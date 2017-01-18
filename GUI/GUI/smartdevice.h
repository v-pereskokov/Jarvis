#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <QPushButton>
#include <QString>
#include <QMessageBox>
#include "../../SmartHome/include/Devices/Devices.hpp"
#include "../../SmartHome/include/SerialPort.hpp"
#include "../../SmartHome/include/BluetoothHC05.hpp"

class SmartDevice : public QPushButton
{
    Q_OBJECT
public:
     SmartDevice(QWidget *parent, const QString deviceBluetooth);
     SmartDevice(QWidget *parent, const QString &deviceBluetooth,
                 const QString &groupName, const QString &deviceName, int id);
    virtual ~SmartDevice();

    bool            setGroupName(const QString& name);
    virtual bool    setDeviceName(const QString& name);
    virtual QString    getDeviceBluetoothName() const;
    bool            setDeviceID(int id);
    bool            turnOnDevice();                 //включить устройство
    bool            turnOffDevice();                //выключить устройство
    bool            getDeviceStatus() const;       // равно true если устройство включено
    QString         getGroupName() const;
    QString         getDeviceName() const;
    int             getDeviceID() const;
    void            startFabric(std::string devicePort);


protected:
    QString                                   groupName;
    QString                                   deviceName;
    QString                                   deviceBluetoothName; // уникальное Bluetooth имя устройства
    int                                       deviceID;
    bool                                      deviceStatus;  //вкл/выкл
    Jarvis::Devices::DeviceFactory           *factory;
    std::unique_ptr<Jarvis::Devices::Device>  device;

    virtual bool        updateDeviceConfig();  //написать (нужен сервер)
    virtual bool        uploadDeviceConfig();  //написать (нужен сервер)


//signals:

//public slots:
};

#endif // SMARTDEVICE_H
