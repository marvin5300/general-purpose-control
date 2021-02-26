#ifndef MEASUREMENT_DEVICE_H
#define MEASUREMENT_DEVICE_H

#include <measurementparameter.h>
#include <QFrame>
#include <QPointer>
#include <QMap>
#include <QStandardItemModel>
#include <QLayout>
#include <QMouseEvent>

// this class is made assuming all devices use rs232 serial connection on scpi message base
// this is an abstract class not meant to live on its own but only to be inherited from

// basic communication like "*IDN?" command and everything that does not change for different
// devices are baked fix in here
namespace Ui {
class MeasurementDevice;
}

class MeasurementDevice : public QFrame
{
    Q_OBJECT

signals:
    void closeConnection();
    void deviceSelectionChange(QPointer<MeasurementDevice> device, QString _newDeviceName, QString _newInterfaceName);
    void measuredValues(QString deviceName, QList<MeasurementValue> values, quint64 number);
    void measureReady(QString deviceName, quint64 number);
    void scanParameterReady(QString deviceName, quint64 number);

public:
    explicit MeasurementDevice(QString _interfaceName, quint32 _baudRate = 9600, QWidget *parent = 0);
    ~MeasurementDevice();
    virtual const QMap<QString,DeviceParameterConstraint> getDeviceParameterConstraints()const = 0;
    virtual const QString getInterfaceName()const = 0;
    virtual const QString deviceName() = 0;
    quint64 getLocalId()const;
    QPointer<QHBoxLayout> layout;
    virtual void setScanParameter(MeasurementValue value) = 0;

public slots:
    virtual void onReceivedMessage(QString message) = 0; // this function has no definition yet, it is heavily dependend on the type of device
    virtual void queueMeasure(quint64 count) = 0;
    virtual void connectBus() = 0;
    void onConnectionStatusChanged(bool connected);
    void setUiConnectionState(bool connected);
    void onInterfaceSelectionChanged(QString _interfaceName);
    void exit();

protected:
    virtual void init() = 0;
    void init(QString deviceName, QString _interfaceName,
              QMap<QString,DeviceParameterConstraint> constraintsMap = QMap<QString,DeviceParameterConstraint>());
    void onDeviceSelectionChanged(QString _newDeviceName);
    QString interfaceName;
    quint32 baudRate;
    quint64 localId = 0;
    static quint64 globalIdCounter;
    bool correctDeviceConnected = false;

    Ui::MeasurementDevice *ui;

    // enable drag drop of widget
    enum MoveDirection{MoveLeft,MoveRight,MoveUp,MoveDown};
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    bool isMinimumDistanceRiched(QMouseEvent *event);
    bool moveInLayout(QWidget *widget, MoveDirection direction);
    QPoint dragStartPosition;
    int oldX = 0;
    int oldY = 0;
    int mouseClickX = 0;
    int mouseClickY = 0;
};

#endif // MEASUREMENT_DEVICE_H
