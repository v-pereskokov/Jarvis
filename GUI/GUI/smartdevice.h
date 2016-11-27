#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <QPushButton>
#include <QString>
#include <QMessageBox>

class SmartDevice : public QPushButton
{
    Q_OBJECT
public:
     SmartDevice(QWidget *parent);
     SmartDevice(QWidget *parent, const QString &groupName, const QString &deviceName, int id);
    virtual ~SmartDevice();

    bool            setGroupName(const QString& name);
    virtual bool    setDeviceName(const QString& name);
    bool            setDeviceID(int id);
    bool            turnOnDevice();                 //включить устройство
    bool            turnOffDevice();                //выключить устройство
    bool            getDeviceStatus() const;       // равно true если устройство включено
    QString         getGroupName() const;
    QString         getDeviceName() const;
    int             getDeviceID() const;


protected:
    QString                  groupName;
    QString                  deviceName;
    int                      deviceID;
    bool                     deviceStatus;  //вкл/выкл


    virtual bool        updateDeviceConfig();  //написать
    virtual bool        uploadDeviceConfig();  //написать


//signals:

//public slots:
};

#endif // SMARTDEVICE_H
