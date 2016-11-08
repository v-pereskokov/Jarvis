#ifndef SETTINGSBUTTON_H
#define SETTINGSBUTTON_H

#include <QPushButton>
#include "dynamicbutton.h"
#include "styles.h"

class SettingsButtonBox : public QPushButton
{
    Q_OBJECT
public:
    explicit SettingsButtonBox(QWidget *parent = 0);
    SettingsButtonBox(DynamicButton *button, QWidget *parent = 0);

    DynamicButton *deviceButton;

signals:

public slots:
};

#endif // SETTINGSBUTTON_H
