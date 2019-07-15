#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include "measurementdevice.h"
#include <QString>
#include <QPointer>
#include <QStringList>
#include <QStandardItemModel>

// since "inline" is only available from C++17 or newer this is the main set of functions to fill comboboxes
// deviceNameList and getDevice hold all device names and information about how to initialise
// the models can be generated at will and should contain valid device names and port names.
// Should be enough to edit them here
class DeviceManager : public QObject
{
    Q_OBJECT

public:
    static QPointer<MeasurementDevice> getDevice(QString deviceName, QString portName);
    static const QStringList deviceNameList;
    static QList<QPointer<MeasurementDevice> > activeDevicesList;   // holds all devices currently active
    static void cleanupActiveDevicesList();
    static QStringList interfaceNameList;
    static QPointer<QStandardItemModel> activeDeviceNameModel;
    static QPointer<QStandardItemModel> allDeviceNameModel;
    static QPointer<QStandardItemModel> allInterfaceNameModel;
    static void removeDevice(QPointer<MeasurementDevice> device);
    static QPointer<QStandardItemModel> getActiveDeviceNameModel();
    //QPointer<QStandardItemModel> getPortNameModel();
    static QPointer<QStandardItemModel> getAllDeviceNameModel();
    static QPointer<QStandardItemModel> getAllInterfaceNameModel();
    static void generateInterfaceList();
    static void actualizeDeviceNameModel();
};
#endif // DEVICEMANAGER_H
