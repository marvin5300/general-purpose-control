/****************************************************************************
** Meta object code from reading C++ file 'cmeasurementcontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../include/cmeasurementcontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cmeasurementcontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CMeasurementControl_t {
    QByteArrayData data[63];
    char stringdata0[1015];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CMeasurementControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CMeasurementControl_t qt_meta_stringdata_CMeasurementControl = {
    {
QT_MOC_LITERAL(0, 0, 19), // "CMeasurementControl"
QT_MOC_LITERAL(1, 20, 18), // "requestMoveChuckXY"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 5), // "_xPos"
QT_MOC_LITERAL(4, 46, 5), // "_yPos"
QT_MOC_LITERAL(5, 52, 7), // "_posRef"
QT_MOC_LITERAL(6, 60, 5), // "_unit"
QT_MOC_LITERAL(7, 66, 9), // "_velocity"
QT_MOC_LITERAL(8, 76, 17), // "requestMoveChuckZ"
QT_MOC_LITERAL(9, 94, 5), // "_zPos"
QT_MOC_LITERAL(10, 100, 19), // "requestReadChuckPos"
QT_MOC_LITERAL(11, 120, 15), // "_readChukPosCmd"
QT_MOC_LITERAL(12, 136, 19), // "continueMeasurement"
QT_MOC_LITERAL(13, 156, 17), // "finishMeasurement"
QT_MOC_LITERAL(14, 174, 13), // "requestZValue"
QT_MOC_LITERAL(15, 188, 6), // "_index"
QT_MOC_LITERAL(16, 195, 19), // "requestInXYPosition"
QT_MOC_LITERAL(17, 215, 18), // "requestInZPosition"
QT_MOC_LITERAL(18, 234, 7), // "warning"
QT_MOC_LITERAL(19, 242, 12), // "_windowTitle"
QT_MOC_LITERAL(20, 255, 11), // "_windowText"
QT_MOC_LITERAL(21, 267, 11), // "information"
QT_MOC_LITERAL(22, 279, 26), // "stateMachineRunningChanged"
QT_MOC_LITERAL(23, 306, 8), // "_running"
QT_MOC_LITERAL(24, 315, 22), // "measurePositionChanged"
QT_MOC_LITERAL(25, 338, 4), // "_row"
QT_MOC_LITERAL(26, 343, 7), // "_column"
QT_MOC_LITERAL(27, 351, 16), // "startMeasurement"
QT_MOC_LITERAL(28, 368, 16), // "informationPopUp"
QT_MOC_LITERAL(29, 385, 10), // "createFile"
QT_MOC_LITERAL(30, 396, 9), // "_filename"
QT_MOC_LITERAL(31, 406, 19), // "measurementFinished"
QT_MOC_LITERAL(32, 426, 22), // "measurementControlData"
QT_MOC_LITERAL(33, 449, 24), // "QList<QList<CPosition> >"
QT_MOC_LITERAL(34, 474, 13), // "_positionList"
QT_MOC_LITERAL(35, 488, 10), // "_zPreValue"
QT_MOC_LITERAL(36, 499, 12), // "_zFinalValue"
QT_MOC_LITERAL(37, 512, 15), // "stopMeasurement"
QT_MOC_LITERAL(38, 528, 20), // "on_moveToPrePosition"
QT_MOC_LITERAL(39, 549, 24), // "on_moveToMeasurePosition"
QT_MOC_LITERAL(40, 574, 19), // "on_startMeasurement"
QT_MOC_LITERAL(41, 594, 17), // "on_machineStarted"
QT_MOC_LITERAL(42, 612, 11), // "on_s2Exited"
QT_MOC_LITERAL(43, 624, 14), // "on_increaseRow"
QT_MOC_LITERAL(44, 639, 11), // "on_s3Exited"
QT_MOC_LITERAL(45, 651, 25), // "on_checkMeasurementStatus"
QT_MOC_LITERAL(46, 677, 20), // "on_timeoutCycReadPos"
QT_MOC_LITERAL(47, 698, 23), // "on_stateMachineFinished"
QT_MOC_LITERAL(48, 722, 20), // "on_startStateMachine"
QT_MOC_LITERAL(49, 743, 19), // "on_stopStateMachine"
QT_MOC_LITERAL(50, 763, 17), // "on_runningChanged"
QT_MOC_LITERAL(51, 781, 23), // "on_parameterNameChanged"
QT_MOC_LITERAL(52, 805, 14), // "_parameterName"
QT_MOC_LITERAL(53, 820, 22), // "on_zValuePrePosChanged"
QT_MOC_LITERAL(54, 843, 7), // "_zValue"
QT_MOC_LITERAL(55, 851, 24), // "on_zValueFinalPosChanged"
QT_MOC_LITERAL(56, 876, 18), // "on_positionChanged"
QT_MOC_LITERAL(57, 895, 9), // "CPosition"
QT_MOC_LITERAL(58, 905, 4), // "_pos"
QT_MOC_LITERAL(59, 910, 32), // "on_requestMeasurementControlData"
QT_MOC_LITERAL(60, 943, 28), // "on_ongoingMeasurementChanged"
QT_MOC_LITERAL(61, 972, 19), // "_ongoingMeasurement"
QT_MOC_LITERAL(62, 992, 22) // "on_measurementFinished"

    },
    "CMeasurementControl\0requestMoveChuckXY\0"
    "\0_xPos\0_yPos\0_posRef\0_unit\0_velocity\0"
    "requestMoveChuckZ\0_zPos\0requestReadChuckPos\0"
    "_readChukPosCmd\0continueMeasurement\0"
    "finishMeasurement\0requestZValue\0_index\0"
    "requestInXYPosition\0requestInZPosition\0"
    "warning\0_windowTitle\0_windowText\0"
    "information\0stateMachineRunningChanged\0"
    "_running\0measurePositionChanged\0_row\0"
    "_column\0startMeasurement\0informationPopUp\0"
    "createFile\0_filename\0measurementFinished\0"
    "measurementControlData\0QList<QList<CPosition> >\0"
    "_positionList\0_zPreValue\0_zFinalValue\0"
    "stopMeasurement\0on_moveToPrePosition\0"
    "on_moveToMeasurePosition\0on_startMeasurement\0"
    "on_machineStarted\0on_s2Exited\0"
    "on_increaseRow\0on_s3Exited\0"
    "on_checkMeasurementStatus\0"
    "on_timeoutCycReadPos\0on_stateMachineFinished\0"
    "on_startStateMachine\0on_stopStateMachine\0"
    "on_runningChanged\0on_parameterNameChanged\0"
    "_parameterName\0on_zValuePrePosChanged\0"
    "_zValue\0on_zValueFinalPosChanged\0"
    "on_positionChanged\0CPosition\0_pos\0"
    "on_requestMeasurementControlData\0"
    "on_ongoingMeasurementChanged\0"
    "_ongoingMeasurement\0on_measurementFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMeasurementControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      40,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      20,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,  214,    2, 0x06 /* Public */,
       8,    4,  225,    2, 0x06 /* Public */,
      10,    1,  234,    2, 0x06 /* Public */,
      10,    0,  237,    2, 0x26 /* Public | MethodCloned */,
      12,    0,  238,    2, 0x06 /* Public */,
      13,    0,  239,    2, 0x06 /* Public */,
      14,    1,  240,    2, 0x06 /* Public */,
      14,    0,  243,    2, 0x26 /* Public | MethodCloned */,
      16,    0,  244,    2, 0x06 /* Public */,
      17,    0,  245,    2, 0x06 /* Public */,
      18,    2,  246,    2, 0x06 /* Public */,
      21,    2,  251,    2, 0x06 /* Public */,
      22,    1,  256,    2, 0x06 /* Public */,
      24,    2,  259,    2, 0x06 /* Public */,
      27,    0,  264,    2, 0x06 /* Public */,
      28,    2,  265,    2, 0x06 /* Public */,
      29,    1,  270,    2, 0x06 /* Public */,
      31,    0,  273,    2, 0x06 /* Public */,
      32,    3,  274,    2, 0x06 /* Public */,
      37,    0,  281,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      38,    0,  282,    2, 0x08 /* Private */,
      39,    0,  283,    2, 0x08 /* Private */,
      40,    0,  284,    2, 0x08 /* Private */,
      41,    0,  285,    2, 0x08 /* Private */,
      42,    0,  286,    2, 0x08 /* Private */,
      43,    0,  287,    2, 0x08 /* Private */,
      44,    0,  288,    2, 0x08 /* Private */,
      45,    0,  289,    2, 0x08 /* Private */,
      46,    0,  290,    2, 0x08 /* Private */,
      47,    0,  291,    2, 0x08 /* Private */,
      48,    0,  292,    2, 0x0a /* Public */,
      49,    0,  293,    2, 0x0a /* Public */,
      50,    1,  294,    2, 0x0a /* Public */,
      51,    1,  297,    2, 0x0a /* Public */,
      53,    1,  300,    2, 0x0a /* Public */,
      55,    1,  303,    2, 0x0a /* Public */,
      56,    3,  306,    2, 0x0a /* Public */,
      59,    0,  313,    2, 0x0a /* Public */,
      60,    1,  314,    2, 0x0a /* Public */,
      62,    0,  317,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,    7,
    QMetaType::Void, QMetaType::Double, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,    5,    6,    7,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   19,   20,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   19,   20,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   25,   26,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   19,   20,
    QMetaType::Void, QMetaType::QString,   30,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 33, QMetaType::Double, QMetaType::Double,   34,   35,   36,
    QMetaType::Void,

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
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, QMetaType::QString,   52,
    QMetaType::Void, QMetaType::Double,   54,
    QMetaType::Void, QMetaType::Double,   54,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 57,   25,   26,   58,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   61,
    QMetaType::Void,

       0        // eod
};

void CMeasurementControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CMeasurementControl *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->requestMoveChuckXY((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 1: _t->requestMoveChuckZ((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 2: _t->requestReadChuckPos((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->requestReadChuckPos(); break;
        case 4: _t->continueMeasurement(); break;
        case 5: _t->finishMeasurement(); break;
        case 6: _t->requestZValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->requestZValue(); break;
        case 8: _t->requestInXYPosition(); break;
        case 9: _t->requestInZPosition(); break;
        case 10: _t->warning((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->information((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: _t->stateMachineRunningChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->measurePositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->startMeasurement(); break;
        case 15: _t->informationPopUp((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 16: _t->createFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->measurementFinished(); break;
        case 18: _t->measurementControlData((*reinterpret_cast< QList<QList<CPosition> >(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 19: _t->stopMeasurement(); break;
        case 20: _t->on_moveToPrePosition(); break;
        case 21: _t->on_moveToMeasurePosition(); break;
        case 22: _t->on_startMeasurement(); break;
        case 23: _t->on_machineStarted(); break;
        case 24: _t->on_s2Exited(); break;
        case 25: _t->on_increaseRow(); break;
        case 26: _t->on_s3Exited(); break;
        case 27: _t->on_checkMeasurementStatus(); break;
        case 28: _t->on_timeoutCycReadPos(); break;
        case 29: _t->on_stateMachineFinished(); break;
        case 30: _t->on_startStateMachine(); break;
        case 31: _t->on_stopStateMachine(); break;
        case 32: _t->on_runningChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->on_parameterNameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 34: _t->on_zValuePrePosChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 35: _t->on_zValueFinalPosChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 36: _t->on_positionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< CPosition(*)>(_a[3]))); break;
        case 37: _t->on_requestMeasurementControlData(); break;
        case 38: _t->on_ongoingMeasurementChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 39: _t->on_measurementFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CMeasurementControl::*)(double , double , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMeasurementControl::requestMoveChuckXY)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CMeasurementControl::*)(double , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMeasurementControl::requestMoveChuckZ)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CMeasurementControl::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMeasurementControl::requestReadChuckPos)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CMeasurementControl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMeasurementControl::continueMeasurement)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CMeasurementControl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMeasurementControl::finishMeasurement)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CMeasurementControl::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMeasurementControl::requestZValue)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (CMeasurementControl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMeasurementControl::requestInXYPosition)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (CMeasurementControl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMeasurementControl::requestInZPosition)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (CMeasurementControl::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMeasurementControl::warning)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (CMeasurementControl::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMeasurementControl::information)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (CMeasurementControl::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMeasurementControl::stateMachineRunningChanged)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (CMeasurementControl::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMeasurementControl::measurePositionChanged)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (CMeasurementControl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMeasurementControl::startMeasurement)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (CMeasurementControl::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMeasurementControl::informationPopUp)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (CMeasurementControl::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMeasurementControl::createFile)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (CMeasurementControl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMeasurementControl::measurementFinished)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (CMeasurementControl::*)(QList<QList<CPosition>> , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMeasurementControl::measurementControlData)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (CMeasurementControl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMeasurementControl::stopMeasurement)) {
                *result = 19;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CMeasurementControl::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CMeasurementControl.data,
    qt_meta_data_CMeasurementControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CMeasurementControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMeasurementControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CMeasurementControl.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CMeasurementControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 40)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 40;
    }
    return _id;
}

// SIGNAL 0
void CMeasurementControl::requestMoveChuckXY(double _t1, double _t2, QString _t3, QString _t4, QString _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CMeasurementControl::requestMoveChuckZ(double _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CMeasurementControl::requestReadChuckPos(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 4
void CMeasurementControl::continueMeasurement()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void CMeasurementControl::finishMeasurement()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void CMeasurementControl::requestZValue(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 8
void CMeasurementControl::requestInXYPosition()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void CMeasurementControl::requestInZPosition()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void CMeasurementControl::warning(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void CMeasurementControl::information(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void CMeasurementControl::stateMachineRunningChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void CMeasurementControl::measurePositionChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void CMeasurementControl::startMeasurement()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void CMeasurementControl::informationPopUp(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void CMeasurementControl::createFile(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void CMeasurementControl::measurementFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void CMeasurementControl::measurementControlData(QList<QList<CPosition>> _t1, double _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void CMeasurementControl::stopMeasurement()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
