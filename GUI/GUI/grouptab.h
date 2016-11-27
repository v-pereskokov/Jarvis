#ifndef GROUPTAB_H
#define GROUPTAB_H
#include "widgetverticallayout.h"
#include "styles.h"
#include <QPushButton>
#include <QString>


//Структура для боковых вкладок
struct GroupTab
{
public:
    GroupTab(QWidget *parent = 0);
    GroupTab(QWidget *parent, const QString &tabName);
    ~GroupTab();

    WidgetVerticalLayout   *layout;  //Слой вкладки в который добавляются кнопки с устройствами
    QPushButton            *tab;     //Кнопка вкладки, позволяет свернуть вкладку по клику
};

#endif // GROUPTAB_H
