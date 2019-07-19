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
    ui->closeButton->setStyleSheet(":!hover{ border-image: url(:/res/close1.png)}:hover{ border-image: url(:/res/close2.png);}");
    connect(ui->closeButton, &QPushButton::clicked, this, &ScanParameterSelection::deleteLater);
    QPointer<QStandardItemModel> deviceModel = DeviceManager::getActiveDeviceNameModel();
    connect(ui->deviceSelectionCombobox->model(), &QAbstractItemModel::dataChanged, this, &ScanParameterSelection::keepDeviceSelectionIndex);
    connect(ui->deviceSelectionCombobox,
            static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &ScanParameterSelection::onDeviceSelectionChanged);
    ui->deviceSelectionCombobox->setModel(deviceModel);
    ui->scanParameterAdjustMode->addItem("ramp");
    ui->scanParameterAdjustMode->addItem("fixed");
    connect(ui->scanParameterAdjustMode, &QComboBox::currentTextChanged, this,
            &ScanParameterSelection::onScanParameterAdjustModeChanged);
    onScanParameterAdjustModeChanged("ramp");

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
    for (i = 0; i < ui->scanParameterSelectionCombobox->count(); i++){
        if (ui->scanParameterSelectionCombobox->itemText(i)=="V"){
            // default selection
            ui->scanParameterSelectionCombobox->setCurrentIndex(i);
        }
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
    if (mode == "fixed"){
        ui->toEdit->setHidden(true);
        ui->toLabel->setHidden(true);
        ui->stepsEdit->setHidden(true);
        ui->stepsLabel->setHidden(true);
        ui->logStepsButton->setHidden(true);
        ui->fromLabel->setText("value:");
    }
    if (mode == "ramp"){
        ui->toEdit->setHidden(false);
        ui->toLabel->setHidden(false);
        ui->stepsEdit->setHidden(false);
        ui->stepsLabel->setHidden(false);
        ui->logStepsButton->setHidden(false);
        ui->fromLabel->setText("from:");
    }
}

ScanParameterSelection::~ScanParameterSelection()
{
    delete ui;
}


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
    int offset;
    if(oldX > x)
    {
        offset = oldX - x;
        direct = MoveLeft;
    }
    else if(oldX < x)
    {
        offset = x - oldX;
        direct = MoveRight;
    }
    qDebug() << "offset: " << offset <<
                " width: " << width() <<
                " x: " << x <<
                " oldX: " << oldX;
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
