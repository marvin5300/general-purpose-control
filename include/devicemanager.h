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
    static void setSerialMask(QStringList masks = _masks);
    static void generateInterfaceList(QStringList masks = _masks);
    static void actualizeDeviceNameModel();
    static QStringList _masks;
};
#endif // DEVICEMANAGER_H
