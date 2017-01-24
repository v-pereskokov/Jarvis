/****************************************************************************
** Meta object code from reading C++ file 'smartbulbconfig.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/smartbulbconfig.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'smartbulbconfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SmartBulbConfig_t {
    QByteArrayData data[9];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SmartBulbConfig_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SmartBulbConfig_t qt_meta_stringdata_SmartBulbConfig = {
    {
QT_MOC_LITERAL(0, 0, 15), // "SmartBulbConfig"
QT_MOC_LITERAL(1, 16, 12), // "deleteDevice"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 10), // "deviceName"
QT_MOC_LITERAL(4, 41, 32), // "on_brightnessSlider_valueChanged"
QT_MOC_LITERAL(5, 74, 5), // "value"
QT_MOC_LITERAL(6, 80, 23), // "on_statusButton_clicked"
QT_MOC_LITERAL(7, 104, 20), // "on_bulbImage_clicked"
QT_MOC_LITERAL(8, 125, 29) // "on_deleteDeviceButton_clicked"

    },
    "SmartBulbConfig\0deleteDevice\0\0deviceName\0"
    "on_brightnessSlider_valueChanged\0value\0"
    "on_statusButton_clicked\0on_bulbImage_clicked\0"
    "on_deleteDeviceButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SmartBulbConfig[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   42,    2, 0x08 /* Private */,
       6,    0,   45,    2, 0x08 /* Private */,
       7,    0,   46,    2, 0x08 /* Private */,
       8,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SmartBulbConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SmartBulbConfig *_t = static_cast<SmartBulbConfig *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deleteDevice((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_brightnessSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_statusButton_clicked(); break;
        case 3: _t->on_bulbImage_clicked(); break;
        case 4: _t->on_deleteDeviceButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SmartBulbConfig::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SmartBulbConfig::deleteDevice)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SmartBulbConfig::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SmartBulbConfig.data,
      qt_meta_data_SmartBulbConfig,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SmartBulbConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SmartBulbConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SmartBulbConfig.stringdata0))
        return static_cast<void*>(const_cast< SmartBulbConfig*>(this));
    return QDialog::qt_metacast(_clname);
}

int SmartBulbConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SmartBulbConfig::deleteDevice(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
