#include "devicemanager.h"

namespace DeviceManager {
    QPointer<MeasurementDevice> getDevice(QString deviceName, QString portName){
        QPointer<MeasurementDevice> device;
        if (deviceName == "default"){
            if (!ports.empty()){
                device = new Keithley_2000(ports.at(0));
            }else {
                device = new Keithley_2000("COM1");
            }
        }
        if (deviceName == deviceNameList.at(0)){
            device = new Keithley_2000(portName);
        }
        if (deviceName == deviceNameList.at(1)){
            device = new Keithley_2410(portName);
        }
        activeDevicesList.append(device);
        return device;
    }

    bool setDevicePort(QString deviceName, QString oldPortName, QString newPortName){
        for (auto device : activeDevicesList){
            if ((device->deviceName == deviceName) && device->getPortName() == oldPortName){
                device->setPort(newPortName);
                return true;
            }
        }
        return false;
    }

    QPointer<QStandardItemModel> getDeviceNameModel(){
        if (activeDeviceNameModel.isNull()){
            activeDeviceNameModel = new QStandardItemModel;
        }
        activeDeviceNameModel->clear();
        for (auto device : activeDevicesList){
            activeDeviceNameModel->appendRow(new QStandardItem(QString(device->deviceName + "  on port: " + device->getPortName())));
        }
        return activeDeviceNameModel;
    }

    void generatePortList(){    // this is done once at start
        if (!ports.empty()){
            return;
        }
    #if defined(Q_OS_WIN)
        for (quint8 i = 1; i < 100; i++){
            ports.append(QString("COM%1").arg(i));
        }
    #else
        for (quint8 i = 0; i < 100; i++){
            ports.append(QString("/dev/ttyACM%1").arg(i));
        }
    #endif
    }
}
