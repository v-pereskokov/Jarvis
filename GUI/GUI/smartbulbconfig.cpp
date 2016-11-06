#include "smartbulbconfig.h"
#include "ui_smartbulbconfig.h"

SmartBulbConfig::SmartBulbConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SmartBulbConfig)
{
    ui->setupUi(this);
}

SmartBulbConfig::SmartBulbConfig(QWidget *parent, DynamicButton *button):
    QDialog(parent),
    ui(new Ui::SmartBulbConfig)
{
    ui->setupUi(this);
    deviceButton = button;
    setStyles(stylesList);
    ui->buttonBox->setStyleSheet(stylesList[1]);

    ui->brightnessSlider->setValue(deviceButton->getBrightness());
    ui->lcdNumber->display(QString::number(deviceButton->getBrightness()));
    ui->bulbName->setText(deviceButton->getDeviceName());


    if(deviceButton->getDeviceStatus())
    {
       ui->statusLabel->setText(QString("ON"));
       ui->statusCheckBox->setChecked(true);

       bulbImg.load( ":/images/bulbOn.png" );
    }
    else
    {
        ui->statusLabel->setText(QString("OFF"));
        ui->statusCheckBox->setChecked(false);
        bulbImg.load( ":/images/bulbOff.png" );
    }

    ui->bulbImage->setIcon(QIcon(bulbImg));
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



void SmartBulbConfig::on_statusCheckBox_clicked()
{

    if(ui->statusCheckBox->isChecked())
    {
        ui->statusLabel->setText(QString("ON"));
        deviceButton->turnOnDevice();
        bulbImg.load( ":/images/bulbOn.png" );
    }
    else
    {
        ui->statusLabel->setText(QString("OFF"));
        deviceButton->turnOffDevice();
        bulbImg.load( ":/images/bulbOff.png" );
    }
    ui->bulbImage->setIcon(QIcon(bulbImg));
}



void SmartBulbConfig::on_bulbImage_clicked()
{
    ui->statusCheckBox->setChecked(!ui->statusCheckBox->isChecked());
    emit(on_statusCheckBox_clicked());
}
