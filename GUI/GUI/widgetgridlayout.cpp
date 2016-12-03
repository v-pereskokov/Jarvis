#include "widgetgridlayout.h"

WidgetGridLayout::WidgetGridLayout(QWidget *parent)
    : QWidget{parent}
{
    vertLayout = new QGridLayout{parent};
    vertLayout->setSizeConstraint(QLayout::SetMinimumSize);
    vertLayout->setColumnMinimumWidth(settingsButtonColumn, settingsButtonColumnWidth);
}

WidgetGridLayout::~WidgetGridLayout()
{

}

void WidgetGridLayout::addWidget(QWidget *widget)
{
    vertLayout->addWidget(widget, vertLayout->rowCount(), 0);
}


void WidgetGridLayout::addLayout(QLayout *layout)
{
    vertLayout->addLayout(layout, vertLayout->rowCount(), 0);
}

void WidgetGridLayout::addSettingsButtonBox(SettingsButtonBox *settings)
{
    int row = vertLayout->rowCount();
    vertLayout->addWidget(settings->deviceButton, row, deviceButtonColumn);
    vertLayout->addWidget(settings, row, settingsButtonColumn);
}

void WidgetGridLayout::hideWidgets()
{
    for(int i = 0; i < count(); ++i)
        {
            QWidget *widget = vertLayout->itemAt(i)->widget();
            widget->hide();

        }
}

void WidgetGridLayout::showWidgets()
{
    for(int i = 0; i < vertLayout->count(); ++i)
        {
            QWidget *widget = vertLayout->itemAt(i)->widget();
            widget->show();

        }
}

int  WidgetGridLayout::count() const
{
    return vertLayout->count();
}

QLayoutItem* WidgetGridLayout::itemAt(int index) const
{
    return vertLayout->itemAt(index);
}


void WidgetGridLayout::removeWidget(QWidget *widget)
{
    vertLayout->removeWidget(widget);
    delete widget;
}
