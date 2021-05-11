#ifndef KEITHLEY_2410_H
#define KEITHLEY_2410_H

#include "devices/scpidevice.h"

class Keithley_2410 : public ScpiDevice
{
    Q_OBJECT

public:
    explicit Keithley_2410(QString _interfaceName, quint32 _baudRate = 9600, QWidget *parent = 0);
    const QMap<QString,DeviceParameterConstraint> getDeviceParameterConstraints()const;
    const QString getInterfaceName()const;
    const QString deviceName() {return _deviceName;}
public slots:
    //void onReceivedMessage(QString message);
private:
    void init();
    const QString _deviceName = "2410";
    static const QMap<QString, DeviceParameterConstraint> _deviceParamMap;
    static const char _terminator;
    QMap<QString, DeviceParameterConstraint> deviceParamMap(){return _deviceParamMap;}
    QMap<QString, MeasurementValue> valuesMap;
    QString translateMeas(QString paramName);
    QString translateSet(QString paramName, double paramValue);
    double translateInc(QString receivedString);
    double translateInc1(QString receivedString);
    void setOutputState(bool on);
    bool _outputOn = false;
};

#endif // KEITHLEY_2410_H
