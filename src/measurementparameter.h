#ifndef MEASUREMENTPARAMETER_H
#define MEASUREMENTPARAMETER_H
#include <QString>
#include <QStringList>
//#include "ui_measurementdevice.h"

enum AccessMode{NONE, READONLY, WRITEONLY, READWRITE};
static const QStringList accessModeStrings({"NONE", "READONLY", "WRITEONLY", "READWRITE"}); // mode > 1 has write access
static const QStringList deviceParameterConstraintsHeaderStrings({"Name", "AccessMode", "Min", "Max"});

struct DeviceParameterConstraint{
    DeviceParameterConstraint(QString _name="", double _min_value=.0,
                         double _max_value=.0, AccessMode _mode=NONE){
        name = _name;
        mode = _mode;
        min_value = _min_value;
        max_value = _max_value;
    }
    double min_value;
    double max_value;
    QString name;
    AccessMode mode;
};

struct MeasurementValue{
    MeasurementValue(QString _name="", double _value=0.0){
        name = _name;
        value = _value;
    }
    QString name;
    double value;
};

#endif // MEASUREMENTPARAMETER_H
