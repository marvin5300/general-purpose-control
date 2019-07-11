/****************************************************************************
** Meta object code from reading C++ file 'measurement_device.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../measurement_device.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'measurement_device.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Measurement_Device_t {
    QByteArrayData data[15];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Measurement_Device_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Measurement_Device_t qt_meta_stringdata_Measurement_Device = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Measurement_Device"
QT_MOC_LITERAL(1, 19, 11), // "scpiCommand"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 7), // "command"
QT_MOC_LITERAL(4, 40, 15), // "disconnectRS232"
QT_MOC_LITERAL(5, 56, 8), // "portName"
QT_MOC_LITERAL(6, 65, 12), // "connectRS232"
QT_MOC_LITERAL(7, 78, 8), // "baudRate"
QT_MOC_LITERAL(8, 87, 10), // "deviceName"
QT_MOC_LITERAL(9, 98, 17), // "onReceivedMessage"
QT_MOC_LITERAL(10, 116, 7), // "message"
QT_MOC_LITERAL(11, 124, 25), // "onConnectionStatusChanged"
QT_MOC_LITERAL(12, 150, 9), // "connected"
QT_MOC_LITERAL(13, 160, 22), // "onConnectButtonClicked"
QT_MOC_LITERAL(14, 183, 19) // "onSendButtonClicked"

    },
    "Measurement_Device\0scpiCommand\0\0command\0"
    "disconnectRS232\0portName\0connectRS232\0"
    "baudRate\0deviceName\0onReceivedMessage\0"
    "message\0onConnectionStatusChanged\0"
    "connected\0onConnectButtonClicked\0"
    "onSendButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Measurement_Device[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    3,   55,    2, 0x0a /* Public */,
       9,    1,   62,    2, 0x0a /* Public */,
      11,    1,   65,    2, 0x0a /* Public */,
      13,    0,   68,    2, 0x09 /* Protected */,
      14,    0,   69,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::QString,    5,    7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Measurement_Device::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Measurement_Device *_t = static_cast<Measurement_Device *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->scpiCommand((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->disconnectRS232((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->connectRS232((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->onReceivedMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->onConnectionStatusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->onConnectButtonClicked(); break;
        case 6: _t->onSendButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Measurement_Device::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Measurement_Device::scpiCommand)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Measurement_Device::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Measurement_Device::disconnectRS232)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Measurement_Device::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_Measurement_Device.data,
      qt_meta_data_Measurement_Device,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Measurement_Device::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Measurement_Device::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Measurement_Device.stringdata0))
        return static_cast<void*>(this);
    return QGroupBox::qt_metacast(_clname);
}

int Measurement_Device::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Measurement_Device::scpiCommand(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Measurement_Device::disconnectRS232(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
