#ifndef MEASUREMENT_DEVICE_H
#define MEASUREMENT_DEVICE_H

#include <QFrame>

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
    void disconnectRS232(QString _interfaceName);
    void closeConnection();

public:
    explicit MeasurementDevice(QString _interfaceName, quint32 _baudRate = 9600, QWidget *parent = 0);
    ~MeasurementDevice();
    const QString deviceName;

public slots:
    virtual void onReceivedMessage(QString message); // this function has no definition yet, it is heavily dependend on the type of device
    void onConnectionStatusChanged(bool connected);
    void setInterface(QString _interfaceName);
    void exit();
    virtual const QString getInterfaceName() = 0;
    virtual const QString getDeviceName() = 0;
    virtual quint32 getLocalId();

protected:
    static quint64 globalIdCounter;
    quint64 localId = 0;
    void checkDevice(QString _deviceName, QString message);
    Ui::MeasurementDevice *ui;
    void connectRS232(QString _interfaceName, quint32 _baudRate);
    virtual void connectRS232() = 0;
    QString interfaceName;
    quint32 baudRate;
    bool correctDeviceConnected = false;
    void onDeviceSelectionChanged(QString _deviceName);
};

#endif // MEASUREMENT_DEVICE_H
