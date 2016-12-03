#ifndef SETTINGSBUTTON_H
#define SETTINGSBUTTON_H

#include <QPushButton>
#include "dynamicbulbbutton.h"
#include "styles.h"

class SettingsButtonBox : public QPushButton
{
    Q_OBJECT
public:
    explicit SettingsButtonBox(QWidget *parent = 0);
    SettingsButtonBox(DynamicBulbButton *button, QWidget *parent = 0);

    DynamicBulbButton *deviceButton;

signals:

public slots:
};

#endif // SETTINGSBUTTON_H
