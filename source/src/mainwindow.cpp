#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "measurementdevice.h"
#include "scanparameterselection.h"
#include "devicemanager.h"
#include "settings.h"
#include <QFileDialog>
#include <QPalette>
#include <QStandardPaths>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("General Purpose Control");
    this->setWindowIcon(QIcon(":/tune.png"));
    ui->addAdjustValueButton->setStyleSheet(":!hover{ border-image: url(:/plus1.png)}:hover{ border-image: url(:/plus2.png);}");
    ui->addDeviceButton->setStyleSheet(":!hover{ border-image: url(:/plus1.png)}:hover{ border-image: url(:/plus2.png);}");
    ui->progressBar->setValue(0);
    connect(ui->progressBar, &QProgressBar::valueChanged, this, &MainWindow::adjustProgressBarAppearance);
    ui->progressBar->setStyleSheet(lowLevel);

    connect(&intervalTimer, &QTimer::timeout, this, &MainWindow::onTimerTimeout);
    intervalTimer.setSingleShot(true);

    connect(ui->startMeasurementButton, &QPushButton::clicked, this, &MainWindow::onStartMeasurementButtonClicked);
    connect(ui->addAdjustValueButton, &QPushButton::clicked, this, &MainWindow::onAddAdjustValuesButtonClicked);
    connect(ui->addDeviceButton, &QPushButton::clicked, this, &MainWindow::onAddMeasureValuesButtonClicked);
    connect(ui->actionSerial_Console, &QAction::triggered, this, [this](){SerialConsole *console = new SerialConsole(this);});
    DeviceManager::generateInterfaceList();

    // all settings related stuff
    connect(ui->actionopen_settings, &QAction::triggered, this, &MainWindow::onSettingsClicked);

    // all filehandler related stuff
    fileHandler = new FileHandler(this);
    connect(this, &MainWindow::setOutputFile, fileHandler, &FileHandler::setOutputFile);
    connect(this, &MainWindow::finishedMeasurement, fileHandler, &FileHandler::onFinishedMeasurement);
    connect(this, &MainWindow::startMeasurement, fileHandler, &FileHandler::onNewMeasurementStarted);
    connect(fileHandler, &FileHandler::openedFileName, ui->fileStatusLabel, &QLabel::setText);
    connect(ui->actionselect_output_file, &QAction::triggered, this, [this](){
        QString outputFileName = QFileDialog::getSaveFileName(this, tr("Open File"),
                                                              QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
                                                              tr("Any File (*)"),
                                                              nullptr,
                                                              QFileDialog::DontConfirmOverwrite);
        if(!outputFileName.isEmpty()){emit setOutputFile(outputFileName);}
    });
    emit setAutoOutputFile(ui->autoFileCheckbox->isChecked());
}
//Add_PB->setStyleSheet( "*{border-image: url(:/icons/maximize.bmp);}"
//":pressed{ border-image: url(:/icons/maximize_pressed.bmp);}");

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setSerialMask(QStringList masks){
    DeviceManager::setSerialMask(masks);
}

void MainWindow::onAddAdjustValuesButtonClicked(){
    ScanParameterSelection *widget = new ScanParameterSelection(this);
    widget->layout=ui->scanValuesHorizontalLayout;
    //unsigned int n = ui->scanValuesHorizontalLayout->count();
    //ui->scanValuesHorizontalLayout->insertWidget(n-2,widget);
    ui->scanValuesHorizontalLayout->insertWidget(ui->scanValuesHorizontalLayout->count()-1,widget);
}

void MainWindow::onAddMeasureValuesButtonClicked(){
    //MeasurementDevice *device = DeviceManager::getDevice("default","default");
    QPointer<MeasurementDevice> device = DeviceManager::getDevice("not selected", "not selected");
    device->setParent(this);
    device->layout=ui->deviceConfigHorizontalLayout;
    connect(device, &MeasurementDevice::deviceSelectionChange, this, &MainWindow::onDeviceSelectionChange);
    //unsigned int n = ui->measureValuesVerticalLayout->count();
    //ui->measureValuesVerticalLayout->insertWidget(n-2,widget);
    DeviceManager::actualizeDeviceNameModel();
    ui->deviceConfigHorizontalLayout->insertWidget(ui->deviceConfigHorizontalLayout->count()-1,device);
}

void MainWindow::onDeviceSelectionChange(QPointer<MeasurementDevice> device, QString _newDeviceName, QString _newInterfaceName){
    QPointer<MeasurementDevice> neoDevice = DeviceManager::getDevice(_newDeviceName, _newInterfaceName);
    neoDevice->setParent(this);
    neoDevice->layout=ui->deviceConfigHorizontalLayout;
    //unsigned int i = ui->deviceConfigHorizontalLayout->indexOf(device);
    ui->deviceConfigHorizontalLayout->replaceWidget(device,neoDevice);
    DeviceManager::actualizeDeviceNameModel();
    connect(neoDevice, &MeasurementDevice::deviceSelectionChange, this, &MainWindow::onDeviceSelectionChange);
}

void MainWindow::onSettingsClicked(){
    Settings *dialog = new Settings(this, fileHandler->getFilePath(),DeviceManager::_masks);
    connect(dialog, &Settings::setOutputFileName, fileHandler, &FileHandler::setOutputFile);
    connect(dialog, &Settings::setSerialMask, this, &MainWindow::setSerialMask);
    dialog->show();
}

void MainWindow::adjustProgressBarAppearance(int value){
    (value>=50) ? ui->progressBar->setStyleSheet(highLevel) :
        ui->progressBar->setStyleSheet(lowLevel);
}

void MainWindow::setUiMeasurementState(bool _ongoingMeasurement){
    ui->menuSettings->setDisabled(_ongoingMeasurement);
    ui->devicesGroupBox->setDisabled(_ongoingMeasurement);
    ui->scanValueGroupBox->setDisabled(_ongoingMeasurement);
    ui->noLimitCheck->setDisabled(_ongoingMeasurement);
    ui->intervalLabel->setDisabled(_ongoingMeasurement);
    ui->intervalspinbox->setDisabled(_ongoingMeasurement);
    ui->startMeasurementButton->setText(_ongoingMeasurement ? "force stop" : "start measurement");
}

void MainWindow::onStartMeasurementButtonClicked(){
    qDebug() << "start cycle "<< measCycle;
    ongoingMeasurement = !ongoingMeasurement;
    setUiMeasurementState(ongoingMeasurement); // ongoingMeasurement is false at the start of the program
    if (ongoingMeasurement){
         // now it is true when measurement started
        // connect all measure devices and signals
        for (QPointer<MeasurementDevice> device : DeviceManager::activeDevicesList){
            connect(this,&MainWindow::measure, device, &MeasurementDevice::queueMeasure);
            connect(device,&MeasurementDevice::measuredValues,fileHandler,&FileHandler::onReceivingValues);
            connect(device,&MeasurementDevice::measureReady,this,&MainWindow::onMeasureReady);
            qDebug()<<"Test MAINWINDOW3";
        }

        // start measurement routine
        //pendingScanParameters = ui->scanValuesHorizontalLayout->count()-2; // beware there are already 2 items in this layout
        int interval = ui->intervalspinbox->value();
        intervalTimer.setInterval(interval);
        qDebug()<<"Test MAINWINDOW";
        connectScanValues(true); // connect
        scanParameterReadyCounter = numberOfScanparameterSelections;
        emit scanInit();
        ui->progressBar->setValue(0);
    }else{ qDebug()<<"Test MAINWINDOW2";
        for (QPointer<MeasurementDevice> device : DeviceManager::activeDevicesList){
            disconnect(this,&MainWindow::measure, device, &MeasurementDevice::queueMeasure);
            disconnect(device,&MeasurementDevice::measuredValues,fileHandler,&FileHandler::onReceivingValues);
            disconnect(device,&MeasurementDevice::measureReady,this,&MainWindow::onMeasureReady);
        }
        connectScanValues(false);
        intervalTimer.stop();
        // put here any command for force quit
        measCycle = 0;
        qDebug() << "emit finished";
        emit finishedMeasurement();
        QMessageBox::warning(this,tr("Attention!"),tr("Measurement was canceled early"),QMessageBox::Ok);
    }
}

void MainWindow::onMeasureReady(QString deviceName, quint64 number){
    measurementReadyCounter--;
    qDebug()<<"Mainw onscan2";
    qDebug() << "onMeasureReady, readyCounter:  "<<measurementReadyCounter << " device: "<<deviceName;
    if (measurementReadyCounter>0){
        qDebug()<<"Mainw onscan3";
        return;
    }
    qDebug() << "measurement ongoing = "<<ongoingMeasurement;
    scanParameterReadyCounter = numberOfScanparameterSelections;
    this->nextInterval();
    qDebug()<<"Mainw onscan4";
    this->probeProgress(0);
    qDebug()<<"Main onMeasureReady";
}

void MainWindow::onScanParamSelReady(QString deviceName, quint64 number){
    qDebug()<<"Mainw onscanparam!";
    if (scanParameterReadyCounter>0){
        scanParameterReadyCounter--;
    }
    if (scanParameterReadyCounter>0){
        return;
    }
    intervalTimer.start();
}

void MainWindow::onTimerTimeout(){
qDebug()<<"Mainw timer!";
    measurementReadyCounter = DeviceManager::activeDevicesList.size();
    emit measure(++measCount);
}

void MainWindow::onFinishedMeasurement(){
    qDebug() << "finished cycle "<< measCycle;
    if (!ui->noLimitCheck->isChecked()){
        // if it is checked, measCycle will not go up and measurements will continue forever
        measCycle++;
    }
    qDebug()<<"int STOP!?";
    intervalTimer.stop();
    for (QPointer<MeasurementDevice> device : DeviceManager::activeDevicesList){
        disconnect(this,&MainWindow::measure, device, &MeasurementDevice::queueMeasure);
        disconnect(device,&MeasurementDevice::measuredValues,fileHandler,&FileHandler::onReceivingValues);
        disconnect(device,&MeasurementDevice::measureReady,this,&MainWindow::onMeasureReady);
    }
    connectScanValues(false);
    ongoingMeasurement = false;
    setUiMeasurementState(ongoingMeasurement);
    if (measCycle < ui->cyclesspinbox->value()){
        onStartMeasurementButtonClicked();
        return;
    }
    measCycle = 0;
    ui->progressBar->setValue(100);
    // put here any command for successful finished measurement
    qDebug() << "emit finished";
    emit finishedMeasurement();
    QMessageBox::information(this, tr("Success!"), tr("Measurement finished"),QMessageBox::Ok);
}

void MainWindow::connectScanValues(bool doConnect){
    qDebug() <<"StartScanValue";
    if (doConnect){
        numberOfScanparameterSelections = ui->scanValuesHorizontalLayout->count()-2;
        qDebug()<<"nextint2";
        if (numberOfScanparameterSelections < 1){
            // if there is no scan value only measurement:
            scanParameterReadyCounter = numberOfScanparameterSelections;
            connect(this, &MainWindow::nextInterval, this, &MainWindow::onFinishedMeasurement);
            qDebug()<<"nexttint";
            intervalTimer.start();
            return;
        }
        for (int i = ui->scanValuesHorizontalLayout->count()-2; i>1 ; i--){
            connect(dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(i)->widget()), &ScanParameterSelection::completedLoop,
                    dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(i-1)->widget()), &ScanParameterSelection::nextScanParameterStep);
            connect(dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(i)->widget()), &ScanParameterSelection::addProgress,
                    dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(i-1)->widget()), &ScanParameterSelection::progressCarry);
            connect(this, &MainWindow::scanInit, dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(i)->widget()), &ScanParameterSelection::scanParameterInit);
            connect(dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(i)->widget()), &ScanParameterSelection::scanParameterReady,this, &MainWindow::onScanParamSelReady);
        }
        connect(this, &MainWindow::probeProgress, dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(ui->scanValuesHorizontalLayout->count()-2)->widget()),
                &ScanParameterSelection::progressCarry);
        connect(this, &MainWindow::scanInit, dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(1)->widget()), &ScanParameterSelection::scanParameterInit);
        connect(dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(1)->widget()), &ScanParameterSelection::scanParameterReady,this, &MainWindow::onScanParamSelReady);
        connect(dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(1)->widget()), &ScanParameterSelection::addProgress,
                this, &MainWindow::onProgressReceived);
        connect(this, &MainWindow::nextInterval,
                dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(ui->scanValuesHorizontalLayout->count()-2)->widget()),
                &ScanParameterSelection::nextScanParameterStep);
        connect(dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(1)->widget()), &ScanParameterSelection::completedLoop,
                this, &MainWindow::onFinishedMeasurement);
    }else{
        if (numberOfScanparameterSelections < 1){
            // if there is no scan value only measurement:
            disconnect(this, &MainWindow::nextInterval, this, &MainWindow::onFinishedMeasurement);
            return;
        }
        for (int i = ui->scanValuesHorizontalLayout->count()-2; i>1 ; i--){
            disconnect(dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(i)->widget()), &ScanParameterSelection::completedLoop,
                       dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(i-1)->widget()), &ScanParameterSelection::nextScanParameterStep);
            disconnect(dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(i)->widget()), &ScanParameterSelection::addProgress,
                    dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(i-1)->widget()), &ScanParameterSelection::progressCarry);
            disconnect(this, &MainWindow::scanInit, dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(i)->widget()), &ScanParameterSelection::scanParameterInit);
            disconnect(dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(i)->widget()), &ScanParameterSelection::scanParameterReady,this, &MainWindow::onScanParamSelReady);
        }
        disconnect(this, &MainWindow::scanInit, dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(1)->widget()), &ScanParameterSelection::scanParameterInit);
        disconnect(dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(1)->widget()), &ScanParameterSelection::scanParameterReady,this, &MainWindow::onScanParamSelReady);
        disconnect(this, &MainWindow::nextInterval,
                dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(ui->scanValuesHorizontalLayout->count()-2)->widget()),
                &ScanParameterSelection::nextScanParameterStep);
        disconnect(dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(1)->widget()), &ScanParameterSelection::completedLoop,
                this, &MainWindow::onFinishedMeasurement);
    }
}

void MainWindow::onProgressReceived(int progress){
    //qDebug() << progress;
    if (progress>100){
        qDebug() << "warning progress > 100% (progress = " << progress << ")";
        progress = 1;
    }
    ui->progressBar->setValue(progress);
}
