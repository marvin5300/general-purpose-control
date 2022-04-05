/****************************************************************************
** Meta object code from reading C++ file 'tektronix_dmm4020.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../include/devices/tektronix_dmm4020.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tektronix_dmm4020.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tektronix_DMM4020_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tektronix_DMM4020_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tektronix_DMM4020_t qt_meta_stringdata_Tektronix_DMM4020 = {
    {
QT_MOC_LITERAL(0, 0, 17) // "Tektronix_DMM4020"

    },
    "Tektronix_DMM4020"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tektronix_DMM4020[] = {

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

void Tektronix_DMM4020::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject Tektronix_DMM4020::staticMetaObject = { {
    QMetaObject::SuperData::link<ScpiDevice::staticMetaObject>(),
    qt_meta_stringdata_Tektronix_DMM4020.data,
    qt_meta_data_Tektronix_DMM4020,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Tektronix_DMM4020::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tektronix_DMM4020::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tektronix_DMM4020.stringdata0))
        return static_cast<void*>(this);
    return ScpiDevice::qt_metacast(_clname);
}

int Tektronix_DMM4020::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ScpiDevice::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
