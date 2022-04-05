/****************************************************************************
** Meta object code from reading C++ file 'cdevice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../include/cdevice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cdevice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CDevice_t {
    QByteArrayData data[22];
    char stringdata0[246];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CDevice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CDevice_t qt_meta_stringdata_CDevice = {
    {
QT_MOC_LITERAL(0, 0, 7), // "CDevice"
QT_MOC_LITERAL(1, 8, 5), // "error"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 12), // "_windowTitle"
QT_MOC_LITERAL(4, 28, 11), // "_windowText"
QT_MOC_LITERAL(5, 40, 7), // "warning"
QT_MOC_LITERAL(6, 48, 11), // "information"
QT_MOC_LITERAL(7, 60, 13), // "dataToDisplay"
QT_MOC_LITERAL(8, 74, 5), // "_data"
QT_MOC_LITERAL(9, 80, 9), // "connected"
QT_MOC_LITERAL(10, 90, 15), // "displayResponse"
QT_MOC_LITERAL(11, 106, 8), // "readData"
QT_MOC_LITERAL(12, 115, 17), // "bufferSizeChanged"
QT_MOC_LITERAL(13, 133, 11), // "_bufferSize"
QT_MOC_LITERAL(14, 145, 16), // "stopStateMachine"
QT_MOC_LITERAL(15, 162, 8), // "readDone"
QT_MOC_LITERAL(16, 171, 16), // "on_synchResponse"
QT_MOC_LITERAL(17, 188, 8), // "response"
QT_MOC_LITERAL(18, 197, 13), // "on_synchError"
QT_MOC_LITERAL(19, 211, 1), // "s"
QT_MOC_LITERAL(20, 213, 15), // "on_synchTimeout"
QT_MOC_LITERAL(21, 229, 16) // "on_threadStarted"

    },
    "CDevice\0error\0\0_windowTitle\0_windowText\0"
    "warning\0information\0dataToDisplay\0"
    "_data\0connected\0displayResponse\0"
    "readData\0bufferSizeChanged\0_bufferSize\0"
    "stopStateMachine\0readDone\0on_synchResponse\0"
    "response\0on_synchError\0s\0on_synchTimeout\0"
    "on_threadStarted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CDevice[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,
       5,    2,   89,    2, 0x06 /* Public */,
       6,    2,   94,    2, 0x06 /* Public */,
       7,    1,   99,    2, 0x06 /* Public */,
       9,    1,  102,    2, 0x06 /* Public */,
      10,    1,  105,    2, 0x06 /* Public */,
      12,    1,  108,    2, 0x06 /* Public */,
      14,    0,  111,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,  112,    2, 0x0a /* Public */,
      15,    0,  113,    2, 0x0a /* Public */,
      16,    1,  114,    2, 0x0a /* Public */,
      18,    1,  117,    2, 0x0a /* Public */,
      20,    1,  120,    2, 0x0a /* Public */,
      21,    0,  123,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,

 // slots: parameters
    QMetaType::UInt,
    QMetaType::UInt,
    QMetaType::UInt, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void,

       0        // eod
};

void CDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CDevice *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->warning((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->information((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->dataToDisplay((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->connected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->displayResponse((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->bufferSizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->stopStateMachine(); break;
        case 8: { uint _r = _t->readData();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 9: { uint _r = _t->readDone();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 10: { uint _r = _t->on_synchResponse((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->on_synchError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_synchTimeout((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->on_threadStarted(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CDevice::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CDevice::error)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CDevice::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CDevice::warning)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CDevice::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CDevice::information)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CDevice::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CDevice::dataToDisplay)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CDevice::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CDevice::connected)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CDevice::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CDevice::displayResponse)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CDevice::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CDevice::bufferSizeChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (CDevice::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CDevice::stopStateMachine)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CDevice::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CDevice.data,
    qt_meta_data_CDevice,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CDevice.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void CDevice::error(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CDevice::warning(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CDevice::information(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CDevice::dataToDisplay(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CDevice::connected(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CDevice::displayResponse(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CDevice::bufferSizeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CDevice::stopStateMachine()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
