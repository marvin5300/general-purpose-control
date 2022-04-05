#ifndef SOURCETRONIC_ST2819A_H
#define SOURCETRONIC_ST2819A_H

#include <devices/scpidevice.h>

class SourceTronic_ST2819A : public ScpiDevice
{
    Q_OBJECT

public:
    explicit SourceTronic_ST2819A(QString _interfaceName, quint32 _baudRate = 9600, QWidget *parent = nullptr);
    const QMap<QString,DeviceParameterConstraint> getDeviceParameterConstraints()const;
    const QString getInterfaceName()const;
    const QString deviceName() {return _deviceName;}
    public slots:
    //void onReceivedMessage(QString message);

private:
    void init();
    const QString _deviceName = "ST2819A";
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
#endif // SOURCETRONIC_ST2819A_H
