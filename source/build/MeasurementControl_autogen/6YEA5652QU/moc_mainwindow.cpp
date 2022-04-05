/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../include/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QPointer>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[48];
    char stringdata0[859];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "setOutputFile"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "filename"
QT_MOC_LITERAL(4, 35, 17), // "setAutoOutputFile"
QT_MOC_LITERAL(5, 53, 10), // "autoOutput"
QT_MOC_LITERAL(6, 64, 12), // "nextInterval"
QT_MOC_LITERAL(7, 77, 7), // "measure"
QT_MOC_LITERAL(8, 85, 5), // "count"
QT_MOC_LITERAL(9, 91, 8), // "scanInit"
QT_MOC_LITERAL(10, 100, 16), // "startMeasurement"
QT_MOC_LITERAL(11, 117, 19), // "finishedMeasurement"
QT_MOC_LITERAL(12, 137, 13), // "probeProgress"
QT_MOC_LITERAL(13, 151, 13), // "progressStart"
QT_MOC_LITERAL(14, 165, 15), // "setMeasureParam"
QT_MOC_LITERAL(15, 181, 25), // "DeviceParameterConstraint"
QT_MOC_LITERAL(16, 207, 16), // "_paramConstraint"
QT_MOC_LITERAL(17, 224, 25), // "ongoingMeasurementChanged"
QT_MOC_LITERAL(18, 250, 28), // "on_pushButton_Logger_clicked"
QT_MOC_LITERAL(19, 279, 34), // "on_pushButton_Measurements_cl..."
QT_MOC_LITERAL(20, 314, 28), // "on_pushButton_Prober_clicked"
QT_MOC_LITERAL(21, 343, 26), // "on_pushButton_Open_clicked"
QT_MOC_LITERAL(22, 370, 30), // "on_pushButton_MeasDevs_clicked"
QT_MOC_LITERAL(23, 401, 30), // "onAddAdjustValuesButtonClicked"
QT_MOC_LITERAL(24, 432, 31), // "onAddMeasureValuesButtonClicked"
QT_MOC_LITERAL(25, 464, 27), // "adjustProgressBarAppearance"
QT_MOC_LITERAL(26, 492, 5), // "value"
QT_MOC_LITERAL(27, 498, 31), // "onStartMeasurementButtonClicked"
QT_MOC_LITERAL(28, 530, 21), // "onFinishedMeasurement"
QT_MOC_LITERAL(29, 552, 23), // "onDeviceSelectionChange"
QT_MOC_LITERAL(30, 576, 27), // "QPointer<MeasurementDevice>"
QT_MOC_LITERAL(31, 604, 6), // "device"
QT_MOC_LITERAL(32, 611, 14), // "_newDeviceName"
QT_MOC_LITERAL(33, 626, 17), // "_newInterfaceName"
QT_MOC_LITERAL(34, 644, 17), // "onSettingsClicked"
QT_MOC_LITERAL(35, 662, 18), // "onProgressReceived"
QT_MOC_LITERAL(36, 681, 8), // "progress"
QT_MOC_LITERAL(37, 690, 14), // "onMeasureReady"
QT_MOC_LITERAL(38, 705, 10), // "deviceName"
QT_MOC_LITERAL(39, 716, 6), // "number"
QT_MOC_LITERAL(40, 723, 19), // "onScanParamSelReady"
QT_MOC_LITERAL(41, 743, 14), // "onTimerTimeout"
QT_MOC_LITERAL(42, 758, 13), // "setSerialMask"
QT_MOC_LITERAL(43, 772, 5), // "masks"
QT_MOC_LITERAL(44, 778, 25), // "onDeletMeasurementDevices"
QT_MOC_LITERAL(45, 804, 23), // "onAddMeasurementDevices"
QT_MOC_LITERAL(46, 828, 17), // "_measurementParam"
QT_MOC_LITERAL(47, 846, 12) // "onTimerStart"

    },
    "MainWindow\0setOutputFile\0\0filename\0"
    "setAutoOutputFile\0autoOutput\0nextInterval\0"
    "measure\0count\0scanInit\0startMeasurement\0"
    "finishedMeasurement\0probeProgress\0"
    "progressStart\0setMeasureParam\0"
    "DeviceParameterConstraint\0_paramConstraint\0"
    "ongoingMeasurementChanged\0"
    "on_pushButton_Logger_clicked\0"
    "on_pushButton_Measurements_clicked\0"
    "on_pushButton_Prober_clicked\0"
    "on_pushButton_Open_clicked\0"
    "on_pushButton_MeasDevs_clicked\0"
    "onAddAdjustValuesButtonClicked\0"
    "onAddMeasureValuesButtonClicked\0"
    "adjustProgressBarAppearance\0value\0"
    "onStartMeasurementButtonClicked\0"
    "onFinishedMeasurement\0onDeviceSelectionChange\0"
    "QPointer<MeasurementDevice>\0device\0"
    "_newDeviceName\0_newInterfaceName\0"
    "onSettingsClicked\0onProgressReceived\0"
    "progress\0onMeasureReady\0deviceName\0"
    "number\0onScanParamSelReady\0onTimerTimeout\0"
    "setSerialMask\0masks\0onDeletMeasurementDevices\0"
    "onAddMeasurementDevices\0_measurementParam\0"
    "onTimerStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  169,    2, 0x06 /* Public */,
       4,    1,  172,    2, 0x06 /* Public */,
       6,    0,  175,    2, 0x06 /* Public */,
       7,    1,  176,    2, 0x06 /* Public */,
       9,    0,  179,    2, 0x06 /* Public */,
      10,    0,  180,    2, 0x06 /* Public */,
      11,    0,  181,    2, 0x06 /* Public */,
      12,    1,  182,    2, 0x06 /* Public */,
      12,    0,  185,    2, 0x26 /* Public | MethodCloned */,
      14,    1,  186,    2, 0x06 /* Public */,
      17,    1,  189,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    0,  192,    2, 0x08 /* Private */,
      19,    0,  193,    2, 0x08 /* Private */,
      20,    0,  194,    2, 0x08 /* Private */,
      21,    0,  195,    2, 0x08 /* Private */,
      22,    0,  196,    2, 0x08 /* Private */,
      23,    0,  197,    2, 0x08 /* Private */,
      24,    0,  198,    2, 0x08 /* Private */,
      25,    1,  199,    2, 0x08 /* Private */,
      27,    0,  202,    2, 0x08 /* Private */,
      28,    0,  203,    2, 0x08 /* Private */,
      29,    3,  204,    2, 0x0a /* Public */,
      34,    0,  211,    2, 0x0a /* Public */,
      35,    1,  212,    2, 0x0a /* Public */,
      37,    2,  215,    2, 0x0a /* Public */,
      40,    2,  220,    2, 0x0a /* Public */,
      41,    0,  225,    2, 0x0a /* Public */,
      42,    1,  226,    2, 0x0a /* Public */,
      44,    0,  229,    2, 0x0a /* Public */,
      45,    1,  230,    2, 0x0a /* Public */,
      47,    0,  233,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::ULongLong,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 30, QMetaType::QString, QMetaType::QString,   31,   32,   33,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   36,
    QMetaType::Void, QMetaType::QString, QMetaType::ULongLong,   38,   39,
    QMetaType::Void, QMetaType::QString, QMetaType::ULongLong,   38,   39,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,   43,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   46,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setOutputFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setAutoOutputFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->nextInterval(); break;
        case 3: _t->measure((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 4: _t->scanInit(); break;
        case 5: _t->startMeasurement(); break;
        case 6: _t->finishedMeasurement(); break;
        case 7: _t->probeProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->probeProgress(); break;
        case 9: _t->setMeasureParam((*reinterpret_cast< DeviceParameterConstraint(*)>(_a[1]))); break;
        case 10: _t->ongoingMeasurementChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_pushButton_Logger_clicked(); break;
        case 12: _t->on_pushButton_Measurements_clicked(); break;
        case 13: _t->on_pushButton_Prober_clicked(); break;
        case 14: _t->on_pushButton_Open_clicked(); break;
        case 15: _t->on_pushButton_MeasDevs_clicked(); break;
        case 16: _t->onAddAdjustValuesButtonClicked(); break;
        case 17: _t->onAddMeasureValuesButtonClicked(); break;
        case 18: _t->adjustProgressBarAppearance((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->onStartMeasurementButtonClicked(); break;
        case 20: _t->onFinishedMeasurement(); break;
        case 21: _t->onDeviceSelectionChange((*reinterpret_cast< QPointer<MeasurementDevice>(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 22: _t->onSettingsClicked(); break;
        case 23: _t->onProgressReceived((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->onMeasureReady((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2]))); break;
        case 25: _t->onScanParamSelReady((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2]))); break;
        case 26: _t->onTimerTimeout(); break;
        case 27: _t->setSerialMask((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 28: _t->onDeletMeasurementDevices(); break;
        case 29: _t->onAddMeasurementDevices((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->onTimerStart(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 21:
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
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::setOutputFile)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::setAutoOutputFile)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::nextInterval)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(quint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::measure)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::scanInit)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::startMeasurement)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::finishedMeasurement)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::probeProgress)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(DeviceParameterConstraint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::setMeasureParam)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::ongoingMeasurementChanged)) {
                *result = 10;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::setOutputFile(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::setAutoOutputFile(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::nextInterval()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::measure(quint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::scanInit()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWindow::startMeasurement()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MainWindow::finishedMeasurement()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MainWindow::probeProgress(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 9
void MainWindow::setMeasureParam(DeviceParameterConstraint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MainWindow::ongoingMeasurementChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
