#ifndef DSA1030A_H
#define DSA1030A_H

#include "devices/scpidevice.h"

class RIGOL_DSA1030A : public ScpiDevice
{
    Q_OBJECT

public:
    explicit RIGOL_DSA1030A(QString _interfaceName, quint32 _baudRate = 9600, QWidget *parent = 0);
    const QMap<QString,DeviceParameterConstraint> getDeviceParameterConstraints()const;
    const QString getInterfaceName()const;
    const QString deviceName() {return _deviceName;}

private:
    void init();
    const QString _deviceName = "RIGOL DSA1030A";
    static const QMap<QString, DeviceParameterConstraint> _deviceParamMap;
    QMap<QString, DeviceParameterConstraint> deviceParamMap(){return _deviceParamMap;}
    QMap<QString, MeasurementValue> valuesMap;
};

#endif // DSA1030A_H
