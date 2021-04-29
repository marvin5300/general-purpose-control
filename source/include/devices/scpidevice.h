#ifndef SCPIDEVICE_H_H
#define SCPIDEVICE_H_H

#include "measurementdevice.h"
#include <QDebug>
#include <QList>
#include <QQueue>

/**
* @brief Abstract class that provides basic functions for scpi devices.
* All devices that use the scpi protocol (commands look like ':TRIGer:SOURce EXTernal')
* should be inherited from this class. It provides basic functions to check if 
* the device connected is correct. It also uses uart over usb/rs232 and therefore
* the class "Serial".
*/
class ScpiDevice : public MeasurementDevice
{
    Q_OBJECT

signals:

    /**
    * Sends scpi command string (usually to the interface)
    * @param command sent scpi command string
    */
    void scpiCommand(QString command);
public:
    /**
    * Constructor of ScpiDevice is the same as MeasurementDevice
    */
    using MeasurementDevice::MeasurementDevice;
public slots:
    /**
    * Parses received scpi message.
    * Uses translateInc(QString message) function to parse message
    * and emits measuredValues and measureReady on finished measurement.
    * @param message received message
    */
    void onReceivedMessage(QString message);

    /**
    * For each checked measurment parameter (activeMeasParam) sends a measure string to interface.
    * Uses translateMeas function to create a device specific measurement string.
    * @param number event ID of measurment
    */
    void queueMeasure(quint64 number) override;

    /**
    * Calls connectSerial because scpi uses Serial connection.
    */
    void connectBus() override;

    /**
    * Sends a set value command to interface.
    * Uses translateSet to create a device specific measurement string to interface.
    * @param value parameter and value to be set
    */
    void setScanParameter(MeasurementValue value);
protected:
    /**
    * Map of all device parameter constraints
    */
    virtual QMap<QString, DeviceParameterConstraint> deviceParamMap() = 0;

    /**
    * EOL terminator char. LF (0x0a) or CR (0xd)
    * todo: more possible terminators like CR LF, LF CR etc.
    * Default is LF
    */
    virtual const char terminator(){return static_cast<char>(0x0a);}

    /**
    * Creates scpi message for measurement of paramName
    * @param paramName name of parameter to measure for example 'V' for voltage
    */
    virtual QString translateMeas(QString paramName){return "";}

    /**
    * Creates scpi message for setting of a parameter
    * @param paramName name of parameter to set for example 'V' for voltage
    */
    virtual QString translateSet(QString paramName, double paramValue){return "";}

    /**
    * Parses incoming scpi message to double.
    * @param receivedString message to be parsed
    */
    virtual double translateInc(QString receivedString){return 0;}
    virtual double translateInc1(QString receivedString){return 0;}
    /**
    * Checks if correct device is set.
    * Checks if answer to *IDN? contains deviceName()
    * @param message answer to *IDN? command
    * @return is correct device connected
    */
    bool checkDevice(QString message);

    /**
    * Starts a serial interface with port name and baudrate
    * @param _interfaceName name of the port to connect to
    * @param _baudRate baudrate of the interface
    */
    void connectSerial(QString _interfaceName, quint32 _baudRate);

    /**
    * map of all device parameter constraints
    */
    static const QMap<QString, DeviceParameterConstraint> _deviceParamMap;

    /**
    * current measurement event ID
    */
    quint64 measureID;

    /**
    * Contains checked measurement parameters.
    * (Parameters that should be measured when measurement is requested)
    */
    QQueue<QString> activeMeasParams;

    /**
    * Contains all current measurement results of the active measurement ID.
    */
    QList<MeasurementValue> measureResults;
};

#endif // SCPIDEVICE_H_H
