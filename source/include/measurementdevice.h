#ifndef MEASUREMENT_DEVICE_H
#define MEASUREMENT_DEVICE_H

#include "measurementparameter.h"
#include  <QFrame>
#include <QPointer>
#include <QMap>
#include <QStandardItemModel>
#include <QLayout>
#include <QMouseEvent>

namespace Ui {
class MeasurementDevice;
}

/**
* @brief Abstract class that represents a device on the gui.
* This is an abstract class not meant to live on its own but only to be inherited from.
* A device can have variable interfaces like uart, spi or i2c.
* It is all about its device parameters, which define what kind of
* parameters the device can measure or set.
*/
class MeasurementDevice : public QFrame
{
    Q_OBJECT

signals:
    /**
    * Tells interface to close connection.
    * (Interface can be anything like SPI, I2C, UART etc.)
    */
    void closeConnection();

    /**
    * Tells for example the mainwindow that the user selected a different device.
    * Usually this object will then get replaced by an object of the new type.
    * @param device this devices name
    * @param _newDeviceName the string selected in device name dropbox
    * @param _newInterfaceName the string selected in interface name dropbox
    */
    void deviceSelectionChange(QPointer<MeasurementDevice> device, QString _newDeviceName, QString _newInterfaceName);

    /**
    * Sends list of measured values, the deviceName and the event number.
    * @param deviceName this devices name
    * @param values list of measured values
    * @param number event ID
    */
    void measuredValues(QString deviceName, QList<MeasurementValue> values, quint64 number);

    /**
    * Signals that the measurement is ready.
    * @param deviceName this devices name
    * @param number event ID
    */
    void measureReady(QString deviceName, quint64 number);

    /**
    * Signals that the set ramp parameter is set correctly.
    * @param deviceName this devices name
    * @param number event ID
    */
    void scanParameterReady(QString deviceName, quint64 number);

public:

    /**
    * Constructor of MeasurementDevice class.
    * Needs an interface name like /dev/usb0 or COM0 for linux/windows respectively.
    * Also a baudrate is set.
    * @param _interfaceName the name of the initial interface (for example /dev/usb0)
    */
    explicit MeasurementDevice(QString _interfaceName, quint32 _baudRate = 9600, QWidget *parent = 0);

    /**
    * Destructor of MeasurementDevice
    */
    ~MeasurementDevice();

    /**
    * Returns the parameter constraints (which parameters the device can measure or set).
    * Abstract function, will be different for each child.
    * @return map with device parameter constraints
    */
    virtual const QMap<QString,DeviceParameterConstraint> getDeviceParameterConstraints()const = 0;

    /**
    * Returns the interface name of the device, for example /dev/usb0.
    * Abstract function, will return different for each child. (does it have to be virtual?)
    * @return interface name
    */
    virtual const QString getInterfaceName()const = 0;

    /**
    * Returns the device name of the device, for example MODEL2000.
    * Abstract function, will return different for each child. (does it have to be virtual?)
    * @return device name
    */
    virtual const QString deviceName() = 0;
    
     
    /**
    * Returns the id of this device.
    * On each new MeasurementDevice initialization the counter will be counted up.
    * This makes each device unique. Not in use right now.
    * @return unique id of the device
    */
    quint64 getLocalId()const;

    /**
    * Reference to the layout this widget sits in.
    * Used to move the widget inside its layout when drag and drop.
    */
    QPointer<QHBoxLayout> layout;

    /**
    * Tells the MeasurementDevice to write a certain value to an output.
    * For example: tells Keithley_2410 to set Voltage output to 200V.
    * @param value parameter to be set to a value value
    */
    virtual void setScanParameter(MeasurementValue value) = 0;

    void switchOutputOff(void);

public slots:
    /**
    * Called when the interface got a message from the physical device.
    * Will contain messages directly from the physical device, for example a current measurement in the form of "0.5A"
    * Abstract function: this function has no definition yet, it is heavily dependend on the type of device.
    * @param message received message
    */
    virtual void onReceivedMessage(QString message) = 0;

    /**
    * Tells the MeasurementDevice to queue a measurement.
    * It will then somehow tell the physical device what to do and perform measurements.
    * Abstract function: heavily dependent on type of interface and device.
    * @param count event ID of measurement
    */
    virtual void queueMeasure(quint64 count) = 0;

    /**
    * Tells the MeasurementDevice to connect to the interface.
    * Will be called when interface selection changes.
    * Abstract function: heavily dependent on type of interface
    */
    virtual void connectBus() = 0;

    /**
    * Called when interface reports connection status change.
    * @param connected new connection state
    */
    void onConnectionStatusChanged(bool connected);

    /**
    * Changes UI colors depending on connection state.
    * @param connected new connection state
    */
    void setUiConnectionState(bool connected);

    /**
    * Called when interface selection dropbox changes selection.
    * @param _interfaceName new interface name to be set
    */
    void onInterfaceSelectionChanged(QString _interfaceName);

    /**
    * Closes the device.
    */
    void exit();

    /**
     * set checkackable parameter for device, if prameter exists
     * @retval: 0 = succeed; 1 = failed (no parameter found)
     */
    unsigned int setMeasureParam(DeviceParameterConstraint _parameterConstraint);

protected:
    /**
    * Initialises the device.
    * Abstract function: Sets device specific things
    * and should then call the device independent init which is defined in MeasurementDevice.
    */
    virtual void init() = 0;

    /**
    * Initialises the device.
    * Primarily sets ui stuff and the parameter constraints.
    * @param deviceName this devices name
    * @param _interfaceName this devices interface name
    * @param constraintsMap this devices constraints map
    */
    void init(QString deviceName, QString _interfaceName,
              QMap<QString,DeviceParameterConstraint> constraintsMap = QMap<QString,DeviceParameterConstraint>());

    /**
    * Called when device selection dropbox changes selection.
    */
    void onDeviceSelectionChanged(QString _newDeviceName);

    /**
    * Name of the interface for example '/dev/usb0'
    */
    QString interfaceName;

    /**
    * baudrate value, default 9600
    */
    quint32 baudRate;

    /**
    * Unique identifier for the device.
    */
    quint64 localId = 0;

    /**
    * Counts up globally for each initialised MeasurementDevice
    */
    static quint64 globalIdCounter;

    /**
    * Gets set to true after checking the correctness of the connected device.
    * Usually checked directly after connecting.
    */
    bool correctDeviceConnected = false;

    /**
    * The ui of MeasurementDevice. See Qt documentation for more information.
    */
    Ui::MeasurementDevice *ui;

    /// enable drag drop of widget
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
