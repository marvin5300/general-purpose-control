#include "setvalue.h"
#include "ui_setvalue.h"
#include "devicegenerator.h"

SetValue::SetValue(bool _measureOnly, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SetValue)
{
    measureOnly = _measureOnly;
    ui->setupUi(this); 
    this->setFrameShadow(QFrame::Plain);
    this->setFrameShape(QFrame::StyledPanel);
    this->setMidLineWidth(1);
    ui->closeButton->setStyleSheet(":!hover{ border-image: url(:/res/close1.png)}:hover{ border-image: url(:/res/close2.png);}");
    connect(ui->closeButton, &QPushButton::clicked, this, &SetValue::deleteLater);
    QPointer<QStandardItemModel> deviceModel = DeviceGenerator::getDeviceNameModel();
    ui->deviceSelectionCombobox->setModel(deviceModel);
    QPointer<QStandardItemModel> portModel = DeviceGenerator::getPortNameModel();
    ui->portSelectionCombobox->setModel(portModel);
    connect(ui->portSelectionCombobox, &QComboBox::currentTextChanged, this, &SetValue::onPortSelectionChanged);
    connect(ui->deviceSelectionCombobox, &QComboBox::currentTextChanged, this, &SetValue::onDeviceSelectionChanged);
    onDeviceSelectionChanged(ui->deviceSelectionCombobox->currentText());
    onPortSelectionChanged(ui->portSelectionCombobox->currentText());
}

void SetValue::onPortSelectionChanged(QString portName){
    if (device==nullptr){
        return;
    }
    device->setPort(portName);
}

void SetValue::onDeviceSelectionChanged(QString deviceName){
    if (device!=nullptr){
        device->exit();
        delete device;
        device = nullptr;
    }
    device = DeviceGenerator::getDevice(deviceName);
    // connect stuff
}

SetValue::~SetValue()
{
    delete ui;
}
