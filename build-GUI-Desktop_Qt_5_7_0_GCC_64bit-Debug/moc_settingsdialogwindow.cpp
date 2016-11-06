/****************************************************************************
** Meta object code from reading C++ file 'settingsdialogwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/GUI/settingsdialogwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingsdialogwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SettingsDialogWindow_t {
    QByteArrayData data[10];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingsDialogWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingsDialogWindow_t qt_meta_stringdata_SettingsDialogWindow = {
    {
QT_MOC_LITERAL(0, 0, 20), // "SettingsDialogWindow"
QT_MOC_LITERAL(1, 21, 18), // "deviceGroupChanged"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 12), // "newGroupName"
QT_MOC_LITERAL(4, 54, 14), // "DynamicButton*"
QT_MOC_LITERAL(5, 69, 3), // "btn"
QT_MOC_LITERAL(6, 73, 20), // "on_buttonBox_clicked"
QT_MOC_LITERAL(7, 94, 16), // "QAbstractButton*"
QT_MOC_LITERAL(8, 111, 6), // "button"
QT_MOC_LITERAL(9, 118, 28) // "on_statusRadioButton_clicked"

    },
    "SettingsDialogWindow\0deviceGroupChanged\0"
    "\0newGroupName\0DynamicButton*\0btn\0"
    "on_buttonBox_clicked\0QAbstractButton*\0"
    "button\0on_statusRadioButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingsDialogWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   34,    2, 0x08 /* Private */,
       9,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,

       0        // eod
};

void SettingsDialogWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SettingsDialogWindow *_t = static_cast<SettingsDialogWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deviceGroupChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< DynamicButton*(*)>(_a[2]))); break;
        case 1: _t->on_buttonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 2: _t->on_statusRadioButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DynamicButton* >(); break;
            }
            break;
        case 1:
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
            typedef void (SettingsDialogWindow::*_t)(QString , DynamicButton * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SettingsDialogWindow::deviceGroupChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SettingsDialogWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SettingsDialogWindow.data,
      qt_meta_data_SettingsDialogWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SettingsDialogWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingsDialogWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SettingsDialogWindow.stringdata0))
        return static_cast<void*>(const_cast< SettingsDialogWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int SettingsDialogWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SettingsDialogWindow::deviceGroupChanged(QString _t1, DynamicButton * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
