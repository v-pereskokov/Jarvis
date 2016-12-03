#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent},
    ui{new Ui::MainWindow}
{
    ui->setupUi(this);
    ui->verticalLayoutLeft->setSpacing(10);
    ui->deleteButton->setDisabled(true); 
    ui->scrollAreaWidgetContents->setLayout(ui->verticalLayoutLeft);

    setStyles(stylesList);

    ui->addButton->setStyleSheet(stylesList[3]);
    ui->deleteButton->setStyleSheet(stylesList[3]);
    ui->addGroup->setStyleSheet(stylesList[3]);
    ui->deleteGroup->setStyleSheet(stylesList[3]);

    ui->toolPushButton->setIcon(QIcon{QPixmap{":/images/toolIcon.png"}});
    ui->toolPushButton->setIconSize(QSize{75, 50});

    ui->label->hide();
    ui->lineEdit->hide();
    ui->addButton->hide();
    ui->deleteButton->hide();
    ui->label_2->hide();
    ui->groupNameEdit->hide();
    ui->addGroup->hide();
    ui->deleteGroup->hide();


}

MainWindow::~MainWindow()
{
    delete ui;
}

SettingsButtonBox* MainWindow::createDynamicButton(const QString &buttonName, const QString groupName, QWidget *parent)
{
    DynamicBulbButton *button = new DynamicBulbButton{parent};  // Создаем объект динамической кнопки


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

bool MainWindow::checkName(const QString& name) const
{
    for(size_t i = 0; i < buttonList.size(); ++i)
    {
        SettingsButtonBox *button = buttonList[i];
        if(button->deviceButton->text() == name)
            return false;

    }
    return true;
}

/* Метод для добавления динамической кнопки
 * */
void MainWindow::on_addButton_clicked()
{
    if(ui->lineEdit->text().isEmpty())
    {
        QMessageBox::information(this, QString{"warning"}, QString{"Error. Empty name"});
        return;
    }

    if (checkName(ui->lineEdit->text()))
    {
        ui->deleteButton->setDisabled(false);        

        GroupTab *tab = getGroupTab(ui->groupNameEdit->text(), true, ui->scrollAreaWidgetContents);

        // Создаем объект динамической кнопки
        SettingsButtonBox *settings = createDynamicButton(ui->lineEdit->text(), tab->tab->text(), tab->layout);

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
        connect(settings->deviceButton, SIGNAL(clicked()), this, SLOT(slotOpenDeviceConfig()));
        connect(settings, SIGNAL(clicked()), this, SLOT(slotSettingsButtonCLicked()));
    }
    else
        QMessageBox::information(nullptr, QString{"warning"}, QString{"Error. Name is alredy used"});
}

/* Метод для удаления динамической кнопки по её имени
 * */
void MainWindow::on_deleteButton_clicked()
{
    deleteDynamicButton(ui->lineEdit->text());
}

/* СЛОТ для получения номера кнопки.
 * */
void MainWindow::slotGetButtonName()
{
    /* Определяем объект, который вызвал сигнал
     * */
    DynamicBulbButton *button = (DynamicBulbButton*) sender();
    /* После чего устанавливаем номер кнопки в lineEdit,
     * который содержится в данной динамической кнопке
     * */
    ui->lineEdit->setText(button->text());
    /* То есть номер кнопки устанавливается в поле lineEdit только тогда,
     * когда мы нажимаем одну из динамических кнопок, и этот номер соответствует
     * номеру нажатой кнопки
     * */
}

void MainWindow::on_lineEdit_textChanged(const QString &str)
{
    if(str.isEmpty())
    {
        ui->addButton->setDisabled(true);
        ui->deleteButton->setDisabled(true);        
    }
    else
    {
        ui->addButton->setDisabled(false);
        ui->deleteButton->setDisabled(false);        
    }

}

void MainWindow::slotOpenDeviceConfig()
{
    SmartBulbConfig *configWindow = new SmartBulbConfig{this, (DynamicBulbButton*) sender()};
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
        ui->label->hide();
        ui->lineEdit->hide();
        ui->addButton->hide();
        ui->deleteButton->hide();
        ui->label_2->hide();
        ui->groupNameEdit->hide();
        ui->addGroup->hide();
        ui->deleteGroup->hide();
    }
    else
    {
        ui->label->show();
        ui->lineEdit->show();
        ui->addButton->show();
        ui->deleteButton->show();
        ui->label_2->show();
        ui->groupNameEdit->show();
        ui->addGroup->show();
        ui->deleteGroup->show();
    }
}
