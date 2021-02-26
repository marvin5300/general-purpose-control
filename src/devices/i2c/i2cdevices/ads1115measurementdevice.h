#ifndef ADS1115MEASUREMENTDEVICE_H
#define ADS1115MEASUREMENTDEVICE_H

#include <QObject>
#include <measurementdevice.h>
#include <src/devices/i2c/i2cdevices/ads1115/ads1115.h>

class Ads1115MeasurementDevice : public MeasurementDevice, ADS1115
{    Q_OBJECT

 signals:
     void scpiCommand(QString command);
 public:
     using MeasurementDevice::MeasurementDevice;
 public slots:
     void onReceivedMessage(QString message);
     void queueMeasure(quint64 number);
     void connectBus();
     void setScanParameter(MeasurementValue value);
     QMap<QString, DeviceParameterConstraint> deviceParamMap(){return _deviceParamMap;}
 protected:
     void init();
     const QString _deviceName = "ADS1115";
     //virtual const char terminator(){return static_cast<char>(0x0a);}
     //virtual QString translateMeas(QString paramName){return "";}
     //virtual QString translateSet(QString paramName){return "";}
     //virtual double translateInc(QString receivedString){return 0;}
     //virtual void setOutputState(bool on){}
     void measure();
     bool checkDevice(QString message);
     void connectSerial(QString _interfaceName, quint32 _baudRate);
     static const QMap<QString, DeviceParameterConstraint> _deviceParamMap;
     quint64 measureID;
     QQueue<QString> activeMeasParams;
     QList<MeasurementValue> measureResults;
};

#endif // ADS1115MEASUREMENTDEVICE_H
