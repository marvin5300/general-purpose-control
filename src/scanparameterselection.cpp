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
    ui->scanParameterTableWidget->setFrameShadow(QTableWidget::Plain);
    ui->scanParameterTableWidget->setFrameShape(QTableWidget::StyledPanel);
    ui->scanParameterTableWidget->setStyleSheet("border: none;");
    ui->closeButton->setStyleSheet(":!hover{ border-image: url(:/res/close1.png)}:hover{ border-image: url(:/res/close2.png);}");
    connect(ui->closeButton, &QPushButton::clicked, this, &ScanParameterSelection::deleteLater);
    QPointer<QStandardItemModel> deviceModel = DeviceManager::getActiveDeviceNameModel();
    ui->deviceSelectionCombobox->setModel(deviceModel);
    connect(ui->deviceSelectionCombobox->model(), &QAbstractItemModel::dataChanged, this, &ScanParameterSelection::keepDeviceSelectionIndex);
    connect(ui->deviceSelectionCombobox,
            static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &ScanParameterSelection::onDeviceSelectionChanged);
}

void ScanParameterSelection::keepDeviceSelectionIndex(){
    if (ui->deviceSelectionCombobox->count()>deviceSelectionIndex){
        return;
    }
    ui->deviceSelectionCombobox->setCurrentIndex(deviceSelectionIndex);
}

void ScanParameterSelection::onDeviceSelectionChanged(int selectedIndex){
    deviceSelectionIndex = selectedIndex;
    if (selectedIndex>=DeviceManager::activeDevicesList.size()){
        //qDebug() << "activeDevicesList size too small!!";
        return;
    }
    //qDebug() << "selected index: " << selectedIndex;
    if (selectedIndex<0){
        return;
    }
    QMap<QString,DeviceParameterConstraint> deviceParameterConstraints = DeviceManager::activeDevicesList.at(selectedIndex)->getDeviceParameterConstraints();
    ui->scanParameterSelectionCombobox->clear();
    ui->scanParameterTableWidget->clear();
    ui->scanParameterTableWidget->setRowCount(deviceParameterConstraints.size());
    ui->scanParameterTableWidget->setColumnCount(deviceParameterConstraintsHeaderStrings.size());
    ui->scanParameterTableWidget->setHorizontalHeaderLabels(deviceParameterConstraintsHeaderStrings);
    ui->scanParameterTableWidget->verticalHeader()->hide();
    ui->scanParameterTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->scanParameterTableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    unsigned int i = 0;
    for (auto constraint : deviceParameterConstraints){
        ui->scanParameterTableWidget->setColumnWidth(i,20);

        ui->scanParameterSelectionCombobox->addItem(constraint.name);
        ui->scanParameterTableWidget->setItem(i,0,new QTableWidgetItem(constraint.name));
        ui->scanParameterTableWidget->setItem(i,1,new QTableWidgetItem(accessModeStrings.at(constraint.mode)));
        ui->scanParameterTableWidget->setItem(i,2,new QTableWidgetItem(QString("%1").arg(constraint.max_value)));
        ui->scanParameterTableWidget->setItem(i,3,new QTableWidgetItem(QString("%1").arg(constraint.min_value)));
        for (int k = 0; k < 4; k++){
            ui->scanParameterTableWidget->item(i,k)->setFlags(
                        ui->scanParameterTableWidget->item(i,k)->flags() &
                        ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
        }
        i++;
    }
    ui->scanParameterTableWidget->resizeColumnsToContents();
    ui->scanParameterTableWidget->resizeRowsToContents();
    //this->setFixedWidth(ui->scanParameterTableWidget->width());
    //QPointer<QStandardItemModel> someModel = DeviceManager::activeDevicesList.at(0)->getDeviceParameterConstraintsModel();
    //ui->scanParameterTableView->setModel(DeviceManager::activeDevicesList.at(selectedIndex)->getDeviceParameterConstraintsModel());
    // model may not work in this case, use lists of contents insted!!!
}

ScanParameterSelection::~ScanParameterSelection()
{
    delete ui;
}
