/****************************************************************************
** Meta object code from reading C++ file 'measurementdevice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../include/measurementdevice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QPointer>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'measurementdevice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MeasurementDevice_t {
    QByteArrayData data[29];
    char stringdata0[445];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MeasurementDevice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MeasurementDevice_t qt_meta_stringdata_MeasurementDevice = {
    {
QT_MOC_LITERAL(0, 0, 17), // "MeasurementDevice"
QT_MOC_LITERAL(1, 18, 15), // "closeConnection"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 21), // "deviceSelectionChange"
QT_MOC_LITERAL(4, 57, 27), // "QPointer<MeasurementDevice>"
QT_MOC_LITERAL(5, 85, 6), // "device"
QT_MOC_LITERAL(6, 92, 14), // "_newDeviceName"
QT_MOC_LITERAL(7, 107, 17), // "_newInterfaceName"
QT_MOC_LITERAL(8, 125, 14), // "measuredValues"
QT_MOC_LITERAL(9, 140, 10), // "deviceName"
QT_MOC_LITERAL(10, 151, 23), // "QList<MeasurementValue>"
QT_MOC_LITERAL(11, 175, 6), // "values"
QT_MOC_LITERAL(12, 182, 6), // "number"
QT_MOC_LITERAL(13, 189, 12), // "measureReady"
QT_MOC_LITERAL(14, 202, 18), // "scanParameterReady"
QT_MOC_LITERAL(15, 221, 17), // "onReceivedMessage"
QT_MOC_LITERAL(16, 239, 7), // "message"
QT_MOC_LITERAL(17, 247, 12), // "queueMeasure"
QT_MOC_LITERAL(18, 260, 5), // "count"
QT_MOC_LITERAL(19, 266, 10), // "connectBus"
QT_MOC_LITERAL(20, 277, 25), // "onConnectionStatusChanged"
QT_MOC_LITERAL(21, 303, 9), // "connected"
QT_MOC_LITERAL(22, 313, 20), // "setUiConnectionState"
QT_MOC_LITERAL(23, 334, 27), // "onInterfaceSelectionChanged"
QT_MOC_LITERAL(24, 362, 14), // "_interfaceName"
QT_MOC_LITERAL(25, 377, 4), // "exit"
QT_MOC_LITERAL(26, 382, 15), // "setMeasureParam"
QT_MOC_LITERAL(27, 398, 25), // "DeviceParameterConstraint"
QT_MOC_LITERAL(28, 424, 20) // "_parameterConstraint"

    },
    "MeasurementDevice\0closeConnection\0\0"
    "deviceSelectionChange\0QPointer<MeasurementDevice>\0"
    "device\0_newDeviceName\0_newInterfaceName\0"
    "measuredValues\0deviceName\0"
    "QList<MeasurementValue>\0values\0number\0"
    "measureReady\0scanParameterReady\0"
    "onReceivedMessage\0message\0queueMeasure\0"
    "count\0connectBus\0onConnectionStatusChanged\0"
    "connected\0setUiConnectionState\0"
    "onInterfaceSelectionChanged\0_interfaceName\0"
    "exit\0setMeasureParam\0DeviceParameterConstraint\0"
    "_parameterConstraint"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MeasurementDevice[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    3,   80,    2, 0x06 /* Public */,
       8,    3,   87,    2, 0x06 /* Public */,
      13,    2,   94,    2, 0x06 /* Public */,
      14,    2,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    1,  104,    2, 0x0a /* Public */,
      17,    1,  107,    2, 0x0a /* Public */,
      19,    0,  110,    2, 0x0a /* Public */,
      20,    1,  111,    2, 0x0a /* Public */,
      22,    1,  114,    2, 0x0a /* Public */,
      23,    1,  117,    2, 0x0a /* Public */,
      25,    0,  120,    2, 0x0a /* Public */,
      26,    1,  121,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QString, QMetaType::QString,    5,    6,    7,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 10, QMetaType::ULongLong,    9,   11,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::ULongLong,    9,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::ULongLong,    9,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::ULongLong,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void,
    QMetaType::UInt, 0x80000000 | 27,   28,

       0        // eod
};

void MeasurementDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MeasurementDevice *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->closeConnection(); break;
        case 1: _t->deviceSelectionChange((*reinterpret_cast< QPointer<MeasurementDevice>(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->measuredValues((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<MeasurementValue>(*)>(_a[2])),(*reinterpret_cast< quint64(*)>(_a[3]))); break;
        case 3: _t->measureReady((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2]))); break;
        case 4: _t->scanParameterReady((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2]))); break;
        case 5: _t->onReceivedMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->queueMeasure((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 7: _t->connectBus(); break;
        case 8: _t->onConnectionStatusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->setUiConnectionState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->onInterfaceSelectionChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->exit(); break;
        case 12: { uint _r = _t->setMeasureParam((*reinterpret_cast< DeviceParameterConstraint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QPointer<MeasurementDevice> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MeasurementDevice::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MeasurementDevice::closeConnection)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MeasurementDevice::*)(QPointer<MeasurementDevice> , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MeasurementDevice::deviceSelectionChange)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MeasurementDevice::*)(QString , QList<MeasurementValue> , quint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MeasurementDevice::measuredValues)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MeasurementDevice::*)(QString , quint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MeasurementDevice::measureReady)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MeasurementDevice::*)(QString , quint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MeasurementDevice::scanParameterReady)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MeasurementDevice::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_meta_stringdata_MeasurementDevice.data,
    qt_meta_data_MeasurementDevice,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MeasurementDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MeasurementDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MeasurementDevice.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int MeasurementDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MeasurementDevice::closeConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MeasurementDevice::deviceSelectionChange(QPointer<MeasurementDevice> _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MeasurementDevice::measuredValues(QString _t1, QList<MeasurementValue> _t2, quint64 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MeasurementDevice::measureReady(QString _t1, quint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MeasurementDevice::scanParameterReady(QString _t1, quint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
