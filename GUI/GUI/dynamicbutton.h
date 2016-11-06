#ifndef DYNAMICBUTTON_H
#define DYNAMICBUTTON_H

#include "smartbulb.h"

#define maxButtonAmount 100

class DynamicButton :  public SmartBulb
{
    Q_OBJECT
public:
    explicit DynamicButton(QWidget *parent = 0);
    DynamicButton(DynamicButton *btn, QWidget *parent = 0);
    ~DynamicButton();
    static bool resBusyID[maxButtonAmount];   // массив номеров кнопок, равен true  если кнопка с этим ID создана
    int getID();        // Функция для возврата локального номера кнопки


public slots:

private:
    int buttonID = 0;   // Локальная переменная, номер кнопки
    int findNewID();
};

#endif // DYNAMICBUTTON_H
