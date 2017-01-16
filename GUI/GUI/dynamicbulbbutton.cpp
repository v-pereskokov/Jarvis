#include "dynamicbulbbutton.h"

DynamicBulbButton::DynamicBulbButton(QWidget *parent, const QString &deviceBluetooth,
                                     QString &deviceType) :  SmartBulb{parent, deviceBluetooth}
{

    buttonID = findNewID();   /* Присвоение кнопке номера, по которому булет производиться
                               * дальнейшая работа с кнопок
                               * */
    resBusyID[buttonID] = true; //ID кнпки теперь занят
    this->setDeviceID(buttonID);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->setFlat(true);
    this->deviceType = deviceType;

}

DynamicBulbButton::DynamicBulbButton(DynamicBulbButton *btn, QWidget *parent)
    :  SmartBulb{parent, btn->getDeviceBluetoothName()}
{
    buttonID = findNewID();
    resBusyID[buttonID] = true;
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->setFlat(true);    
    this->setText(btn->text());
    this->setDeviceName(btn->text());
    this->setBrightness(btn->getBrightness());
    this->setBulbColor(btn->getBulbColor());
    this->setDeviceID(buttonID);
    deviceType = btn->deviceType;
    if(btn->getDeviceStatus())
        this->turnOnDevice();
    else
        this->turnOffDevice();


}

DynamicBulbButton::~DynamicBulbButton()
{
    resBusyID[buttonID] = false; //ID кнопки освобожден
}

/* Метод для возврата значения номера кнопки
 * */
int DynamicBulbButton::getID()
{
    return buttonID;
}

int DynamicBulbButton::findNewID()
{
    for(size_t i = 0; i < maxButtonAmount; ++i)
    {
        if(!resBusyID[i])
            return i;
    }
    QMessageBox::information(this, QString("warning"), QString("Error. Cannot create button. Delete some buttons"));
}

/* Инициализация статической переменной класса.
 * */
bool DynamicBulbButton::resBusyID[maxButtonAmount];
