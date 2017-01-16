#ifndef DYNAMICBUTTON_H
#define DYNAMICBUTTON_H

#include "smartbulb.h"

#define maxButtonAmount 100

class DynamicBulbButton :  public SmartBulb
{
    Q_OBJECT
public:
    DynamicBulbButton(QWidget *parent, const QString &deviceBluetooth, QString &deviceType);
    DynamicBulbButton(DynamicBulbButton *btn, QWidget *parent = 0);
    ~DynamicBulbButton();
    static bool resBusyID[maxButtonAmount];   // массив номеров кнопок, равен true  если кнопка с этим ID создана
    int getID();        // Функция для возврата локального номера кнопки

    QString deviceType;

public slots:

private:
    int buttonID = 0;   // номер кнопки

    int findNewID();

};

#endif // DYNAMICBUTTON_H
