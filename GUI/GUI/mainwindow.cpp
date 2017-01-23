#include "mainwindow.h"
#include "adddevicewindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent},
    ui{new Ui::MainWindow}, _factory(new Jarvis::Devices::DeviceFactory)
{
    ui->setupUi(this);
    ui->verticalLayoutLeft->setSpacing(10);
    ui->scrollAreaWidgetContents->setLayout(ui->verticalLayoutLeft);

    setStyles(stylesList);

    ui->addButton->setStyleSheet(stylesList[3]);
    ui->addGroup->setStyleSheet(stylesList[3]);
    ui->deleteGroup->setStyleSheet(stylesList[3]);

    ui->toolPushButton->setIcon(QIcon{QPixmap{":/images/toolIcon.png"}});
    ui->toolPushButton->setIconSize(QSize{75, 50});

    ui->addButton->hide();
    ui->label_2->hide();
    ui->groupNameEdit->hide();
    ui->addGroup->hide();
    ui->deleteGroup->hide();


    microphoneMovie = new QMovie(":/images/microphone.gif"); // Утечка?
    connect(microphoneMovie ,SIGNAL(frameChanged(int)),this,SLOT(setButtonIcon(int)));

    if (microphoneMovie->loopCount() != -1)
        connect(microphoneMovie, SIGNAL(finished()), microphoneMovie, SLOT(stop()));
}



MainWindow::~MainWindow()
{
    delete ui;    
    delete _factory;
}

void MainWindow::setButtonIcon(int frame)
{
    ui->microphoneButton->setIcon(QIcon(microphoneMovie->currentPixmap()));
}

SettingsButtonBox* MainWindow::createDynamicButton(const QString deviceBluetooth, const QString &buttonName,
                                                   const QString groupName, QWidget *parent)
{
    QString type = getDeviceTypeFromBluetoothName(deviceBluetooth);
    DynamicBulbButton *button = new DynamicBulbButton{parent, deviceBluetooth, type};  // Создаем объект динамической кнопки

    button->setStyleSheet(stylesList[0]);
    button->setText(buttonName);
    button->setDeviceName(buttonName);
    button->setGroupName(groupName);
    button->setIcon(QIcon(QPixmap(":/images/bulbOffIcon.png")));
    button->setIconSize(QSize(25, 25));

    SettingsButtonBox *settings = new SettingsButtonBox{button, parent};
    buttonList.push_back(settings);

    return settings;
}


QString MainWindow::getDeviceTypeFromBluetoothName(QString deviceBluetooth) //TODO need fix
{

    return QString("Bulb");
}

void MainWindow::deleteDynamicButton(const QString &buttonName)
{
    for(size_t i = 0; i < buttonList.size(); ++i)
    {
        SettingsButtonBox *button = buttonList[i];

        if(button->deviceButton->text() == buttonName)
        {
            GroupTab *tab = getGroupTab(button->deviceButton->getGroupName(), false);


            for(size_t j = i; j < buttonList.size() - 1; ++j)
                buttonList[j] = buttonList[j + 1];           //сдвигаем список кнопок
            buttonList.pop_back();                           //удаляем последний элемент из списка


            button->hide();
            button->deviceButton->hide();
            tab->layout->removeWidget(button->deviceButton);
            tab->layout->removeWidget(button);
            break;
        }
    }
}

void MainWindow::changeDeviceGroupTab(QString newGroupTabName, SettingsButtonBox *btn)
{
    GroupTab *tab = getGroupTab(newGroupTabName, true, ui->scrollAreaWidgetContents);

    DynamicBulbButton *newButton = new DynamicBulbButton{btn->deviceButton, tab->layout};
    SettingsButtonBox *newSettingsButton = new SettingsButtonBox{newButton, tab->layout};

    newButton->setStyleSheet(stylesList[0]);
    newButton->setGroupName(tab->tab->text());

    if(newButton->getDeviceStatus())
        newButton->setIcon(QIcon{QPixmap{":/images/bulbOnIcon.png"}});
    else
        newButton->setIcon(QIcon{QPixmap{":/images/bulbOffIcon.png"}});

    newButton->setIconSize(QSize{25, 25});

    deleteDynamicButton(btn->deviceButton->text());

    buttonList.push_back(newSettingsButton);
    tab->layout->addSettingsButtonBox(newSettingsButton);
    newButton->show();
    newSettingsButton->show();

    connect(newButton, SIGNAL(clicked()), this, SLOT(slotGetButtonName()));
    connect(newButton, SIGNAL(clicked()), this, SLOT(slotOpenDeviceConfig()));
    connect(newSettingsButton, SIGNAL(clicked()), this, SLOT(slotSettingsButtonCLicked()));

}

GroupTab* MainWindow::getGroupTab(QString tabName,bool createIfNotExist, QWidget *parent)
{
    GroupTab *tab = nullptr;
    if(tabName.isEmpty())
        tabName = QString{"Main Group"};
    for(size_t i = 0; i < groupList.size(); ++i)
    {
        tab = groupList[i];
        if(tab->tab->text() == tabName)
            return tab;
    }
    if(createIfNotExist)
        return createGroupTab(tabName, parent);
    else
        return nullptr;
}

GroupTab* MainWindow::createGroupTab(QString tabName, QWidget *parent)
{

    if(tabName.isEmpty())
        tabName = QString{"Main Group"};

    GroupTab *tab = new GroupTab{parent, tabName};
    groupList.push_back(tab);
    ui->verticalLayoutLeft->addWidget(tab->tab);
    ui->verticalLayoutLeft->addLayout(tab->layout->vertLayout);

    tab->tab->show();

    connect(tab->tab, SIGNAL(clicked()), this, SLOT(onTabClicked()));
    return tab;
}



void MainWindow::on_addButton_clicked()
{
    // Список доступных устройств (имя)
    Jarvis::Connection::Bluetooth::BluetoothHC05 BTModule("/dev/cu.usbmodem14331"); // Порт потом укажу нужный
    BTModule.connect();
    auto avaliableDevices = BTModule.getListOfDevicePortName();
    BTModule.disconnect();

    AddDeviceWindow *addDeviceWindow = new AddDeviceWindow{this, buttonList, avaliableDevices};
    connect(addDeviceWindow, SIGNAL(newDevice(QString, std::string, QString , QString)),
            this, SLOT(addDevice(QString, std::string, QString , QString)));
    addDeviceWindow->show(); //вызов диалогового окна добавления устройства

}

void MainWindow::addDevice(QString deviceBluetooth, std::string devicePort, QString deviceName, QString groupName)
{
    GroupTab *tab = getGroupTab(groupName, true, ui->scrollAreaWidgetContents);

    // Создаем объект динамической кнопки
    SettingsButtonBox *settings = createDynamicButton(deviceBluetooth, deviceName, tab->tab->text(), tab->layout);
    settings->deviceButton->startFabric(devicePort);
    //Добавляем кнопку в слой
    tab->layout->addSettingsButtonBox(settings);
    if(tab->tab->isChecked())
    {
        settings->deviceButton->hide();
        settings->hide();
    }
    else
    {
        settings->deviceButton->show();
        settings->show();
    }

    // Подключаем сигнал нажатия кнопки к слотам
    connect(settings->deviceButton, SIGNAL(clicked()), this, SLOT(slotGetButtonName()));
    if(settings->deviceButton->deviceType == "Bulb")
        connect(settings->deviceButton, SIGNAL(clicked()), this, SLOT(slotOpenDeviceConfig()));
    connect(settings, SIGNAL(clicked()), this, SLOT(slotSettingsButtonCLicked()));

}


void MainWindow::deleteButtonBox(QString deviceName)
{
    deleteDynamicButton(deviceName);
}

void MainWindow::slotOpenDeviceConfig()
{
    SmartBulbConfig *configWindow = new SmartBulbConfig{this, (DynamicBulbButton*) sender()};
    connect(configWindow, SIGNAL(deleteDevice(QString)), this, SLOT(deleteButtonBox(QString)));
    configWindow->show(); //вызов диалогового окна настроек

}

void MainWindow::slotSettingsButtonCLicked()
{
    SettingsButtonBox *button = (SettingsButtonBox*) sender();

    SettingsDialogWindow *settingsWindow = new SettingsDialogWindow{this, button, &buttonList, groupList};
    connect(settingsWindow, SIGNAL(deviceGroupChanged(QString , SettingsButtonBox *)),
            this, SLOT(changeDeviceGroupTab(QString , SettingsButtonBox *)));
    settingsWindow->show(); //вызов диалогового окна настроек
}

void MainWindow::onTabClicked()
{
    QPushButton *tab = (QPushButton*)sender();
    GroupTab *groupTab = getGroupTab(tab->text(), false);
    ui->groupNameEdit->setText(groupTab->tab->text());

    if(tab->isChecked())
    {
        tab->setIcon(QIcon{QPixmap{":/images/tabClosed"}});
        groupTab->layout->hideWidgets();
        groupTab->layout->hide();

    }
    else
    {
        tab->setIcon(QIcon{QPixmap{":/images/tabOpened"}});
        groupTab->layout->showWidgets();
    }
}

void MainWindow::on_addGroup_clicked()
{
    QString tabName = ui->groupNameEdit->text();
    getGroupTab(tabName, true, ui->scrollAreaWidgetContents); //возвращает указатель на вкладку, если ее нет, то создает ее
}



void MainWindow::on_deleteGroup_clicked()
{
    QString tabName = ui->groupNameEdit->text();

    if(tabName.isEmpty())
        return;
    GroupTab *tab = getGroupTab(tabName, false);

    if(tab == nullptr)
        return;

    QMessageBox msgBox;
    //заголовок
    msgBox.setWindowTitle(QString{"Delete Group"});
    msgBox.setText(QString{"Warning"});
    msgBox.setIcon(QMessageBox::Information);
    // Основное сообщение Message Box
    msgBox.setInformativeText(QString{"All Smart Devices in the group \""}
                              + tabName
                              + QString{"\" will be REMOVED!!! \n\n Do you want to continue?"} );
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);

    int ret = msgBox.exec();

    switch (ret)
    {
    case QMessageBox::Cancel:
        return;
    case QMessageBox::Ok:
        break;
    default:
        return;
    }
    while( tab->layout->count() > 0 )
    {
        DynamicBulbButton *button = qobject_cast<DynamicBulbButton*>(tab->layout->vertLayout->itemAt(0)->widget());
        deleteDynamicButton(button->text());
    }

    for(size_t i = 0; i < groupList.size()-1; ++i)
    {
        if(tab == groupList[i])
            std::swap(groupList[i], groupList[i + 1]);
    }
    groupList.pop_back();
    delete tab;
}

void MainWindow::on_toolPushButton_clicked()
{
    if(ui->toolPushButton->isChecked())
    {
        ui->addButton->hide();
        ui->label_2->hide();
        ui->groupNameEdit->hide();
        ui->addGroup->hide();
        ui->deleteGroup->hide();
    }
    else
    {
        ui->addButton->show();
        ui->label_2->show();
        ui->groupNameEdit->show();
        ui->addGroup->show();
        ui->deleteGroup->show();
    }
}

void MainWindow::on_microphoneButton_clicked()
{
    std::string deviceName, command;
    std::thread thr(voiceProcessing, std::ref(deviceName), std::ref(command));
    thr.detach();
    microphoneMovie->start();

    DynamicBulbButton *device = findDevice(QString::fromUtf8(deviceName.c_str()));

    if(command.compare(0,2,"on") == 0 && device)
        device->turnOnDevice();
    if (command.compare(0,3,"off")== 0 && device)
        device->turnOffDevice();
    if (command.compare(0,3,"add") == 0)
        emit(on_addButton_clicked());

}

void voiceProcessing(std::string &deviceName, std::string &command)
{
    std::string cmd = Jarvis::Jarvis::getStringVoice();
    command = parseCommand(cmd);
    if (cmd.find("лампу") != std::string::npos || cmd.find("свет") != std::string::npos)
        deviceName = "Bulb";
    else if (cmd.find("чайник") != std::string::npos)
        deviceName = "Kettle";
    return;
    // TODO:
    //
    // включить микрофон
    // получить команду
    // 1) для выключения вызвать функцию
    //    device = buttonList[n]; // n найти перебором спика по имени лампочки которое ввел пользователь (deviceName)
    //    device->deviceButton->turnOffDevice;
    // 2) для включения вызвать функцию
    //    device = buttonList[n]; // n найти перебором спика по имени лампочки которое ввел пользователь (deviceName)
    //    device->deviceButton->turnOnDevice;
    // 3) для добавления устройства вызвать
    //    emit(on_addButton_clicked());

}
DynamicBulbButton* MainWindow::findDevice(QString deviceName)
{
    for(size_t i = 0; i < buttonList.size(); ++i)
    {
        SettingsButtonBox *button = buttonList[i];
        if((button->deviceButton->getDeviceName() == deviceName))
        {
            return button->deviceButton;
        }
    }
    return nullptr;
}

std::string parseCommand(std::string &command)
{
    std::map<std::string, std::string> commands{{"включи", "on"}, {"выключи", "off"},
                                                {"включить", "on"}, {"выключить", "off"},
                                                {"погаси", "off"}, {"вскипяти", "on"},
                                                {"успокойся", "goodbye"}, {"добавь", "add"},
                                                {"добавить","add"}};
    auto findCmd = commands.begin();
    for (auto it = findCmd; it != commands.end(); ++it) {
        auto pos = command.find(it->first);
        if (pos != std::string::npos) {
            findCmd = it;
            break;
        }
    }

    return findCmd->second;
}
