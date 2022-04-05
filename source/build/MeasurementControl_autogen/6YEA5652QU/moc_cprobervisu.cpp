/****************************************************************************
** Meta object code from reading C++ file 'cprobervisu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../include/cprobervisu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cprobervisu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CProberVisu_t {
    QByteArrayData data[66];
    char stringdata0[1295];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CProberVisu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CProberVisu_t qt_meta_stringdata_CProberVisu = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CProberVisu"
QT_MOC_LITERAL(1, 12, 10), // "addCommand"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "_command"
QT_MOC_LITERAL(4, 33, 17), // "startStateMachine"
QT_MOC_LITERAL(5, 51, 16), // "stopStateMachine"
QT_MOC_LITERAL(6, 68, 24), // "deleteMeasurementDevices"
QT_MOC_LITERAL(7, 93, 16), // "measurementParam"
QT_MOC_LITERAL(8, 110, 1), // "i"
QT_MOC_LITERAL(9, 112, 22), // "paramNameInFileChanged"
QT_MOC_LITERAL(10, 135, 16), // "_paramNameInFile"
QT_MOC_LITERAL(11, 152, 12), // "zValuePrePos"
QT_MOC_LITERAL(12, 165, 10), // "_zPreValue"
QT_MOC_LITERAL(13, 176, 14), // "zValueFinalPos"
QT_MOC_LITERAL(14, 191, 10), // "_zFinalPos"
QT_MOC_LITERAL(15, 202, 15), // "changedPosition"
QT_MOC_LITERAL(16, 218, 4), // "_row"
QT_MOC_LITERAL(17, 223, 7), // "_column"
QT_MOC_LITERAL(18, 231, 9), // "CPosition"
QT_MOC_LITERAL(19, 241, 4), // "_pos"
QT_MOC_LITERAL(20, 246, 18), // "requesMeasCtrlData"
QT_MOC_LITERAL(21, 265, 24), // "changePositionStylesheet"
QT_MOC_LITERAL(22, 290, 11), // "_stylesheet"
QT_MOC_LITERAL(23, 302, 29), // "on_textEdit_ZPreValue_changed"
QT_MOC_LITERAL(24, 332, 31), // "on_textEdit_ZFinalValue_changed"
QT_MOC_LITERAL(25, 364, 28), // "on_pushButton_Search_clicked"
QT_MOC_LITERAL(26, 393, 29), // "on_pushButton_Connect_clicked"
QT_MOC_LITERAL(27, 423, 41), // "on_tableWidget_Ports_itemSele..."
QT_MOC_LITERAL(28, 465, 32), // "on_pushButton_Disconnect_clicked"
QT_MOC_LITERAL(29, 498, 32), // "on_pushButton_SendString_clicked"
QT_MOC_LITERAL(30, 531, 39), // "on_pushButton_ReadChuckPositi..."
QT_MOC_LITERAL(31, 571, 36), // "on_pushButton_StartSynchComm_..."
QT_MOC_LITERAL(32, 608, 31), // "on_pushButton_StopSynch_clicked"
QT_MOC_LITERAL(33, 640, 33), // "on_pushButton_MoveChuckXY_cli..."
QT_MOC_LITERAL(34, 674, 32), // "on_pushButton_MoveChuckZ_clicked"
QT_MOC_LITERAL(35, 707, 18), // "on_positionChanged"
QT_MOC_LITERAL(36, 726, 8), // "_posName"
QT_MOC_LITERAL(37, 735, 12), // "_newPosition"
QT_MOC_LITERAL(38, 748, 39), // "on_pushButton_StartStateMachi..."
QT_MOC_LITERAL(39, 788, 37), // "on_pushButtonStopStateMachine..."
QT_MOC_LITERAL(40, 826, 23), // "on_stateMachineFinished"
QT_MOC_LITERAL(41, 850, 29), // "on_stateMachineRunningChanged"
QT_MOC_LITERAL(42, 880, 8), // "_running"
QT_MOC_LITERAL(43, 889, 29), // "on_measurementPositionChanged"
QT_MOC_LITERAL(44, 919, 20), // "on_SynchCommFinished"
QT_MOC_LITERAL(45, 940, 12), // "on_Connected"
QT_MOC_LITERAL(46, 953, 11), // "isConnected"
QT_MOC_LITERAL(47, 965, 11), // "on_readData"
QT_MOC_LITERAL(48, 977, 9), // "_readData"
QT_MOC_LITERAL(49, 987, 20), // "on_proberInZPosition"
QT_MOC_LITERAL(50, 1008, 21), // "on_proberInXYPosition"
QT_MOC_LITERAL(51, 1030, 23), // "on_proberNotInZPosition"
QT_MOC_LITERAL(52, 1054, 24), // "on_proberNotInXYPosition"
QT_MOC_LITERAL(53, 1079, 20), // "on_bufferSizeChanged"
QT_MOC_LITERAL(54, 1100, 11), // "_bufferSize"
QT_MOC_LITERAL(55, 1112, 25), // "on_measurementControlData"
QT_MOC_LITERAL(56, 1138, 24), // "QList<QList<CPosition> >"
QT_MOC_LITERAL(57, 1163, 14), // "_positionTable"
QT_MOC_LITERAL(58, 1178, 12), // "_zFinalValue"
QT_MOC_LITERAL(59, 1191, 11), // "on_ErrorMsg"
QT_MOC_LITERAL(60, 1203, 12), // "_windowTitle"
QT_MOC_LITERAL(61, 1216, 11), // "_windowText"
QT_MOC_LITERAL(62, 1228, 13), // "on_WarningMsg"
QT_MOC_LITERAL(63, 1242, 17), // "on_InformationMsg"
QT_MOC_LITERAL(64, 1260, 28), // "on_MeasuredParameter_Changed"
QT_MOC_LITERAL(65, 1289, 5) // "index"

    },
    "CProberVisu\0addCommand\0\0_command\0"
    "startStateMachine\0stopStateMachine\0"
    "deleteMeasurementDevices\0measurementParam\0"
    "i\0paramNameInFileChanged\0_paramNameInFile\0"
    "zValuePrePos\0_zPreValue\0zValueFinalPos\0"
    "_zFinalPos\0changedPosition\0_row\0_column\0"
    "CPosition\0_pos\0requesMeasCtrlData\0"
    "changePositionStylesheet\0_stylesheet\0"
    "on_textEdit_ZPreValue_changed\0"
    "on_textEdit_ZFinalValue_changed\0"
    "on_pushButton_Search_clicked\0"
    "on_pushButton_Connect_clicked\0"
    "on_tableWidget_Ports_itemSelectionChanged\0"
    "on_pushButton_Disconnect_clicked\0"
    "on_pushButton_SendString_clicked\0"
    "on_pushButton_ReadChuckPosition_clicked\0"
    "on_pushButton_StartSynchComm_clicked\0"
    "on_pushButton_StopSynch_clicked\0"
    "on_pushButton_MoveChuckXY_clicked\0"
    "on_pushButton_MoveChuckZ_clicked\0"
    "on_positionChanged\0_posName\0_newPosition\0"
    "on_pushButton_StartStateMachine_clicked\0"
    "on_pushButtonStopStateMachine_clicked\0"
    "on_stateMachineFinished\0"
    "on_stateMachineRunningChanged\0_running\0"
    "on_measurementPositionChanged\0"
    "on_SynchCommFinished\0on_Connected\0"
    "isConnected\0on_readData\0_readData\0"
    "on_proberInZPosition\0on_proberInXYPosition\0"
    "on_proberNotInZPosition\0"
    "on_proberNotInXYPosition\0on_bufferSizeChanged\0"
    "_bufferSize\0on_measurementControlData\0"
    "QList<QList<CPosition> >\0_positionTable\0"
    "_zFinalValue\0on_ErrorMsg\0_windowTitle\0"
    "_windowText\0on_WarningMsg\0on_InformationMsg\0"
    "on_MeasuredParameter_Changed\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CProberVisu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      42,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  224,    2, 0x06 /* Public */,
       4,    0,  227,    2, 0x06 /* Public */,
       5,    0,  228,    2, 0x06 /* Public */,
       6,    0,  229,    2, 0x06 /* Public */,
       7,    1,  230,    2, 0x06 /* Public */,
       9,    1,  233,    2, 0x06 /* Public */,
      11,    1,  236,    2, 0x06 /* Public */,
      13,    1,  239,    2, 0x06 /* Public */,
      15,    3,  242,    2, 0x06 /* Public */,
      20,    0,  249,    2, 0x06 /* Public */,
      21,    1,  250,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    0,  253,    2, 0x08 /* Private */,
      24,    0,  254,    2, 0x08 /* Private */,
      25,    0,  255,    2, 0x0a /* Public */,
      26,    0,  256,    2, 0x0a /* Public */,
      27,    0,  257,    2, 0x0a /* Public */,
      28,    0,  258,    2, 0x0a /* Public */,
      29,    0,  259,    2, 0x0a /* Public */,
      30,    0,  260,    2, 0x0a /* Public */,
      31,    0,  261,    2, 0x0a /* Public */,
      32,    0,  262,    2, 0x0a /* Public */,
      33,    0,  263,    2, 0x0a /* Public */,
      34,    0,  264,    2, 0x0a /* Public */,
      35,    2,  265,    2, 0x0a /* Public */,
      38,    0,  270,    2, 0x0a /* Public */,
      39,    0,  271,    2, 0x0a /* Public */,
      40,    0,  272,    2, 0x0a /* Public */,
      41,    1,  273,    2, 0x0a /* Public */,
      43,    2,  276,    2, 0x0a /* Public */,
      44,    0,  281,    2, 0x0a /* Public */,
      45,    1,  282,    2, 0x0a /* Public */,
      47,    1,  285,    2, 0x0a /* Public */,
      49,    0,  288,    2, 0x0a /* Public */,
      50,    0,  289,    2, 0x0a /* Public */,
      51,    0,  290,    2, 0x0a /* Public */,
      52,    0,  291,    2, 0x0a /* Public */,
      53,    1,  292,    2, 0x0a /* Public */,
      55,    3,  295,    2, 0x0a /* Public */,
      59,    2,  302,    2, 0x0a /* Public */,
      62,    2,  307,    2, 0x0a /* Public */,
      63,    2,  312,    2, 0x0a /* Public */,
      64,    1,  317,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 18,   16,   17,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   22,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 18,   36,   37,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   42,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   16,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   46,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   54,
    QMetaType::Void, 0x80000000 | 56, QMetaType::Double, QMetaType::Double,   57,   12,   58,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   60,   61,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   60,   61,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   60,   61,
    QMetaType::Void, QMetaType::Int,   65,

       0        // eod
};

void CProberVisu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CProberVisu *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addCommand((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->startStateMachine(); break;
        case 2: _t->stopStateMachine(); break;
        case 3: _t->deleteMeasurementDevices(); break;
        case 4: _t->measurementParam((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->paramNameInFileChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->zValuePrePos((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->zValueFinalPos((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->changedPosition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< CPosition(*)>(_a[3]))); break;
        case 9: _t->requesMeasCtrlData(); break;
        case 10: _t->changePositionStylesheet((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->on_textEdit_ZPreValue_changed(); break;
        case 12: _t->on_textEdit_ZFinalValue_changed(); break;
        case 13: _t->on_pushButton_Search_clicked(); break;
        case 14: _t->on_pushButton_Connect_clicked(); break;
        case 15: _t->on_tableWidget_Ports_itemSelectionChanged(); break;
        case 16: _t->on_pushButton_Disconnect_clicked(); break;
        case 17: _t->on_pushButton_SendString_clicked(); break;
        case 18: _t->on_pushButton_ReadChuckPosition_clicked(); break;
        case 19: _t->on_pushButton_StartSynchComm_clicked(); break;
        case 20: _t->on_pushButton_StopSynch_clicked(); break;
        case 21: _t->on_pushButton_MoveChuckXY_clicked(); break;
        case 22: _t->on_pushButton_MoveChuckZ_clicked(); break;
        case 23: _t->on_positionChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< CPosition(*)>(_a[2]))); break;
        case 24: _t->on_pushButton_StartStateMachine_clicked(); break;
        case 25: _t->on_pushButtonStopStateMachine_clicked(); break;
        case 26: _t->on_stateMachineFinished(); break;
        case 27: _t->on_stateMachineRunningChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->on_measurementPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 29: _t->on_SynchCommFinished(); break;
        case 30: _t->on_Connected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->on_readData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 32: _t->on_proberInZPosition(); break;
        case 33: _t->on_proberInXYPosition(); break;
        case 34: _t->on_proberNotInZPosition(); break;
        case 35: _t->on_proberNotInXYPosition(); break;
        case 36: _t->on_bufferSizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->on_measurementControlData((*reinterpret_cast< QList<QList<CPosition> >(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 38: _t->on_ErrorMsg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 39: _t->on_WarningMsg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 40: _t->on_InformationMsg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 41: _t->on_MeasuredParameter_Changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CProberVisu::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CProberVisu::addCommand)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CProberVisu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CProberVisu::startStateMachine)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CProberVisu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CProberVisu::stopStateMachine)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CProberVisu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CProberVisu::deleteMeasurementDevices)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CProberVisu::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CProberVisu::measurementParam)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CProberVisu::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CProberVisu::paramNameInFileChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CProberVisu::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CProberVisu::zValuePrePos)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (CProberVisu::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CProberVisu::zValueFinalPos)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (CProberVisu::*)(int , int , CPosition );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CProberVisu::changedPosition)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (CProberVisu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CProberVisu::requesMeasCtrlData)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (CProberVisu::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CProberVisu::changePositionStylesheet)) {
                *result = 10;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CProberVisu::staticMetaObject = { {
    QMetaObject::SuperData::link<QTabWidget::staticMetaObject>(),
    qt_meta_stringdata_CProberVisu.data,
    qt_meta_data_CProberVisu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CProberVisu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CProberVisu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CProberVisu.stringdata0))
        return static_cast<void*>(this);
    return QTabWidget::qt_metacast(_clname);
}

int CProberVisu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 42)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 42;
    }
    return _id;
}

// SIGNAL 0
void CProberVisu::addCommand(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CProberVisu::startStateMachine()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CProberVisu::stopStateMachine()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CProberVisu::deleteMeasurementDevices()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void CProberVisu::measurementParam(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CProberVisu::paramNameInFileChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CProberVisu::zValuePrePos(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CProberVisu::zValueFinalPos(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void CProberVisu::changedPosition(int _t1, int _t2, CPosition _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void CProberVisu::requesMeasCtrlData()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void CProberVisu::changePositionStylesheet(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
