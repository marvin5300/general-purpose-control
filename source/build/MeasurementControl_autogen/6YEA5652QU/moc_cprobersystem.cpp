/****************************************************************************
** Meta object code from reading C++ file 'cprobersystem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../include/cprobersystem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cprobersystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CProberSystem_t {
    QByteArrayData data[32];
    char stringdata0[420];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CProberSystem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CProberSystem_t qt_meta_stringdata_CProberSystem = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CProberSystem"
QT_MOC_LITERAL(1, 14, 10), // "inPosition"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10), // "addCommand"
QT_MOC_LITERAL(4, 37, 8), // "_command"
QT_MOC_LITERAL(5, 46, 11), // "inZPosition"
QT_MOC_LITERAL(6, 58, 12), // "inXYPosition"
QT_MOC_LITERAL(7, 71, 14), // "notInZPosition"
QT_MOC_LITERAL(8, 86, 15), // "notInXYPosition"
QT_MOC_LITERAL(9, 102, 11), // "actPosition"
QT_MOC_LITERAL(10, 114, 9), // "CPosition"
QT_MOC_LITERAL(11, 124, 9), // "_position"
QT_MOC_LITERAL(12, 134, 20), // "on_timeoutCycReadPos"
QT_MOC_LITERAL(13, 155, 26), // "on_asynchReadChuckPosition"
QT_MOC_LITERAL(14, 182, 10), // "CPosition*"
QT_MOC_LITERAL(15, 193, 13), // "_readPosition"
QT_MOC_LITERAL(16, 207, 20), // "on_synchReadChuckPos"
QT_MOC_LITERAL(17, 228, 13), // "_readChuckPos"
QT_MOC_LITERAL(18, 242, 21), // "on_requestMoveChuckXY"
QT_MOC_LITERAL(19, 264, 5), // "_xPos"
QT_MOC_LITERAL(20, 270, 5), // "_yPos"
QT_MOC_LITERAL(21, 276, 7), // "_posRef"
QT_MOC_LITERAL(22, 284, 5), // "_unit"
QT_MOC_LITERAL(23, 290, 9), // "_velocity"
QT_MOC_LITERAL(24, 300, 20), // "on_requestMoveChuckZ"
QT_MOC_LITERAL(25, 321, 5), // "_zPos"
QT_MOC_LITERAL(26, 327, 11), // "on_response"
QT_MOC_LITERAL(27, 339, 9), // "_response"
QT_MOC_LITERAL(28, 349, 20), // "on_requestInPosition"
QT_MOC_LITERAL(29, 370, 18), // "displayActPosition"
QT_MOC_LITERAL(30, 389, 17), // "CPositionVisuXYZ*"
QT_MOC_LITERAL(31, 407, 12) // "_actPosition"

    },
    "CProberSystem\0inPosition\0\0addCommand\0"
    "_command\0inZPosition\0inXYPosition\0"
    "notInZPosition\0notInXYPosition\0"
    "actPosition\0CPosition\0_position\0"
    "on_timeoutCycReadPos\0on_asynchReadChuckPosition\0"
    "CPosition*\0_readPosition\0on_synchReadChuckPos\0"
    "_readChuckPos\0on_requestMoveChuckXY\0"
    "_xPos\0_yPos\0_posRef\0_unit\0_velocity\0"
    "on_requestMoveChuckZ\0_zPos\0on_response\0"
    "_response\0on_requestInPosition\0"
    "displayActPosition\0CPositionVisuXYZ*\0"
    "_actPosition"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CProberSystem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    1,   95,    2, 0x06 /* Public */,
       5,    0,   98,    2, 0x06 /* Public */,
       6,    0,   99,    2, 0x06 /* Public */,
       7,    0,  100,    2, 0x06 /* Public */,
       8,    0,  101,    2, 0x06 /* Public */,
       9,    1,  102,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,  105,    2, 0x08 /* Private */,
      13,    1,  106,    2, 0x0a /* Public */,
      13,    0,  109,    2, 0x2a /* Public | MethodCloned */,
      16,    1,  110,    2, 0x0a /* Public */,
      18,    5,  113,    2, 0x0a /* Public */,
      24,    4,  124,    2, 0x0a /* Public */,
      26,    1,  133,    2, 0x0a /* Public */,
      28,    0,  136,    2, 0x0a /* Public */,
      29,    1,  137,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::UInt, 0x80000000 | 14,   15,
    QMetaType::UInt,
    QMetaType::UInt, QMetaType::QString,   17,
    QMetaType::UInt, QMetaType::Double, QMetaType::Double, QMetaType::QString, QMetaType::QString, QMetaType::QString,   19,   20,   21,   22,   23,
    QMetaType::UInt, QMetaType::Double, QMetaType::QString, QMetaType::QString, QMetaType::QString,   25,   21,   22,   23,
    QMetaType::UInt, QMetaType::QString,   27,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 30,   31,

       0        // eod
};

void CProberSystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CProberSystem *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->inPosition(); break;
        case 1: _t->addCommand((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->inZPosition(); break;
        case 3: _t->inXYPosition(); break;
        case 4: _t->notInZPosition(); break;
        case 5: _t->notInXYPosition(); break;
        case 6: _t->actPosition((*reinterpret_cast< CPosition(*)>(_a[1]))); break;
        case 7: _t->on_timeoutCycReadPos(); break;
        case 8: { uint _r = _t->on_asynchReadChuckPosition((*reinterpret_cast< CPosition*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 9: { uint _r = _t->on_asynchReadChuckPosition();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 10: { uint _r = _t->on_synchReadChuckPos((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 11: { uint _r = _t->on_requestMoveChuckXY((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 12: { uint _r = _t->on_requestMoveChuckZ((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 13: { uint _r = _t->on_response((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->on_requestInPosition(); break;
        case 15: _t->displayActPosition((*reinterpret_cast< CPositionVisuXYZ*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CPosition* >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CPositionVisuXYZ* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CProberSystem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CProberSystem::inPosition)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CProberSystem::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CProberSystem::addCommand)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CProberSystem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CProberSystem::inZPosition)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CProberSystem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CProberSystem::inXYPosition)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CProberSystem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CProberSystem::notInZPosition)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CProberSystem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CProberSystem::notInXYPosition)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CProberSystem::*)(CPosition );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CProberSystem::actPosition)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CProberSystem::staticMetaObject = { {
    QMetaObject::SuperData::link<CDevice::staticMetaObject>(),
    qt_meta_stringdata_CProberSystem.data,
    qt_meta_data_CProberSystem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CProberSystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CProberSystem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CProberSystem.stringdata0))
        return static_cast<void*>(this);
    return CDevice::qt_metacast(_clname);
}

int CProberSystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CDevice::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void CProberSystem::inPosition()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CProberSystem::addCommand(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CProberSystem::inZPosition()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CProberSystem::inXYPosition()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void CProberSystem::notInZPosition()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void CProberSystem::notInXYPosition()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void CProberSystem::actPosition(CPosition _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
