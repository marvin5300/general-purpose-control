#include "devicemanager.h"

#include "devices/keithley_2000.h"
#include "devices/keithley_2410.h"
#include "devices/sourcetronic_st2819a.h"
#include "devices/tektronix_dmm4020.h"
#include "devices/voltcraft_psp1803.h"
#include "devices/rigol_dsa1030a.h"
#include "devices/hp_34401a.h"
#include "devices/hameg_hm8143.h"
#include "devices/gw_instek_gpd4303s.h"
#include "devices/dummy.h"
#include "devices/sourcetronic_st2826.h"
#include <QDebug>
#include <QDir>

QList<QPointer<MeasurementDevice> > DeviceManager::activeDevicesList;
QStringList DeviceManager::interfaceNameList;
QPointer<QStandardItemModel> DeviceManager::activeDeviceNameModel;
QPointer<QStandardItemModel> DeviceManager::allDeviceNameModel;
QPointer<QStandardItemModel> DeviceManager::allInterfaceNameModel;

QStringList DeviceManager::_masks = {"ttyUSB*", "ttyA*"};

const QStringList DeviceManager::deviceNameList({
                                           "MODEL 2000",
                                           "MODEL 2410",
                                           "ST2819A",
                                           "DMM4020",
                                           "PSP1803",
                                           "RIGOL DSA1030A",
                                           "HP 34401A",
                                           "Hameg HM8143",
                                           "GPD-4303S",
                                           "ST2826"
                                        });

QPointer<MeasurementDevice> DeviceManager::getDevice(QString deviceName, QString portName){
    static QPointer<MeasurementDevice> device;
    if (deviceName == "not selected"){
        device = new Dummy();
    }
    if (deviceName == deviceNameList.at(0)){
        device = new Keithley_2000(portName);
    }
    if (deviceName == deviceNameList.at(1)){
        device = new Keithley_2410(portName);
    }
    if (deviceName == deviceNameList.at(2)){
        device = new SourceTronic_ST2819A(portName);
    }
    if (deviceName == deviceNameList.at(3)){
        device = new Tektronix_DMM4020(portName);
    }
    if (deviceName == deviceNameList.at(4)){
        device = new Voltcraft_PSP1803(portName);
    }
    if (deviceName == deviceNameList.at(5)){
        device = new RIGOL_DSA1030A(portName);
    }
    if (deviceName == deviceNameList.at(6)){
        device = new HP_34401A(portName);
    }
    if (deviceName == deviceNameList.at(7)){
        device = new Hameg_HM8143(portName);
    }
    if (deviceName == deviceNameList.at(8)){
        device = new GW_INSTEK_GPD4303S(portName);
    }
    if (deviceName == deviceNameList.at(9)){
        device = new SourceTronic_ST2826(portName);
    }
    activeDevicesList.append(device);
    return device;
}

void DeviceManager::cleanupActiveDevicesList(){
    for (int i = activeDevicesList.size()-1; i >= 0; i--){
        if (activeDevicesList.at(i).isNull()){
            activeDevicesList.removeAt(i);
        }
    }
}

void DeviceManager::removeDevice(QPointer<MeasurementDevice> device){
    for (int i = activeDevicesList.size()-1; i >= 0; i--){
        if (!activeDevicesList.at(i).isNull()){
            /*qDebug() << activeDevicesList.at(i)->getDeviceName() << " == " << device->getDeviceName();
            qDebug() << activeDevicesList.at(i)->getInterfaceName() << " == " << device->getInterfaceName();
            qDebug() << activeDevicesList.at(i)->getLocalId() << " == " << device->getLocalId();*/
            if (activeDevicesList.at(i)->deviceName() == device->deviceName()
                    && activeDevicesList.at(i)->getInterfaceName() == device->getInterfaceName()
                    && activeDevicesList.at(i)->getLocalId() == device->getLocalId()){
                activeDevicesList.removeAt(i);
                actualizeDeviceNameModel();
                return;
            }
        }else{
            activeDevicesList.removeAt(i);
        }
    }
}

QPointer<QStandardItemModel> DeviceManager::getActiveDeviceNameModel(){
    actualizeDeviceNameModel();
    return activeDeviceNameModel;
}

void DeviceManager::actualizeDeviceNameModel(){
    cleanupActiveDevicesList();
    if (activeDeviceNameModel.isNull()){
        activeDeviceNameModel = new QStandardItemModel;
    }
    activeDeviceNameModel->clear();
    for (auto device : activeDevicesList){
        activeDeviceNameModel->appendRow(new QStandardItem(QString(device->deviceName() + " : " + device->getInterfaceName())));
    }
}

QPointer<QStandardItemModel> DeviceManager::getAllDeviceNameModel(){
    if (allDeviceNameModel.isNull()){
        allDeviceNameModel = new QStandardItemModel;
        allDeviceNameModel->appendRow(new QStandardItem(QString("not selected")));
        for (auto deviceName : deviceNameList){
            allDeviceNameModel->appendRow(new QStandardItem(deviceName));
        }
    }
    return allDeviceNameModel;
}

QPointer<QStandardItemModel> DeviceManager::getAllInterfaceNameModel(){
    if (allInterfaceNameModel.isNull()){
        allInterfaceNameModel = new QStandardItemModel;
        allInterfaceNameModel->appendRow(new QStandardItem(QString("not selected")));
        for (auto interfaceName : interfaceNameList){
            allInterfaceNameModel->appendRow(new QStandardItem(interfaceName));
        }
    }
    return allInterfaceNameModel;
}

void DeviceManager::setSerialMask(QStringList masks){
    _masks = masks;
#if defined(Q_OS_UNIX)
    QDir directory("/dev","*",QDir::Name, QDir::System);
    if (!masks.empty()){
        interfaceNameList = directory.entryList(masks);
    }else{
        interfaceNameList.clear();
    }
    if (allInterfaceNameModel.isNull()){
        allInterfaceNameModel = new QStandardItemModel;
        allInterfaceNameModel->appendRow(new QStandardItem(QString("not selected")));
    }else{
        allInterfaceNameModel->setRowCount(1);
    }
    for (auto name : interfaceNameList){
        allInterfaceNameModel->appendRow(new QStandardItem(name));
    }
#endif
}

void DeviceManager::generateInterfaceList(QStringList masks){    // this is done once at start
    if (!interfaceNameList.empty()){
        return;
    }
#if defined(Q_OS_WIN)
    for (quint8 i = 1; i < 10; i++){
        interfaceNameList.append(QString("COM%1").arg(i));
    }
#endif
#if defined(Q_OS_UNIX)
    QDir directory("/dev","*",QDir::Name, QDir::System);
    interfaceNameList = directory.entryList(masks);
#endif
}
