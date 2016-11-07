#include "dynamicbutton.h"

DynamicButton::DynamicButton(QWidget *parent) :  SmartBulb(parent)
{

    buttonID = findNewID();   /* Присвоение кнопке номера, по которому булет производиться
                               * дальнейшая работа с кнопок
                               * */
    resBusyID[buttonID] = true; //ID кнпки теперь занят
    this->setDeviceID(buttonID);
    this->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
    this->setFlat(true);
    this->setMaximumWidth(200);
}

DynamicButton::DynamicButton(DynamicButton *btn, QWidget *parent) :  SmartBulb(parent)
{
    buttonID = findNewID();
    resBusyID[buttonID] = true;
    this->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
    this->setFlat(true);
    this->setMaximumWidth(200);
    this->setText(btn->text());
    this->setDeviceName(btn->text());
    this->setBrightness(btn->getBrightness());
    this->setBulbColor(btn->getBulbColor());
    this->setDeviceID(buttonID);
    if(btn->getDeviceStatus())
        this->turnOnDevice();
    else
        this->turnOffDevice();


}

DynamicButton::~DynamicButton()
{
    resBusyID[buttonID] = false; //ID кнопки освобожден
}

/* Метод для возврата значения номера кнопки
 * */
int DynamicButton::getID()
{
    return buttonID;
}

int DynamicButton::findNewID()
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
bool DynamicButton::resBusyID[maxButtonAmount];
