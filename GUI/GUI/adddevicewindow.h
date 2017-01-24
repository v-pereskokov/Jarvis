#ifndef ADDDEVICEWINDOW_H
#define ADDDEVICEWINDOW_H

#include <QDialog>
#include <vector>
#include "settingsbuttonbox.h"
#include "grouptab.h"
#include "styles.h"


namespace Ui {
class AddDeviceWindow;
}

class AddDeviceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddDeviceWindow(QWidget *parent = 0);
    AddDeviceWindow(QWidget *parent, std::vector<SettingsButtonBox *> &btnList,
                    std::vector<std::pair<std::string, std::string>> avaliableDevices);
    ~AddDeviceWindow();
    bool checkName(const QString& name) const;
    bool checkBluetoothName(const QString& name) const;

private slots:
    void  getButtonName();
    void  on_buttonBox_clicked(QAbstractButton *button);

signals:
    void  newDevice(QString device, std::string devicePort, QString deviceName, QString GroupName);

private:
    Ui::AddDeviceWindow *ui;
    std::vector<SettingsButtonBox*>    buttonList;
    std::vector<std::pair<std::string, std::string>> avaliableDevices;
};

#endif // ADDDEVICEWINDOW_H
