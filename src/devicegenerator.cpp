#include "devicegenerator.h"

namespace DeviceGenerator {
    QPointer<MeasurementDevice> getDevice(QString deviceName){
        QPointer<MeasurementDevice> device;
        if (deviceName == deviceNameList.at(0)){
            device = new Keithley_2000(deviceName);
        }
        if (deviceName == deviceNameList.at(1)){
            device = new Keithley_2410(deviceName);
        }
        return device;
    }

    QPointer<QStandardItemModel> getDeviceNameModel(){
        if (deviceNameModel.isNull()){
            deviceNameModel = new QStandardItemModel();
            for (auto port : deviceNameList){
                deviceNameModel->appendRow(new QStandardItem(port));
            }
        }
        return deviceNameModel;
    }

    QPointer<QStandardItemModel> getPortNameModel(){
        if (portNameModel.isNull()){
            generatePortList();
            portNameModel = new QStandardItemModel();
            for (auto port : ports){
                portNameModel->appendRow(new QStandardItem(port));
            }
        }
        return portNameModel;
    }

    void generatePortList(){
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
