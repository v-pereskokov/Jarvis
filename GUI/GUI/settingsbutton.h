#ifndef SETTINGSBUTTON_H
#define SETTINGSBUTTON_H

#include <QPushButton>
#include "dynamicbutton.h"
#include "styles.h"

class SettingsButton : public QPushButton
{
    Q_OBJECT
public:
    explicit SettingsButton(QWidget *parent = 0);
    SettingsButton(DynamicButton *button, QWidget *parent = 0);

    DynamicButton *deviceButton;

signals:

public slots:
};

#endif // SETTINGSBUTTON_H
