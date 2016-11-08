#include "settingsbuttonbox.h"

SettingsButtonBox::SettingsButtonBox(QWidget *parent) : QPushButton(parent)
{
    setText(QString("..."));
    deviceButton = nullptr;
}

SettingsButtonBox::SettingsButtonBox(DynamicButton *button, QWidget *parent) : QPushButton(parent)
{
    setText(QString("..."));
    deviceButton = button;
}
