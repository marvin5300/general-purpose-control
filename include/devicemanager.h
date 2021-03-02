#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include "measurementdevice.h"
#include <QString>
#include <QPointer>
#include <QStringList>
#include <QStandardItemModel>

/** 
* @brief Holds all possible device names and creates objects of certain device types.
* Only device names and classes that are listed here will be available in the final program.
*/
class DeviceManager : public QObject
{
    Q_OBJECT

public:
    /**
    * Creates new device. Device class is chosen by deviceName.
    * @param deviceName name of the device
    * @param portName interface name of the device for example /dev/usb0
    * @return QPointer on created device
    */
    static QPointer<MeasurementDevice> getDevice(QString deviceName, QString portName);

    /**
    * List containing all possible device names.
    * To create new device classes they have to be added to this list and their deviceName must be similar.
    */
    static const QStringList deviceNameList;

    /**
    * List containing QPointer to all currently existing devices.
    */
    static QList<QPointer<MeasurementDevice> > activeDevicesList;

    /**
    * Checks if Pointer in activeDevicesList is null and removes nullpointer.
    */
    static void cleanupActiveDevicesList();

    /**
    * List containing all possible interface names. 
    * Created OS specific at beginning of the program.
    */
    static QStringList interfaceNameList;

    /**
    * Model that holds all unique names of devices currently active
    */
    static QPointer<QStandardItemModel> activeDeviceNameModel;

    /**
    * Model that holds all possible device names
    */
    static QPointer<QStandardItemModel> allDeviceNameModel;
    
    /**
    * Model that holds all possible interface names
    */
    static QPointer<QStandardItemModel> allInterfaceNameModel;

    /**
    * Removes a devices and deletes it from alle lists and models
    * @param device QPointer to device that should be deleted
    */
    static void removeDevice(QPointer<MeasurementDevice> device);

    /**
    * Updates the activeDeviceNameModel using the activeDeviceNameList.
    * Calls cleanupActiveDevicesList first before updating Model
    */
    static void actualizeDeviceNameModel();

    /**
    * accessor to activeDeviceNameModel
    */
    static QPointer<QStandardItemModel> getActiveDeviceNameModel();

    /**
    * accessor to allDeviceNameModel
    */
    static QPointer<QStandardItemModel> getAllDeviceNameModel();

    /**
    * accessor to allInterfaceNameModel
    */
    static QPointer<QStandardItemModel> getAllInterfaceNameModel();

    /**
    * Sets filter mask for interface ports.
    * Can be applied in Settings dialog.
    * @param masks List of all filters that should be applied to interface search.
    */
    static void setSerialMask(QStringList masks = _masks);

    /**
    * Creates list of interface port names using a filter mask
    * @param masks List of all filters that should be applied to interface search.
    */
    static void generateInterfaceList(QStringList masks = _masks);

    /**
    * List of all filters that should be applied to interface search.
    */
    static QStringList _masks;
};
#endif // DEVICEMANAGER_H
