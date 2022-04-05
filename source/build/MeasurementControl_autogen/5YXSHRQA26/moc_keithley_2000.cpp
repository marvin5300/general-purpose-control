/****************************************************************************
** Meta object code from reading C++ file 'keithley_2000.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../include/devices/keithley_2000.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'keithley_2000.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Keithley_2000_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Keithley_2000_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Keithley_2000_t qt_meta_stringdata_Keithley_2000 = {
    {
QT_MOC_LITERAL(0, 0, 13) // "Keithley_2000"

    },
    "Keithley_2000"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Keithley_2000[] = {

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

void Keithley_2000::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject Keithley_2000::staticMetaObject = { {
    QMetaObject::SuperData::link<ScpiDevice::staticMetaObject>(),
    qt_meta_stringdata_Keithley_2000.data,
    qt_meta_data_Keithley_2000,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Keithley_2000::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Keithley_2000::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Keithley_2000.stringdata0))
        return static_cast<void*>(this);
    return ScpiDevice::qt_metacast(_clname);
}

int Keithley_2000::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ScpiDevice::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
