/****************************************************************************
** Meta object code from reading C++ file 'CSynchcommConsumer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../include/CSynchcommConsumer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CSynchcommConsumer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CSynchCommConsumer_t {
    QByteArrayData data[12];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSynchCommConsumer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSynchCommConsumer_t qt_meta_stringdata_CSynchCommConsumer = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CSynchCommConsumer"
QT_MOC_LITERAL(1, 19, 8), // "response"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 1), // "s"
QT_MOC_LITERAL(4, 31, 5), // "error"
QT_MOC_LITERAL(5, 37, 7), // "timeout"
QT_MOC_LITERAL(6, 45, 6), // "logger"
QT_MOC_LITERAL(7, 52, 21), // "serialPortIsConnected"
QT_MOC_LITERAL(8, 74, 10), // "_connected"
QT_MOC_LITERAL(9, 85, 17), // "bufferSizeChanged"
QT_MOC_LITERAL(10, 103, 11), // "_bufferSize"
QT_MOC_LITERAL(11, 115, 11) // "sendRequest"

    },
    "CSynchCommConsumer\0response\0\0s\0error\0"
    "timeout\0logger\0serialPortIsConnected\0"
    "_connected\0bufferSizeChanged\0_bufferSize\0"
    "sendRequest"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSynchCommConsumer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       5,    1,   55,    2, 0x06 /* Public */,
       6,    1,   58,    2, 0x06 /* Public */,
       7,    1,   61,    2, 0x06 /* Public */,
       9,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Int,   10,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void CSynchCommConsumer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CSynchCommConsumer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->response((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->timeout((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->logger((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->serialPortIsConnected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->bufferSizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->sendRequest(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CSynchCommConsumer::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CSynchCommConsumer::response)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CSynchCommConsumer::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CSynchCommConsumer::error)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CSynchCommConsumer::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CSynchCommConsumer::timeout)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CSynchCommConsumer::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CSynchCommConsumer::logger)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CSynchCommConsumer::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CSynchCommConsumer::serialPortIsConnected)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CSynchCommConsumer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CSynchCommConsumer::bufferSizeChanged)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CSynchCommConsumer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CSynchCommConsumer.data,
    qt_meta_data_CSynchCommConsumer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CSynchCommConsumer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSynchCommConsumer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CSynchCommConsumer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CSynchCommConsumer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void CSynchCommConsumer::response(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CSynchCommConsumer::error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CSynchCommConsumer::timeout(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CSynchCommConsumer::logger(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CSynchCommConsumer::serialPortIsConnected(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CSynchCommConsumer::bufferSizeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
