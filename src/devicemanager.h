#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include "devices/keithley_2000.h"
#include "devices/keithley_2410.h"
#include <QString>
#include <QPointer>
#include <QStringList>
#include <QStandardItemModel>

// since "inline" is only available from C++17 or newer this is the main set of functions to fill comboboxes
// deviceNameList and getDevice hold all device names and information about how to initialise
// the models can be generated at will and should contain valid device names and port names.
// Should be enough to edit them here
namespace DeviceManager {
    QPointer<MeasurementDevice> getDevice(QString deviceName, QString portName);
    static const QStringList deviceNameList({
                                               "MODULE 2000",
                                               "MODULE 2410"
                                            });
    static QList<QPointer<MeasurementDevice> > activeDevicesList;   // holds all devices currently active
    static QStringList ports;
    static QPointer<QStandardItemModel> activeDeviceNameModel;
    static bool setDevicePort(QString deviceName, QString oldPortName, QString newPortName);
    QPointer<QStandardItemModel> getDeviceNameModel();
    QPointer<QStandardItemModel> getPortNameModel();
    void generatePortList();
}
#endif // DEVICEMANAGER_H
