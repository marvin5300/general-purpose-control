#include "scanparameterselection.h"
#include "ui_scanparameterselection.h"
#include "devicemanager.h"

ScanParameterSelection::ScanParameterSelection(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ScanParameterSelection)
{
    ui->setupUi(this); 
    this->setFrameShadow(QFrame::Plain);
    this->setFrameShape(QFrame::StyledPanel);
    this->setMidLineWidth(1);
    ui->closeButton->setStyleSheet(":!hover{ border-image: url(:/res/close1.png)}:hover{ border-image: url(:/res/close2.png);}");
    connect(ui->closeButton, &QPushButton::clicked, this, &ScanParameterSelection::deleteLater);
    QPointer<QStandardItemModel> deviceModel = DeviceManager::getActiveDeviceNameModel();
    ui->deviceSelectionCombobox->setModel(deviceModel);
    connect(ui->deviceSelectionCombobox, &QComboBox::currentTextChanged, this, &ScanParameterSelection::onDeviceSelectionChanged);
    onDeviceSelectionChanged(ui->deviceSelectionCombobox->currentText());
}

void ScanParameterSelection::onDeviceSelectionChanged(QString deviceName){

}

ScanParameterSelection::~ScanParameterSelection()
{
    delete ui;
}
