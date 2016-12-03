#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

//#include <QObject>
//#include <QWidget>
#include <QString>
#include <QMessageBox>

class SmartDevice //: public QWidget
{
    //Q_OBJECT
public:
    explicit SmartDevice(/*QWidget *parent = 0*/);
             SmartDevice(/*QWidget *parent,*/ const QString &groupName, const QString &deviceName, int id);
    virtual ~SmartDevice();

    bool            setGroupName(const QString& name);
    virtual bool    setDeviceName(const QString& name);
    bool            setDeviceID(int id);
    bool            turnOnDevice();                 //включить устройство
    bool            turnOffFevice();                //выключить устройство
    bool            getDeviceStatus() const;
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
