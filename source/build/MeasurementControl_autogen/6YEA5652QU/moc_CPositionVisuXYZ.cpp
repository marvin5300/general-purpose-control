/****************************************************************************
** Meta object code from reading C++ file 'CPositionVisuXYZ.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../include/CPositionVisuXYZ.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CPositionVisuXYZ.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CPositionVisuXYZ_t {
    QByteArrayData data[12];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CPositionVisuXYZ_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CPositionVisuXYZ_t qt_meta_stringdata_CPositionVisuXYZ = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CPositionVisuXYZ"
QT_MOC_LITERAL(1, 17, 15), // "positionChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 10), // "_labelName"
QT_MOC_LITERAL(4, 45, 9), // "CPosition"
QT_MOC_LITERAL(5, 55, 12), // "_newPosition"
QT_MOC_LITERAL(6, 68, 7), // "warning"
QT_MOC_LITERAL(7, 76, 12), // "_windowTitle"
QT_MOC_LITERAL(8, 89, 11), // "_windowText"
QT_MOC_LITERAL(9, 101, 23), // "on_inputPositionChanged"
QT_MOC_LITERAL(10, 125, 26), // "on_writePositionToTextEdit"
QT_MOC_LITERAL(11, 152, 9) // "_position"

    },
    "CPositionVisuXYZ\0positionChanged\0\0"
    "_labelName\0CPosition\0_newPosition\0"
    "warning\0_windowTitle\0_windowText\0"
    "on_inputPositionChanged\0"
    "on_writePositionToTextEdit\0_position"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CPositionVisuXYZ[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       6,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   44,    2, 0x08 /* Private */,
      10,    1,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,   11,

       0        // eod
};

void CPositionVisuXYZ::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CPositionVisuXYZ *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->positionChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< CPosition(*)>(_a[2]))); break;
        case 1: _t->warning((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->on_inputPositionChanged(); break;
        case 3: _t->on_writePositionToTextEdit((*reinterpret_cast< CPosition(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CPositionVisuXYZ::*)(QString , CPosition );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CPositionVisuXYZ::positionChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CPositionVisuXYZ::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CPositionVisuXYZ::warning)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CPositionVisuXYZ::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CPositionVisuXYZ.data,
    qt_meta_data_CPositionVisuXYZ,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CPositionVisuXYZ::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CPositionVisuXYZ::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CPositionVisuXYZ.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CPositionVisuXYZ::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CPositionVisuXYZ::positionChanged(QString _t1, CPosition _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CPositionVisuXYZ::warning(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
