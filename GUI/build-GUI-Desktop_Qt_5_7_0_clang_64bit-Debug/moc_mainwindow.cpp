/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[356];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 20), // "on_addButton_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 15), // "deleteButtonBox"
QT_MOC_LITERAL(4, 49, 10), // "deviceName"
QT_MOC_LITERAL(5, 60, 20), // "slotOpenDeviceConfig"
QT_MOC_LITERAL(6, 81, 25), // "slotSettingsButtonCLicked"
QT_MOC_LITERAL(7, 107, 12), // "onTabClicked"
QT_MOC_LITERAL(8, 120, 20), // "changeDeviceGroupTab"
QT_MOC_LITERAL(9, 141, 15), // "newGroupTabName"
QT_MOC_LITERAL(10, 157, 18), // "SettingsButtonBox*"
QT_MOC_LITERAL(11, 176, 3), // "btn"
QT_MOC_LITERAL(12, 180, 19), // "on_addGroup_clicked"
QT_MOC_LITERAL(13, 200, 22), // "on_deleteGroup_clicked"
QT_MOC_LITERAL(14, 223, 9), // "addDevice"
QT_MOC_LITERAL(15, 233, 15), // "deviceBluetooth"
QT_MOC_LITERAL(16, 249, 11), // "std::string"
QT_MOC_LITERAL(17, 261, 10), // "devicePort"
QT_MOC_LITERAL(18, 272, 9), // "groupName"
QT_MOC_LITERAL(19, 282, 25), // "on_toolPushButton_clicked"
QT_MOC_LITERAL(20, 308, 13), // "setButtonIcon"
QT_MOC_LITERAL(21, 322, 5), // "frame"
QT_MOC_LITERAL(22, 328, 27) // "on_microphoneButton_clicked"

    },
    "MainWindow\0on_addButton_clicked\0\0"
    "deleteButtonBox\0deviceName\0"
    "slotOpenDeviceConfig\0slotSettingsButtonCLicked\0"
    "onTabClicked\0changeDeviceGroupTab\0"
    "newGroupTabName\0SettingsButtonBox*\0"
    "btn\0on_addGroup_clicked\0on_deleteGroup_clicked\0"
    "addDevice\0deviceBluetooth\0std::string\0"
    "devicePort\0groupName\0on_toolPushButton_clicked\0"
    "setButtonIcon\0frame\0on_microphoneButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    1,   75,    2, 0x08 /* Private */,
       5,    0,   78,    2, 0x08 /* Private */,
       6,    0,   79,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    2,   81,    2, 0x08 /* Private */,
      12,    0,   86,    2, 0x08 /* Private */,
      13,    0,   87,    2, 0x08 /* Private */,
      14,    4,   88,    2, 0x08 /* Private */,
      19,    0,   97,    2, 0x08 /* Private */,
      20,    1,   98,    2, 0x08 /* Private */,
      22,    0,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 10,    9,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 16, QMetaType::QString, QMetaType::QString,   15,   17,    4,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_addButton_clicked(); break;
        case 1: _t->deleteButtonBox((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slotOpenDeviceConfig(); break;
        case 3: _t->slotSettingsButtonCLicked(); break;
        case 4: _t->onTabClicked(); break;
        case 5: _t->changeDeviceGroupTab((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< SettingsButtonBox*(*)>(_a[2]))); break;
        case 6: _t->on_addGroup_clicked(); break;
        case 7: _t->on_deleteGroup_clicked(); break;
        case 8: _t->addDevice((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 9: _t->on_toolPushButton_clicked(); break;
        case 10: _t->setButtonIcon((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_microphoneButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SettingsButtonBox* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
