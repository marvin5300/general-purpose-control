#ifndef GW_INSTEK_GPD4303S_H
#define GW_INSTEK_GPD4303S_H

#include "devices/scpidevice.h"

class GW_INSTEK_GPD4303S : public ScpiDevice
{
    Q_OBJECT

public:
    explicit GW_INSTEK_GPD4303S(QString _interfaceName, quint32 _baudRate = 9600, QWidget *parent = nullptr);
    const QMap<QString,DeviceParameterConstraint> getDeviceParameterConstraints()const;
    const QString getInterfaceName()const;
    const QString deviceName() {return _deviceName;}

private:
    void init();
    const QString _deviceName = "GPD-4303S";
    static const QMap<QString, DeviceParameterConstraint> _deviceParamMap;
    static const char _terminator;
    //const char terminator() {return _terminator;}
    QMap<QString, DeviceParameterConstraint> deviceParamMap(){return _deviceParamMap;}
    QMap<QString, MeasurementValue> valuesMap;
    QString translateSet(QString paramName);
    QString translateMeas(QString paramName);
    double translateInc(QString receivedString);
    void setOutputState(bool on);
    bool _outputOn = false;
};
#endif // GW_INSTEK_GPD4303S_H
