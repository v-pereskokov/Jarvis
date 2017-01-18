#ifndef SMARTBULBCONFIG_H
#define SMARTBULBCONFIG_H

#include <QDialog>
#include <QPixmap>
#include "dynamicbulbbutton.h"
#include "styles.h"

namespace Ui {
class SmartBulbConfig;
}

class SmartBulbConfig : public QDialog
{
    Q_OBJECT

public:
    explicit SmartBulbConfig(QWidget *parent = 0);
    SmartBulbConfig(QWidget *parent, DynamicBulbButton *button);
    ~SmartBulbConfig();

private slots:
    void on_brightnessSlider_valueChanged(int value);
    void on_statusButton_clicked();
    void on_bulbImage_clicked();
    void on_deleteDeviceButton_clicked();

signals:
    void deleteDevice(QString deviceName);

private:
    Ui::SmartBulbConfig *ui;
    QString stylesList[stylesAmount];
    DynamicBulbButton *deviceButton;
    QPixmap bulbImg;

};

#endif // SMARTBULBCONFIG_H
