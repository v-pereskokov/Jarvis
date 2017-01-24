/****************************************************************************
** Meta object code from reading C++ file 'adddevicewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/adddevicewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adddevicewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddDeviceWindow_t {
    QByteArrayData data[13];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddDeviceWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddDeviceWindow_t qt_meta_stringdata_AddDeviceWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "AddDeviceWindow"
QT_MOC_LITERAL(1, 16, 9), // "newDevice"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 6), // "device"
QT_MOC_LITERAL(4, 34, 11), // "std::string"
QT_MOC_LITERAL(5, 46, 10), // "devicePort"
QT_MOC_LITERAL(6, 57, 10), // "deviceName"
QT_MOC_LITERAL(7, 68, 9), // "GroupName"
QT_MOC_LITERAL(8, 78, 13), // "getButtonName"
QT_MOC_LITERAL(9, 92, 20), // "on_buttonBox_clicked"
QT_MOC_LITERAL(10, 113, 16), // "QAbstractButton*"
QT_MOC_LITERAL(11, 130, 6), // "button"
QT_MOC_LITERAL(12, 137, 8) // "changeUI"

    },
    "AddDeviceWindow\0newDevice\0\0device\0"
    "std::string\0devicePort\0deviceName\0"
    "GroupName\0getButtonName\0on_buttonBox_clicked\0"
    "QAbstractButton*\0button\0changeUI"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddDeviceWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   43,    2, 0x08 /* Private */,
       9,    1,   44,    2, 0x08 /* Private */,
      12,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, QMetaType::QString, QMetaType::QString,    3,    5,    6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,

       0        // eod
};

void AddDeviceWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddDeviceWindow *_t = static_cast<AddDeviceWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newDevice((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->getButtonName(); break;
        case 2: _t->on_buttonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 3: _t->changeUI(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AddDeviceWindow::*_t)(QString , std::string , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddDeviceWindow::newDevice)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject AddDeviceWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddDeviceWindow.data,
      qt_meta_data_AddDeviceWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AddDeviceWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddDeviceWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AddDeviceWindow.stringdata0))
        return static_cast<void*>(const_cast< AddDeviceWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddDeviceWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AddDeviceWindow::newDevice(QString _t1, std::string _t2, QString _t3, QString _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
