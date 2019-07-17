#ifndef MEASUREMENT_DEVICE_H
#define MEASUREMENT_DEVICE_H

#include <QFrame>
#include "measurementparameter.h"
#include <QPointer>
#include <QMap>
#include <QStandardItemModel>

// this class is made assuming all devices use rs232 serial connection on scpi message base
// this is an abstract function not meant to live on its own but only to be inherited from

// basic communication like "*IDN?" command and everything that does not change for different
// devices are baked fix in here
namespace Ui {
class MeasurementDevice;
}

class MeasurementDevice : public QFrame
{
    Q_OBJECT

signals:
    void scpiCommand(QString command);
    void closeConnection();
    void deviceSelectionChange(QPointer<MeasurementDevice> device, QString _newDeviceName, QString _newInterfaceName);

public:
    explicit MeasurementDevice(QString _interfaceName, quint32 _baudRate = 9600, QWidget *parent = 0);
    ~MeasurementDevice();
    const QString deviceName;
    virtual const QMap<QString,DeviceParameterConstraint> getDeviceParameterConstraints()const = 0;
    virtual const QString getInterfaceName()const = 0;
    virtual const QString getDeviceName()const = 0;
    virtual quint64 getLocalId()const;

public slots:
    virtual void onReceivedMessage(QString message); // this function has no definition yet, it is heavily dependend on the type of device
    void setUiConnectionState(bool connected);
    void onConnectionStatusChanged(bool connected);
    virtual void onInterfaceSelectionChanged(QString _interfaceName);
    void exit();

protected:
    void init(QString deviceName, QString _interfaceName);
    virtual void init() = 0;
    static quint64 globalIdCounter;
    quint64 localId = 0;
    virtual void checkDevice(QString message);
    Ui::MeasurementDevice *ui;
    void connectRS232(QString _interfaceName, quint32 _baudRate);
    virtual void connectRS232() = 0;
    QString interfaceName;
    quint32 baudRate;
    bool correctDeviceConnected = false;
    void onDeviceSelectionChanged(QString _newDeviceName);
};

#endif // MEASUREMENT_DEVICE_H
