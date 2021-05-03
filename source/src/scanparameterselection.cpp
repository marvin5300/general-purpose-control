#include "scanparameterselection.h"
#include "ui_scanparameterselection.h"
#include "devicemanager.h"
#include <QSizePolicy>
#include <QDebug>
#include <QPainter>
#include <QTimer>

ScanParameterSelection::ScanParameterSelection(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ScanParameterSelection)
{
    ui->setupUi(this); 
    this->setFrameShadow(QFrame::Plain);
    this->setFrameShape(QFrame::StyledPanel);
    this->setMidLineWidth(1);
    ui->scanParameterAdjustMode->setAttribute(Qt::WA_NoMousePropagation);
    ui->deviceSelectionCombobox->setAttribute(Qt::WA_NoMousePropagation);
    ui->scanParameterSelectionCombobox->setAttribute(Qt::WA_NoMousePropagation);

    ui->scanParameterTableWidget->setFrameShadow(QTableWidget::Plain);
    ui->scanParameterTableWidget->setFrameShape(QTableWidget::StyledPanel);
    ui->scanParameterTableWidget->setStyleSheet("border: none;");
    ui->closeButton->setStyleSheet(":!hover{ border-image: url(:/close1.png)}:hover{ border-image: url(:/close2.png);}");
    connect(ui->closeButton, &QPushButton::clicked, this, &ScanParameterSelection::deleteLater);
    QPointer<QStandardItemModel> deviceModel = DeviceManager::getActiveDeviceNameModel();
    connect(ui->deviceSelectionCombobox->model(), &QAbstractItemModel::dataChanged, this, &ScanParameterSelection::keepDeviceSelectionIndex);
    connect(ui->deviceSelectionCombobox,
            static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &ScanParameterSelection::onDeviceSelectionChanged);
    ui->deviceSelectionCombobox->setModel(deviceModel);
    connect(ui->scanParameterAdjustMode, &QComboBox::currentTextChanged, this,
            &ScanParameterSelection::onScanParameterAdjustModeChanged);
    ui->scanParameterAdjustMode->addItem("fixed");
    ui->scanParameterAdjustMode->addItem("ramp");


    connect(ui->fromEdit, &QLineEdit::editingFinished, this,
            [this](){bool ok = false;
                                 double temp = ui->fromEdit->text().toDouble(&ok);
                                 if(ok){this->parameterBeginValue = temp;
                                        this->parameterCurrentValue = temp;}
                                 else{ui->fromEdit->setText(QString("%1").arg(parameterBeginValue));}
                                });
    connect(ui->toEdit, &QLineEdit::editingFinished, this,
            [this](){bool ok = false;
                                 double temp = ui->toEdit->text().toDouble(&ok);
                                 if(ok){this->parameterEndValue = temp;}
                                 else{ui->toEdit->setText(QString("%1").arg(parameterEndValue));}
                                });
    connect(ui->stepsEdit, &QLineEdit::editingFinished, this,
            [this](){bool ok = false;
                     double temp = ui->stepsEdit->text().toDouble(&ok);
                     if(ok){this->stepNumber = temp;}
                     else{ui->stepsEdit->setText(QString("%1").arg(stepNumber));}
                     });
    timer.setInterval(1000);
    timer.setSingleShot(true);
    connect(&timer, &QTimer::timeout, this, [this](){mouseReleaseReady = true;});
}

void ScanParameterSelection::keepDeviceSelectionIndex(){
    if (ui->deviceSelectionCombobox->count()>deviceSelectionIndex){
        return;
    }
    ui->deviceSelectionCombobox->setCurrentIndex(deviceSelectionIndex);
}

void ScanParameterSelection::onDeviceSelectionChanged(int selectedIndex){
    if (selectedIndex>=DeviceManager::activeDevicesList.size()){
        //qDebug() << "activeDevicesList size too small!!";
        return;
    }
    //qDebug() << "selected index: " << selectedIndex;
    if (selectedIndex<0){
        return;
    }
    if (!(lastSelectedDevice.isNull())){
        disconnect(lastSelectedDevice,&MeasurementDevice::scanParameterReady, this,&ScanParameterSelection::onDeviceScanParameterReady);
    }
    deviceSelectionIndex = selectedIndex;
    lastSelectedDevice = DeviceManager::activeDevicesList.at(deviceSelectionIndex);
    connect(DeviceManager::activeDevicesList.at(deviceSelectionIndex),&MeasurementDevice::scanParameterReady, this,&ScanParameterSelection::onDeviceScanParameterReady);
    QMap<QString,DeviceParameterConstraint> deviceParameterConstraints = DeviceManager::activeDevicesList.at(selectedIndex)->getDeviceParameterConstraints();
    ui->scanParameterSelectionCombobox->clear();
    ui->scanParameterTableWidget->clear();
    ui->scanParameterTableWidget->setRowCount(deviceParameterConstraints.size());
    ui->scanParameterTableWidget->setColumnCount(deviceParameterConstraintsHeaderStrings.size());
    ui->scanParameterTableWidget->setHorizontalHeaderLabels(deviceParameterConstraintsHeaderStrings);
    ui->scanParameterTableWidget->verticalHeader()->hide();
    ui->scanParameterTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->scanParameterTableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    int i = 0;
    for (auto constraint : deviceParameterConstraints){
        ui->scanParameterTableWidget->setColumnWidth(i,20);
        if(constraint.mode == READWRITE ||constraint.mode == WRITEONLY){
            ui->scanParameterSelectionCombobox->addItem(constraint.name);
        }
        ui->scanParameterTableWidget->setItem(i,0,new QTableWidgetItem(constraint.name));
        ui->scanParameterTableWidget->setItem(i,1,new QTableWidgetItem(accessModeStrings.at(constraint.mode)));
        ui->scanParameterTableWidget->setItem(i,2,new QTableWidgetItem(QString("%1").arg(constraint.max_value)));
        ui->scanParameterTableWidget->setItem(i,3,new QTableWidgetItem(QString("%1").arg(constraint.min_value)));
        for (int k = 0; k < 4; k++){
            ui->scanParameterTableWidget->item(i,k)->setFlags(
                        ui->scanParameterTableWidget->item(i,k)->flags() &
                        ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable | Qt::ItemNeverHasChildren);
            ui->scanParameterTableWidget->item(i,k)->setTextAlignment(Qt::AlignCenter);
        }
        i++;
    }
    ui->scanParameterTableWidget->resizeColumnsToContents();
    ui->scanParameterTableWidget->resizeRowsToContents();
    // adjusting the settings here for different measurement parameter structs
    ui->scanParameterTableWidget->horizontalHeader()->setSectionResizeMode(
                deviceParameterConstraintsHeaderStrings.size()-1,QHeaderView::Stretch);
    ui->scanParameterTableWidget->horizontalHeader()->setSectionResizeMode(
                deviceParameterConstraintsHeaderStrings.size()-2,QHeaderView::Stretch);
    //this->setFixedWidth(ui->scanParameterTableWidget->width());
    //QPointer<QStandardItemModel> someModel = DeviceManager::activeDevicesList.at(0)->getDeviceParameterConstraintsModel();
    //ui->scanParameterTableView->setModel(DeviceManager::activeDevicesList.at(selectedIndex)->getDeviceParameterConstraintsModel());
    // model may not work in this case, use lists of contents insted!!!
}

void ScanParameterSelection::onScanParameterAdjustModeChanged(QString mode){
    ui->checkBox_4->hide();
    ui->checkBox_5->hide();
    ui->delayEdit->hide();
    ui->delayLabel->hide();
    if (mode == "fixed"){
        ui->toEdit->setHidden(true);
        ui->toLabel->setHidden(true);
        ui->stepsEdit->setHidden(true);
        ui->stepsCombobox->setHidden(true);
        ui->logStepsButton->setHidden(true);
        ui->fromLabel->setText("value:");
    }
    if (mode == "ramp"){
        ui->toEdit->setHidden(false);
        ui->toLabel->setHidden(false);
        ui->stepsEdit->setHidden(false);
        ui->stepsCombobox->setHidden(false);
        ui->logStepsButton->setHidden(false);
        ui->fromLabel->setText("from:");
    }
}

ScanParameterSelection::~ScanParameterSelection()
{
    delete ui;
}

void ScanParameterSelection::scanParameterInit(){
    qDebug() <<"ScanParamSel:ScanParameterInit ";
    if (deviceSelectionIndex>=DeviceManager::activeDevicesList.size()){
        return;
    }
    setScanCounter = 0;
    parameterCurrentValue = parameterBeginValue;
    MeasurementValue scanParameter;
    scanParameter.name = ui->scanParameterSelectionCombobox->currentText();
    scanParameter.value = parameterBeginValue;
    DeviceManager::activeDevicesList.at(deviceSelectionIndex)->setScanParameter(scanParameter);
}

void ScanParameterSelection::onDeviceScanParameterReady(QString deviceName, quint64 number){
    emit scanParameterReady(deviceName, number);
}

void ScanParameterSelection::nextScanParameterStep(){
    qDebug()<<"nextStep";
    // changes scan parameter value to the next step (within selected range and settings)
    if (deviceSelectionIndex>=DeviceManager::activeDevicesList.size()){
        emit completedLoop();
        return;
    }

    bool fixedMode = ui->scanParameterAdjustMode->currentText()=="fixed";
    if (fixedMode){
        emit completedLoop();
        MeasurementDevice* device = DeviceManager::activeDevicesList.at(deviceSelectionIndex);
        device->scanParameterReady(device->deviceName(),0);
        return;
    }

    // following should only happen when ramping
    setScanCounter++;
    qDebug() <<"Scan Param:setscancounter: "<<setScanCounter;
    MeasurementValue scanParameter;
    // determine which value will be next and if the loop is finished
    bool newLoop = false;
    if (ui->scanParameterAdjustMode->currentText()=="ramp"){
        MeasurementDevice* device = DeviceManager::activeDevicesList.at(deviceSelectionIndex);
        device->scanParameterReady(device->deviceName(),0);
        // if ramping
        if (parameterCurrentValue == parameterEndValue||
                (parameterEndValue-parameterCurrentValue)<0.1*(parameterEndValue-parameterBeginValue)/(stepNumber-1)){
            //qDebug() << "deviceSelectionIndex: " << deviceSelectionIndex << " completedLoop";
            emit completedLoop();
            
            newLoop = true;
        }
        switch(ui->stepsCombobox->currentIndex()){
        case 0:
            parameterCurrentValue = parameterCurrentValue + (parameterEndValue-parameterBeginValue)/(stepNumber-1);
            break;
        case 1:
            parameterCurrentValue = parameterCurrentValue + stepNumber;
        default:
            break;
        }
        if (parameterCurrentValue>parameterEndValue){
            parameterCurrentValue = parameterEndValue;
        }
        scanParameter.value = parameterCurrentValue;
        if (newLoop){
            parameterCurrentValue = parameterBeginValue;
            scanParameter.value = parameterBeginValue;   
        }
    }
    scanParameter.name = ui->scanParameterSelectionCombobox->currentText();
    DeviceManager::activeDevicesList.at(deviceSelectionIndex)->setScanParameter(scanParameter);
}

void ScanParameterSelection::progressCarry(int progress){
    if (stepNumber<2){
        emit addProgress(100);
        return;
    }
    double increment = 1.0/(stepNumber); // the step precision of the percentage value
    double progressCurrentLoop = (1.0-increment)*(parameterCurrentValue-parameterBeginValue)/(parameterEndValue-parameterBeginValue);
    progressCurrentLoop += 0.01*progress*increment;
    int percentage = (int)(100.0*progressCurrentLoop);
    emit addProgress(percentage);
}

// drag & drop actions:
void ScanParameterSelection::mouseMoveEvent(QMouseEvent *event){
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
    int LeftBorder = layout->geometry().width() - this->geometry().width();
    if(x < 0) x = 0;
    else if(x > LeftBorder) x = LeftBorder;
    move(x, oldY);
}


void ScanParameterSelection::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton){
        dragStartPosition = event->pos();
    }
    oldX = this->geometry().x();
    oldY = this->geometry().y();
    mouseClickX = event->globalX();
    mouseClickY = event->globalY();
}

bool ScanParameterSelection::isMinimumDistanceRiched(QMouseEvent *event)
{
    return (event->pos() - dragStartPosition).manhattanLength() >= QApplication::startDragDistance();
}

bool ScanParameterSelection::moveInLayout(QWidget *widget, MoveDirection direction)
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
    const int newIndex = (direction == MoveLeft) ? (index - 1) : (index + 1);
    layout->removeWidget(widget);
    layout->insertWidget(newIndex , widget);
    return true;
}

void ScanParameterSelection::paintEvent(QPaintEvent *)
{
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
}

void ScanParameterSelection::mouseReleaseEvent(QMouseEvent *)
{
    if (!mouseReleaseReady){
        return;
    }
    mouseReleaseReady = false;
    timer.start();
    if(layout.isNull()){
        return;
    }
    int x = this->geometry().x();
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
