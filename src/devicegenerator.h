#ifndef DEVICEGENERATOR_H
#define DEVICEGENERATOR_H

#include "keithley_2000.h"
#include "keithley_2410.h"
#include <QString>
#include <QPointer>
#include <QStringList>
#include <QStandardItemModel>

namespace DeviceGenerator {
    QPointer<MeasurementDevice> getDevice(QString deviceName);
    static const QStringList deviceNameList({
                                               "MODULE 2000",
                                               "MODULE 2410"
                                            });
    static QStringList ports;
    static QPointer<QStandardItemModel> deviceNameModel;
    static QPointer<QStandardItemModel> portNameModel;
    QPointer<QStandardItemModel> getDeviceNameModel();
    QPointer<QStandardItemModel> getPortNameModel();
    void generatePortList();
}
#endif // DEVICEGENERATOR_H
