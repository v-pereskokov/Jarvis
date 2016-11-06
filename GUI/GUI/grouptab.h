#ifndef GROUPTAB_H
#define GROUPTAB_H
#include "widgetverticallayout.h"
#include "styles.h"
#include <QPushButton>
#include <QString>



struct GroupTab
{
public:
    GroupTab(QWidget *parent = 0);
    GroupTab(QWidget *parent, const QString &tabName);
    ~GroupTab();

    WidgetVerticalLayout   *layout;
    QPushButton            *tab;
};

#endif // GROUPTAB_H
