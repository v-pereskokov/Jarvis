#include "grouptab.h"

GroupTab::GroupTab(QWidget *parent)
{
    layout = new WidgetVerticalLayout(parent);
    tab = new QPushButton(parent);
}

GroupTab::GroupTab(QWidget *parent, const QString &tabName)
{
    layout =  new WidgetVerticalLayout(parent);
    tab = new QPushButton(QIcon(QPixmap(":/images/tabOpened")), tabName, parent);
    tab->setCheckable(true);
    tab->setFlat(true);
    tab->setStyleSheet("QPushButton {"
                       "    border: none;"
                       "    text-align: left;"
                       "    background-repeat: none;"
                       "}"
                       "QPushButton:hover {"
                       "    background-color: #56c9ff;"
                       "}" );
}

GroupTab::~GroupTab()
{
    tab->hide();
    delete tab;
    delete layout;
}
