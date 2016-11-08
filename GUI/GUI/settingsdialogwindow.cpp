#include "settingsdialogwindow.h"
#include "ui_settingsdialogwindow.h"

SettingsDialogWindow::SettingsDialogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialogWindow)
{
    ui->setupUi(this);  
}


SettingsDialogWindow::SettingsDialogWindow(QWidget *parent, SettingsButtonBox *btn,
                                           std::vector<SettingsButtonBox *> *btnList,
                                           std::vector<GroupTab *> &grpList)  : SettingsDialogWindow(parent)

{

    deviceButton = btn->deviceButton;
    deviceSettingsButton = btn;
    buttonList = btnList;
    groupList = grpList;

    ui->idLabel->setText(QString::number(deviceButton->getID()));
    ui->deviceTypelabel->setText(deviceButton->getDeviceType());
    ui->nameEdit->setText(deviceButton->getDeviceName());
    ui->GroupNameEdit->setText(deviceButton->getGroupName());

    setStyles(stylesList);
    ui->buttonBox->setStyleSheet(stylesList[1]);

    ui->statusButton->setCheckable(true);
    ui->statusButton->setFlat(true);



    if(deviceButton->getDeviceStatus())
    {
        ui->statusLabel->setText(QString("ON"));
        ui->statusButton->setChecked(true);
        ui->statusButton->setIcon(QIcon(QPixmap(":/images/powerOn.png")));
    }
    else
    {
        ui->statusLabel->setText(QString("OFF"));
        ui->statusButton->setChecked(false);
        ui->statusButton->setIcon(QIcon(QPixmap(":/images/powerOff.png")));
    }
    connect(ui->statusButton, SIGNAL(clicked()), this, SLOT(onStatusButtonClicked()));

}


SettingsDialogWindow::~SettingsDialogWindow()
{
    delete ui;
}



void SettingsDialogWindow::on_buttonBox_clicked(QAbstractButton *button)
{

    if(ui->buttonBox->standardButton(button) == QDialogButtonBox::Apply)

    {
        if(!ui->nameEdit->text().isEmpty())
        {
            for(size_t i = 0; i < buttonList->size(); ++i)
            {
                SettingsButtonBox *button = (*buttonList)[i];
                if((button->deviceButton->getDeviceName() == ui->nameEdit->text())
                        && (button->deviceButton != deviceButton))
                {
                    QMessageBox::information(nullptr, QString("Warning"), QString("Name is already used"));
                    return;
                }
            }
            deviceButton->setDeviceName(ui->nameEdit->text());
            deviceButton->setText(ui->nameEdit->text());
        }
        else
            QMessageBox::information(nullptr, QString("warning"), QString("Error. Empty device name"));


        if(ui->statusButton->isChecked())
            deviceButton->turnOnDevice();
        else
            deviceButton->turnOffDevice();
        if(deviceButton->getGroupName() != ui->GroupNameEdit->text())
        {
            emit deviceGroupChanged(ui->GroupNameEdit->text(), deviceSettingsButton);
            for(size_t i = 0; i < buttonList->size(); ++i)
            {
                SettingsButtonBox *button = (*buttonList)[i];
                if(button->deviceButton->getDeviceName() == ui->nameEdit->text())
                {
                    deviceButton = button->deviceButton;  //обновление указателя после смены группы
                    deviceSettingsButton = button;
                    break;
                }

            }
        }
    }
}







void SettingsDialogWindow::onStatusButtonClicked()
{
    if(ui->statusButton->isChecked())
    {
        ui->statusLabel->setText(QString("ON"));
        ui->statusButton->setIcon(QIcon(QPixmap(":/images/powerOn.png")));
    }
    else
    {
        ui->statusLabel->setText(QString("OFF"));
        ui->statusButton->setIcon(QIcon(QPixmap(":/images/powerOff.png")));
    }
}
