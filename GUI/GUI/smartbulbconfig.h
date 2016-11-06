#ifndef SMARTBULBCONFIG_H
#define SMARTBULBCONFIG_H

#include <QDialog>
#include <QPixmap>
#include "dynamicbutton.h"
#include "styles.h"

namespace Ui {
class SmartBulbConfig;
}

class SmartBulbConfig : public QDialog
{
    Q_OBJECT

public:
    explicit SmartBulbConfig(QWidget *parent = 0);
    SmartBulbConfig(QWidget *parent, DynamicButton *button);
    ~SmartBulbConfig();

private slots:
    void on_brightnessSlider_valueChanged(int value);

    void on_statusCheckBox_clicked();


    void on_bulbImage_clicked();

private:
    Ui::SmartBulbConfig *ui;
    QString stylesList[stylesAmount];
    DynamicButton *deviceButton;
    QPixmap bulbImg;

};

#endif // SMARTBULBCONFIG_H
