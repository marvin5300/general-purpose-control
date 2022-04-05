/****************************************************************************
** Meta object code from reading C++ file 'scpidevice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../include/devices/scpidevice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scpidevice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ScpiDevice_t {
    QByteArrayData data[13];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScpiDevice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScpiDevice_t qt_meta_stringdata_ScpiDevice = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ScpiDevice"
QT_MOC_LITERAL(1, 11, 11), // "scpiCommand"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "command"
QT_MOC_LITERAL(4, 32, 21), // "startMeasurementTimer"
QT_MOC_LITERAL(5, 54, 17), // "onReceivedMessage"
QT_MOC_LITERAL(6, 72, 7), // "message"
QT_MOC_LITERAL(7, 80, 12), // "queueMeasure"
QT_MOC_LITERAL(8, 93, 6), // "number"
QT_MOC_LITERAL(9, 100, 10), // "connectBus"
QT_MOC_LITERAL(10, 111, 16), // "setScanParameter"
QT_MOC_LITERAL(11, 128, 16), // "MeasurementValue"
QT_MOC_LITERAL(12, 145, 5) // "value"

    },
    "ScpiDevice\0scpiCommand\0\0command\0"
    "startMeasurementTimer\0onReceivedMessage\0"
    "message\0queueMeasure\0number\0connectBus\0"
    "setScanParameter\0MeasurementValue\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScpiDevice[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   48,    2, 0x0a /* Public */,
       7,    1,   51,    2, 0x0a /* Public */,
       9,    0,   54,    2, 0x0a /* Public */,
      10,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::ULongLong,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void ScpiDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScpiDevice *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->scpiCommand((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->startMeasurementTimer(); break;
        case 2: _t->onReceivedMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->queueMeasure((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 4: _t->connectBus(); break;
        case 5: _t->setScanParameter((*reinterpret_cast< MeasurementValue(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ScpiDevice::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScpiDevice::scpiCommand)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ScpiDevice::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScpiDevice::startMeasurementTimer)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ScpiDevice::staticMetaObject = { {
    QMetaObject::SuperData::link<MeasurementDevice::staticMetaObject>(),
    qt_meta_stringdata_ScpiDevice.data,
    qt_meta_data_ScpiDevice,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ScpiDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScpiDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScpiDevice.stringdata0))
        return static_cast<void*>(this);
    return MeasurementDevice::qt_metacast(_clname);
}

int ScpiDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MeasurementDevice::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ScpiDevice::scpiCommand(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ScpiDevice::startMeasurementTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
