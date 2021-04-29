#ifndef MEASUREMENTPARAMETER_H
#define MEASUREMENTPARAMETER_H
#include <QString>
#include <QStringList>
//#include "ui_measurementdevice.h"

enum AccessMode{NONE, READONLY, WRITEONLY, READWRITE};
static const QStringList accessModeStrings({"NONE", "READONLY", "WRITEONLY", "READWRITE"}); // mode > 1 has write access
static const QStringList deviceParameterConstraintsHeaderStrings({"Name", "AccessMode", "Min", "Max"});

/**
* @brief Parameters in a device like U,I,C
*/
struct DeviceParameterConstraint{
    DeviceParameterConstraint(QString _name="", double _min_value=.0,
                         double _max_value=.0, AccessMode _mode=NONE){
        name = _name;
        min_value = _min_value;
        max_value = _max_value;
        mode = _mode;
    }
    QString name;
    double min_value;
    double max_value;
    AccessMode mode;
};

/**
* @brief One measured value with parameter label
*/
struct MeasurementValue{
    MeasurementValue(QString _name="", double _value=0.0, double _value1=0.0){
        name = _name;
        value = _value;
        value1 = _value1;
    }
    QString name;
    double value;
    double value1;
};

#endif // MEASUREMENTPARAMETER_H
