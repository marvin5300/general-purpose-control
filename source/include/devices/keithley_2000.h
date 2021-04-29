#ifndef KEITHLEY_2000_H
#define KEITHLEY_2000_H

#include "devices/scpidevice.h"

/* Connection: serial over RS-232
 * Supported baudrates: 19.2k; 9600; 4800; 2400; 1200; 600; 300
 * no flow control
 * Software flow control is in the form of X__ON and X__OFF characters and is enabled when
XonXoFF is selected from the RS232 FLOW menu. When the input queue of the Model 2000
becomes more than 3/4 full, the instrument issues an X_OFF command. The control program
should respond to this and stop sending characters until the Model 2000 issues the X_ON, which
it will do once its input buffer has dropped below half-full. The Model 2000 recognizes X_ON
and X_OFF sent from the controller. An X_OFF will cause the Model 2000 to stop outputting
characters until it sees an X_ON. Incoming commands are processed after the <CR> character
is received from the controller.
 *
 * The Model 2000 can be configured to terminate each program message that it transmits to the
controller with any combination of <CR> and <LF>. Perform the following steps to set the
terminator:
1.
Access the RS-232 configuration by pressing SHIFT and then RS232.
You see: RS 232: ON (assuming you have already selected the RS-232 interface).
 *
 *
*/
class Keithley_2000 : public ScpiDevice
{
    Q_OBJECT

public:
    explicit Keithley_2000(QString _interfaceName, quint32 _baudRate = 9600, QWidget *parent = 0);
    const QMap<QString,DeviceParameterConstraint> getDeviceParameterConstraints()const;
    const QString getInterfaceName()const;
    const QString deviceName() {return _deviceName;}
    public slots:

private:
    void init();
    const QString _deviceName = "MODEL 2000";
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

#endif // KEITHLEY_2000_H
