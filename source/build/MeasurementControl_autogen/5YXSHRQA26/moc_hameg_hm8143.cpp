/****************************************************************************
** Meta object code from reading C++ file 'hameg_hm8143.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../include/devices/hameg_hm8143.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hameg_hm8143.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Hameg_HM8143_t {
    QByteArrayData data[1];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Hameg_HM8143_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Hameg_HM8143_t qt_meta_stringdata_Hameg_HM8143 = {
    {
QT_MOC_LITERAL(0, 0, 12) // "Hameg_HM8143"

    },
    "Hameg_HM8143"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Hameg_HM8143[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void Hameg_HM8143::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject Hameg_HM8143::staticMetaObject = { {
    QMetaObject::SuperData::link<ScpiDevice::staticMetaObject>(),
    qt_meta_stringdata_Hameg_HM8143.data,
    qt_meta_data_Hameg_HM8143,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Hameg_HM8143::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Hameg_HM8143::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Hameg_HM8143.stringdata0))
        return static_cast<void*>(this);
    return ScpiDevice::qt_metacast(_clname);
}

int Hameg_HM8143::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ScpiDevice::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
