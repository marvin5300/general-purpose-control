#ifndef MEASUREMENTPARAMETER_H
#define MEASUREMENTPARAMETER_H
#include <QString>

enum AccessMode{NONE, READONLY, WRITEONLY, READWRITE};

struct DeviceParameterConstraint{
    DeviceParameterConstraint(QString _name, double _min_value,
                         double _max_value, AccessMode _mode){
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
    MeasurementValue(QString _name, double _value){
        name = _name;
        value = _value;
    }
    QString name;
    double value;
};

#endif // MEASUREMENTPARAMETER_H
