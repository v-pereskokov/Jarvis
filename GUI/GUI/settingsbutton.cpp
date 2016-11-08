#include "settingsbutton.h"

SettingsButton::SettingsButton(QWidget *parent) : QPushButton(parent)
{
    setText(QString("..."));
    deviceButton = nullptr;
}

SettingsButton::SettingsButton(DynamicButton *button, QWidget *parent) : QPushButton(parent)
{
    setText(QString("..."));
    deviceButton = button;
}
