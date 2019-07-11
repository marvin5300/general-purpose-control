/****************************************************************************
** Meta object code from reading C++ file 'rs232.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../rs232.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rs232.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RS232_t {
    QByteArrayData data[14];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RS232_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RS232_t qt_meta_stringdata_RS232 = {
    {
QT_MOC_LITERAL(0, 0, 5), // "RS232"
QT_MOC_LITERAL(1, 6, 15), // "receivedMessage"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 7), // "message"
QT_MOC_LITERAL(4, 31, 16), // "connectionStatus"
QT_MOC_LITERAL(5, 48, 9), // "connected"
QT_MOC_LITERAL(6, 58, 11), // "onReadyRead"
QT_MOC_LITERAL(7, 70, 14), // "makeConnection"
QT_MOC_LITERAL(8, 85, 15), // "sendScpiCommand"
QT_MOC_LITERAL(9, 101, 7), // "command"
QT_MOC_LITERAL(10, 109, 15), // "closeConnection"
QT_MOC_LITERAL(11, 125, 11), // "scanMessage"
QT_MOC_LITERAL(12, 137, 12), // "std::string&"
QT_MOC_LITERAL(13, 150, 6) // "buffer"

    },
    "RS232\0receivedMessage\0\0message\0"
    "connectionStatus\0connected\0onReadyRead\0"
    "makeConnection\0sendScpiCommand\0command\0"
    "closeConnection\0scanMessage\0std::string&\0"
    "buffer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RS232[] = {

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
       6,    0,   55,    2, 0x0a /* Public */,
       7,    0,   56,    2, 0x0a /* Public */,
       8,    1,   57,    2, 0x0a /* Public */,
      10,    0,   60,    2, 0x0a /* Public */,
      11,    1,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 12,   13,

       0        // eod
};

void RS232::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RS232 *_t = static_cast<RS232 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receivedMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->connectionStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onReadyRead(); break;
        case 3: _t->makeConnection(); break;
        case 4: _t->sendScpiCommand((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->closeConnection(); break;
        case 6: { bool _r = _t->scanMessage((*reinterpret_cast< std::string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (RS232::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RS232::receivedMessage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RS232::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RS232::connectionStatus)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject RS232::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RS232.data,
      qt_meta_data_RS232,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RS232::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RS232::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RS232.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RS232::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void RS232::receivedMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RS232::connectionStatus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
