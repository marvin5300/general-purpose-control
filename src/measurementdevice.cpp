#include "measurementdevice.h"
#include "ui_measurementdevice.h"
#include "devicemanager.h"
#include "serial.h"
#include <QThread>
#include <QList>
#include <QPainter>

quint64 MeasurementDevice::globalIdCounter = 0;

MeasurementDevice::MeasurementDevice(QString _portName, quint32 _baudRate, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MeasurementDevice)
{
    ui->setupUi(this);
    ui->interfaceNameSelectBox->setAttribute(Qt::WA_NoMousePropagation);
    ui->deviceNameSelectBox->setAttribute(Qt::WA_NoMousePropagation);
    interfaceName = _portName;
    baudRate = _baudRate;
    localId = globalIdCounter;
    globalIdCounter++;
    this->setFrameShadow(QFrame::Plain);
    this->setFrameShape(QFrame::StyledPanel);
    this->setMidLineWidth(1);
    ui->parameterTableWidget->setFrameShadow(QTableWidget::Plain);
    ui->parameterTableWidget->setFrameShape(QTableWidget::StyledPanel);
    ui->parameterTableWidget->setStyleSheet("border: none;");
    ui->closeButton->setStyleSheet(":!hover{ border-image: url(:/res/close1.png)}:hover{ border-image: url(:/res/close2.png);}");
    connect(ui->closeButton, &QPushButton::clicked, this, &MeasurementDevice::exit);
    ui->deviceNameSelectBox->setModel(DeviceManager::getAllDeviceNameModel());
    ui->interfaceNameSelectBox->setModel(DeviceManager::getAllInterfaceNameModel());
}

void MeasurementDevice::init(QString _deviceName, QString _interfaceName, QMap<QString,DeviceParameterConstraint> constraintsMap){
    ui->deviceNameSelectBox->setCurrentIndex(ui->deviceNameSelectBox->findText(_deviceName));
    connect(ui->deviceNameSelectBox, &QComboBox::currentTextChanged, this, &MeasurementDevice::onDeviceSelectionChanged);
    ui->interfaceNameSelectBox->setCurrentIndex(ui->interfaceNameSelectBox->findText(_interfaceName));
    connect(ui->interfaceNameSelectBox, &QComboBox::currentTextChanged, this, &MeasurementDevice::onInterfaceSelectionChanged);
    //interfaceName = _interfaceName;
    if (_interfaceName!="not selected"&&_interfaceName!=""){
        connectBus();
    }else{
        ui->deviceNameSelectBox->setStyleSheet("color: black;");
        ui->interfaceNameSelectBox->setStyleSheet("color: black;");
    }

    // setup table widget
    ui->parameterTableWidget->clear();
    ui->parameterTableWidget->setRowCount(constraintsMap.size());
    ui->parameterTableWidget->setColumnCount(deviceParameterConstraintsHeaderStrings.size());
    //QStringList temp;
    //temp << "Get?";
    //temp.append(deviceParameterConstraintsHeaderStrings);
    //ui->parameterTableWidget->setHorizontalHeaderLabels(temp);
    ui->parameterTableWidget->setHorizontalHeaderLabels(deviceParameterConstraintsHeaderStrings);
    ui->parameterTableWidget->verticalHeader()->hide();
    ui->parameterTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->parameterTableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    unsigned int i = 0;
    for (auto constraint : constraintsMap){
        ui->parameterTableWidget->setColumnWidth(i,20);
        QTableWidgetItem *item = new QTableWidgetItem(constraint.name);
        item->setCheckState(Qt::Unchecked);
        item->setFlags(item->flags()|Qt::ItemIsUserCheckable);
        ui->parameterTableWidget->setItem(i,0,item);
        //ui->parameterTableWidget->setItem(i,1,new QTableWidgetItem(constraint.name));
        //ui->parameterTableWidget->item(i,0)->setCheckState(Qt::Unchecked);
        ui->parameterTableWidget->setItem(i,1,new QTableWidgetItem(accessModeStrings.at(constraint.mode)));
        ui->parameterTableWidget->setItem(i,2,new QTableWidgetItem(QString("%1").arg(constraint.max_value)));
        ui->parameterTableWidget->setItem(i,3,new QTableWidgetItem(QString("%1").arg(constraint.min_value)));
        for (int k = 0; k < 4; k++){
            ui->parameterTableWidget->item(i,k)->setFlags(
                        ui->parameterTableWidget->item(i,k)->flags() &
                        ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable | Qt::ItemNeverHasChildren);
            ui->parameterTableWidget->item(i,k)->setTextAlignment(Qt::AlignCenter);
        }
        ui->parameterTableWidget->item(i,0)->setFlags(ui->parameterTableWidget->item(i,0)->flags() | Qt::ItemIsUserCheckable); //  | Qt::ItemIsEditable | Qt::ItemIsSelectable
        i++;
    }
    ui->parameterTableWidget->resizeColumnsToContents();
    ui->parameterTableWidget->resizeRowsToContents();
   // ui->parameterTableWidget->setColumnWidth(0,0);
    // adjusting the settings here for different measurement parameter structs
    /*ui->parameterTableWidget->horizontalHeader()->setSectionResizeMode(
                deviceParameterConstraintsHeaderStrings.size()-1,QHeaderView::Stretch);*/
    ui->parameterTableWidget->horizontalHeader()->setSectionResizeMode(
                deviceParameterConstraintsHeaderStrings.size()-2,QHeaderView::Stretch);

}

quint64 MeasurementDevice::getLocalId()const{
    return localId;
}

MeasurementDevice::~MeasurementDevice()
{
    delete ui;
}

void MeasurementDevice::onConnectionStatusChanged(bool connected){
    setUiConnectionState(connected);
}

void MeasurementDevice::setUiConnectionState(bool connected){
    if (connected){
        ui->deviceNameSelectBox->setStyleSheet("color: green;");
        ui->interfaceNameSelectBox->setStyleSheet("color: green;");
    }else{
        correctDeviceConnected = false;
        ui->deviceNameSelectBox->setStyleSheet("color: red;");
        ui->interfaceNameSelectBox->setStyleSheet("color: red;");
    }
}


void MeasurementDevice::onInterfaceSelectionChanged(QString _interfaceName){
    emit closeConnection();
    interfaceName = _interfaceName;
    DeviceManager::actualizeDeviceNameModel();
    if (_interfaceName!="not selected"&&_interfaceName!=""){
        connectBus();
    }else{
        ui->deviceNameSelectBox->setStyleSheet("color: black;");
        ui->interfaceNameSelectBox->setStyleSheet("color: black;");
    }
}

void MeasurementDevice::onDeviceSelectionChanged(QString _newDeviceName){
    // create new device on same location but different subclass
    emit deviceSelectionChange(QPointer<MeasurementDevice>(this),_newDeviceName, interfaceName);
    exit();
}

//QPointer<QStandardItemModel> MeasurementDevice::getDeviceParameterConstraintsModel() const{
//    const QMap<QString,DeviceParameterConstraint> deviceParamConstraints = getDeviceParameterConstraints();
//    QPointer<QStandardItemModel> model = new QStandardItemModel;
//    for (auto constraint : deviceParamConstraints){
//        QList<QStandardItem*> list;
//        list << new QStandardItem(constraint.name);
//        list << new QStandardItem(QString("min: %1").arg(constraint.min_value)),
//        list << new QStandardItem(QString("max: %1").arg(constraint.max_value));
//        model->appendRow(list);
//    }
//    return model;
//}

void MeasurementDevice::exit(){
    //QPointer<MeasurementDevice> thisObject = this;
    DeviceManager::removeDevice(this);
    emit closeConnection();
    this->deleteLater();
}

// functions for drag and drop moving the widget

void MeasurementDevice::mouseMoveEvent(QMouseEvent *event){
    if(layout.isNull()){
        return;
    }
    if (!(event->buttons() & Qt::LeftButton))
        return;
    if (!isMinimumDistanceRiched(event))
    {
        return;
    }
    int x = event->globalX() - mouseClickX + oldX;
    int LeftBorder = parentWidget()->geometry().width() - this->geometry().width();
    if(x < 0) x = 0;
    else if(x > LeftBorder) x = LeftBorder;
    move(x, oldY);
}


void MeasurementDevice::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton){
        dragStartPosition = event->pos();
    }
    oldX = this->geometry().x();
    oldY = this->geometry().y();
    mouseClickX = event->globalX();
    mouseClickY = event->globalY();
}

bool MeasurementDevice::isMinimumDistanceRiched(QMouseEvent *event)
{
    return (event->pos() - dragStartPosition).manhattanLength() >= QApplication::startDragDistance();
}

bool MeasurementDevice::moveInLayout(QWidget *widget, MoveDirection direction)
{
    if (layout.isNull()){
        return false;
    }
    const int index = layout->indexOf(widget);
    if (direction == MoveLeft && index == 1)
    {
        return false;
    }
    if (direction == MoveRight && index == layout->count()-2 )
    {
        return false;
    }
    const int newIndex = direction == MoveLeft ? index - 1 : index + 1;
    layout->removeWidget(widget);
    layout->insertWidget(newIndex , widget);
    return true;
}

void MeasurementDevice::paintEvent(QPaintEvent *)
{
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
}

void MeasurementDevice::mouseReleaseEvent(QMouseEvent *)
{
    if(layout.isNull()){
        return;
    }
    int x = geometry().x();
    MoveDirection direct;
    int offset = 0;
    if(oldX > x)
    {
        offset = oldX - x;
        direct = MoveLeft;
    }
    else if(oldX <= x)
    {
        offset = x - oldX;
        direct = MoveRight;
    }
    int count = offset/width();
    for(int i = 0; i < count; i++)
    {
        moveInLayout(this, direct);
    }
    update();
    if (layout.isNull()){
        return;
    }
    layout->update();
    //this->saveGeometry();
}
