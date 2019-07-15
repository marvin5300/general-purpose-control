#include "setvalue.h"
#include "ui_setvalue.h"
#include "devicemanager.h"

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
    QPointer<QStandardItemModel> deviceModel = DeviceManager::getDeviceNameModel();
    ui->deviceSelectionCombobox->setModel(deviceModel);
    connect(ui->deviceSelectionCombobox, &QComboBox::currentTextChanged, this, &SetValue::onDeviceSelectionChanged);
    onDeviceSelectionChanged(ui->deviceSelectionCombobox->currentText());
}

void SetValue::onDeviceSelectionChanged(QString deviceName){

}

SetValue::~SetValue()
{
    delete ui;
}
