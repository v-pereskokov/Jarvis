#include "settingsbuttonbox.h"

SettingsButtonBox::SettingsButtonBox(QWidget *parent) : QPushButton(parent)
{
    setText(QString("..."));
    deviceButton = nullptr;
}

SettingsButtonBox::SettingsButtonBox(DynamicButton *button, QWidget *parent) : QPushButton(parent)
{    
    deviceButton = button;
    this->setStyleSheet("QPushButton {"
                        "    border: none;"
                        "    text-align: left;"
                        "    background-repeat: none; "
                        "    max-width: 30px; "
                        "    max-height: 30px;"
                        "}"
                        "QPushButton:hover {"
                        "    background-color: #004A49;"
                        "}" );
    this->setIcon(QIcon(QPixmap(":/images/settings.png")));
    this->setIconSize(QSize(30, 30));
}
