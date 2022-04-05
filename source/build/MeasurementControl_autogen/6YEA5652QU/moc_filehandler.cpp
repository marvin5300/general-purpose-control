/****************************************************************************
** Meta object code from reading C++ file 'filehandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../include/filehandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filehandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileHandler_t {
    QByteArrayData data[19];
    char stringdata0[253];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileHandler_t qt_meta_stringdata_FileHandler = {
    {
QT_MOC_LITERAL(0, 0, 11), // "FileHandler"
QT_MOC_LITERAL(1, 12, 14), // "openedFileName"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "filename"
QT_MOC_LITERAL(4, 37, 18), // "setOutputAutomatic"
QT_MOC_LITERAL(5, 56, 10), // "autoOutput"
QT_MOC_LITERAL(6, 67, 13), // "setOutputFile"
QT_MOC_LITERAL(7, 81, 8), // "fileName"
QT_MOC_LITERAL(8, 90, 23), // "onNewMeasurementStarted"
QT_MOC_LITERAL(9, 114, 21), // "onFinishedMeasurement"
QT_MOC_LITERAL(10, 136, 17), // "onReceivingValues"
QT_MOC_LITERAL(11, 154, 10), // "devicename"
QT_MOC_LITERAL(12, 165, 23), // "QList<MeasurementValue>"
QT_MOC_LITERAL(13, 189, 6), // "values"
QT_MOC_LITERAL(14, 196, 6), // "number"
QT_MOC_LITERAL(15, 203, 9), // "writeLine"
QT_MOC_LITERAL(16, 213, 4), // "line"
QT_MOC_LITERAL(17, 218, 17), // "writeBufferToFile"
QT_MOC_LITERAL(18, 236, 16) // "endOfMeasurement"

    },
    "FileHandler\0openedFileName\0\0filename\0"
    "setOutputAutomatic\0autoOutput\0"
    "setOutputFile\0fileName\0onNewMeasurementStarted\0"
    "onFinishedMeasurement\0onReceivingValues\0"
    "devicename\0QList<MeasurementValue>\0"
    "values\0number\0writeLine\0line\0"
    "writeBufferToFile\0endOfMeasurement"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   57,    2, 0x0a /* Public */,
       6,    1,   60,    2, 0x0a /* Public */,
       8,    0,   63,    2, 0x0a /* Public */,
       9,    0,   64,    2, 0x0a /* Public */,
      10,    3,   65,    2, 0x0a /* Public */,
      15,    1,   72,    2, 0x0a /* Public */,
      17,    1,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 12, QMetaType::ULongLong,   11,   13,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::Bool,   18,

       0        // eod
};

void FileHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileHandler *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->openedFileName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setOutputAutomatic((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setOutputFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->onNewMeasurementStarted(); break;
        case 4: _t->onFinishedMeasurement(); break;
        case 5: _t->onReceivingValues((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<MeasurementValue>(*)>(_a[2])),(*reinterpret_cast< quint64(*)>(_a[3]))); break;
        case 6: _t->writeLine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->writeBufferToFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FileHandler::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileHandler::openedFileName)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FileHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FileHandler.data,
    qt_meta_data_FileHandler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FileHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FileHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void FileHandler::openedFileName(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
