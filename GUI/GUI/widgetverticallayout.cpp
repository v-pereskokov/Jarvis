#include "widgetverticallayout.h"

WidgetVerticalLayout::WidgetVerticalLayout(QWidget *parent)
    : QWidget{parent}
{
    vertLayout = new QGridLayout{parent};
    vertLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
    vertLayout->setColumnMinimumWidth(0, 210);
    vertLayout->setColumnMinimumWidth(1, 40);
}

WidgetVerticalLayout::~WidgetVerticalLayout()
{

}

void WidgetVerticalLayout::addWidget(DynamicButton *widget)
{
    vertLayout->addWidget(widget, vertLayout->rowCount(), 0);
}

void WidgetVerticalLayout::addWidgetWithSettingsButton(SettingsButtonBox *settings)
{
    int row = vertLayout->rowCount();
    vertLayout->addWidget(settings->deviceButton, row, 0);
    vertLayout->addWidget(settings, row, 1);
}

void WidgetVerticalLayout::hideWidgets()
{
    for(int i = 0; i < count(); ++i)
        {
            QWidget *widget = vertLayout->itemAt(i)->widget();
            widget->hide();

        }
}

void WidgetVerticalLayout::showWidgets()
{
    for(int i = 0; i < vertLayout->count(); ++i)
        {
            QWidget *widget = vertLayout->itemAt(i)->widget();
            widget->show();

        }
}

int  WidgetVerticalLayout::count() const
{
    return vertLayout->count();
}

QLayoutItem* WidgetVerticalLayout::itemAt(int index) const
{
    return vertLayout->itemAt(index);
}


void WidgetVerticalLayout::removeWidget(QWidget *widget)
{
    vertLayout->removeWidget(widget);
    delete widget;
}
