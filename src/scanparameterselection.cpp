#include "scanparameterselection.h"
#include "ui_scanparameterselection.h"
#include "devicemanager.h"
#include <QDebug>

ScanParameterSelection::ScanParameterSelection(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ScanParameterSelection)
{
    ui->setupUi(this); 
    this->setFrameShadow(QFrame::Plain);
    this->setFrameShape(QFrame::StyledPanel);
    this->setMidLineWidth(1);
    ui->scanParameterTableView->setFrameShadow(QTableView::Plain);
    ui->scanParameterTableView->setFrameShape(QTableView::StyledPanel);
    ui->scanParameterTableView->setStyleSheet("border: none;");
    ui->closeButton->setStyleSheet(":!hover{ border-image: url(:/res/close1.png)}:hover{ border-image: url(:/res/close2.png);}");
    connect(ui->closeButton, &QPushButton::clicked, this, &ScanParameterSelection::deleteLater);
    QPointer<QStandardItemModel> deviceModel = DeviceManager::getActiveDeviceNameModel();
    ui->deviceSelectionCombobox->setModel(deviceModel);
    connect(ui->deviceSelectionCombobox,
            static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &ScanParameterSelection::onDeviceSelectionChanged);
}

void ScanParameterSelection::onDeviceSelectionChanged(int selectedIndex){
    DeviceManager::cleanupActiveDevicesList();
    if (DeviceManager::activeDevicesList.size()<=selectedIndex){
        qDebug() << "activeDevicesList size too small!!";
        return;
    }
    qDebug() << "selected index: " << selectedIndex;
    //QPointer<QStandardItemModel> someModel = DeviceManager::activeDevicesList.at(0)->getDeviceParameterConstraintsModel();
    //ui->scanParameterTableView->setModel(DeviceManager::activeDevicesList.at(selectedIndex)->getDeviceParameterConstraintsModel());
    // model may not work in this case, use lists of contents insted!!!
}

ScanParameterSelection::~ScanParameterSelection()
{
    delete ui;
}
