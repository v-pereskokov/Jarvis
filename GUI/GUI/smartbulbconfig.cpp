#include "smartbulbconfig.h"
#include "ui_smartbulbconfig.h"

SmartBulbConfig::SmartBulbConfig(QWidget *parent) :
    QDialog{parent},
    ui{new Ui::SmartBulbConfig}
{
    ui->setupUi(this);
}

SmartBulbConfig::SmartBulbConfig(QWidget *parent, DynamicBulbButton *button):
    QDialog{parent},
    ui{new Ui::SmartBulbConfig}
{
    ui->setupUi(this);
    deviceButton = button;
    setStyles(stylesList);
    ui->buttonBox->setStyleSheet(stylesList[1]);

    ui->brightnessSlider->setValue(deviceButton->getBrightness());
    ui->lcdNumber->display(QString::number(deviceButton->getBrightness()));
    ui->bulbName->setText(deviceButton->getDeviceName());

    ui->statusButton->setCheckable(true);
    ui->statusButton->setFlat(true);

    if(deviceButton->getDeviceStatus())
    {
       ui->statusLabel->setText(QString{"ON"});
       ui->statusButton->setChecked(true);
       ui->statusButton->setIcon(QIcon{QPixmap{":/images/powerOn.png"}});
       bulbImg.load( ":/images/bulbOn.png" );
    }
    else
    {
        ui->statusLabel->setText(QString{"OFF"});
        ui->statusButton->setChecked(false);
        ui->statusButton->setIcon(QIcon{QPixmap{":/images/powerOff.png"}});
        bulbImg.load( ":/images/bulbOff.png" );
    }

    ui->bulbImage->setIcon(QIcon{bulbImg});
    ui->bulbImage->setIconSize(ui->bulbImage->size());
}

SmartBulbConfig::~SmartBulbConfig()
{
    delete ui;
}

void SmartBulbConfig::on_brightnessSlider_valueChanged(int value)
{

    ui->lcdNumber->display(QString::number(value));
    deviceButton->setBrightness(value);
}



void SmartBulbConfig::on_statusButton_clicked()
{

    if(ui->statusButton->isChecked())
    {
        ui->statusLabel->setText(QString{"ON"});
        deviceButton->turnOnDevice();
        bulbImg.load( ":/images/bulbOn.png" );
        ui->statusButton->setIcon(QIcon{QPixmap{":/images/powerOn.png"}});
        deviceButton->setIcon(QIcon{QPixmap{":/images/bulbOnIcon.png"}});
    }
    else
    {
        ui->statusLabel->setText(QString{"OFF"});
        deviceButton->turnOffDevice();
        ui->statusButton->setIcon(QIcon{QPixmap{":/images/powerOff.png"}});
        deviceButton->setIcon(QIcon{QPixmap{":/images/bulbOffIcon.png"}});
        bulbImg.load( ":/images/bulbOff.png" );
    }
    ui->bulbImage->setIcon(QIcon{bulbImg});
    deviceButton->setIconSize(QSize{25, 25});
}



void SmartBulbConfig::on_bulbImage_clicked()
{
    ui->statusButton->setChecked(!ui->statusButton->isChecked());
    emit(on_statusButton_clicked());
}

void SmartBulbConfig::on_deleteDeviceButton_clicked()
{

    QMessageBox msgBox;
    //заголовок
    msgBox.setWindowTitle(QString{"Delete Device"});
    msgBox.setText(QString{"Warning"});
    msgBox.setIcon(QMessageBox::Information);
    // Основное сообщение Message Box
    msgBox.setInformativeText(QString{"Smart Device "}
                              + deviceButton->text()
                              + QString{" will be REMOVED!!! \n\n Do you want to continue?"} );
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
    emit(deleteDevice(deviceButton->text()));
    this->close();
}
