#include "smartbulb.h"

SmartBulb::SmartBulb(QWidget *parent)  : SmartDevice(parent)
{
    brightness = 1;
    color = bulbColor::white;

}

SmartBulb::SmartBulb(QWidget *parent, const QString &groupName, const QString &deviceName, int id, int brightness, bulbColor color) :
    SmartDevice(parent, groupName, deviceName, id)
{

    this->brightness = brightness;
    if(brightness <= 0)
        this->brightness = 1;
    if(brightness >= 100)
        this->brightness = 100;
    this->color = color;
    this->uploadDeviceConfig();
}

SmartBulb::~SmartBulb()
{
    //удалить из бд
}

bool SmartBulb::setBrightness(int brightness)
{
    int temp = this->brightness;
    this->brightness = brightness;

    if(brightness <= 0)
        this->brightness = 1;
    if(brightness >= 100)
        this->brightness = 100;

    if(uploadDeviceConfig())
        return true;
    else
    {
        this->brightness = temp;
        QMessageBox::information(nullptr, QString("warning"), QString("Error. Cannot upload bulb config"));
        return false;
    }
}

bool SmartBulb::setBulbColor(bulbColor color)
{
    bulbColor temp = this->color;
    this->color = color;
    if(uploadDeviceConfig())
        return true;
    else
    {
        this->color = temp;
        QMessageBox::information(nullptr, QString("warning"), QString("Error. Cannot upload bulb config"));
        return false;
    }
}

int SmartBulb::getBrightness() const
{
    return brightness;
}

bulbColor SmartBulb::getBulbColor() const
{
    return color;
}

QString SmartBulb::getDeviceType() const
{
    return deviceType;
}

const QString SmartBulb::deviceType = QString("Smart Bulb");
