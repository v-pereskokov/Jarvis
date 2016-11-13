#ifndef WIDGETVERTICALLAYOUT_H
#define WIDGETVERTICALLAYOUT_H

#include <QWidget>
#include <QGridLayout>
#include "settingsbuttonbox.h"

#define deviceButtonColumn   0
#define settingsButtonColumn 1
#define settingsButtonColumnWidth 40

class WidgetGridLayout : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetGridLayout(QWidget *parent = 0);

   ~WidgetGridLayout();
    QLayoutItem *itemAt(int index) const;
    void removeWidget(QWidget *widget);
    void addWidget(QWidget *widget);
    void addLayout(QLayout *layout);
    void addSettingsButtonBox(SettingsButtonBox *settings);
    void hideWidgets();
    void showWidgets();
    int  count() const;


    QGridLayout *vertLayout;
};

#endif // WIDGETVERTICALLAYOUT_H
