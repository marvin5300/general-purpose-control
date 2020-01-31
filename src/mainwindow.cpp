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
    this->setWindowIcon(QIcon(":/res/tune.png"));
    ui->addAdjustValueButton->setStyleSheet(":!hover{ border-image: url(:/res/plus1.png)}:hover{ border-image: url(:/res/plus2.png);}");
    ui->addDeviceButton->setStyleSheet(":!hover{ border-image: url(:/res/plus1.png)}:hover{ border-image: url(:/res/plus2.png);}");
    ui->progressBar->setValue(0);
    connect(ui->progressBar, &QProgressBar::valueChanged, this, &MainWindow::adjustProgressBarAppearance);
    ui->progressBar->setStyleSheet(lowLevel);

    connect(&intervalTimer, &QTimer::timeout, this,
            [this](){
                this->measure(++measCount);
                this->nextInterval();
                this->probeProgress(0);
            });
    intervalTimer.setSingleShot(false);

    connect(ui->startMeasurementButton, &QPushButton::clicked, this, &MainWindow::onStartMeasurementButtonClicked);
    connect(ui->addAdjustValueButton, &QPushButton::clicked, this, &MainWindow::onAddAdjustValuesButtonClicked);
    connect(ui->addDeviceButton, &QPushButton::clicked, this, &MainWindow::onAddMeasureValuesButtonClicked);
    connect(ui->actionSerial_Console, &QAction::triggered, this, [this](){SerialConsole *console = new SerialConsole(this);});
    DeviceManager::generateInterfaceList();

    // all settings related stuff
    connect(ui->actionopen_settings, &QAction::triggered, this, &MainWindow::onSettingsClicked);

    // all filehandler related stuff
    fileHandler = new FileHandler(this);
    connect(fileHandler, &FileHandler::openFileStatus, this, [this](bool open){
        this->ui->fileStatusLabel->setText(open ? fileHandler->getFileName() :  "no file");
    });
    connect(this, &MainWindow::setOutputFile, fileHandler, &FileHandler::setOutputFile);
    connect(ui->actionselect_output_file, &QAction::triggered, this, [this](){
        QString outputFileName = QFileDialog::getSaveFileName(this, tr("Open File"),
                                                              QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
                                                              tr("Any File (*)"),
                                                              nullptr,
                                                              QFileDialog::DontConfirmOverwrite);
        if(!outputFileName.isEmpty()){this->setOutputFile(outputFileName);}
    });
}
//Add_PB->setStyleSheet( "*{border-image: url(:/icons/maximize.bmp);}"
//":pressed{ border-image: url(:/icons/maximize_pressed.bmp);}");

MainWindow::~MainWindow()
{
    delete ui;
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
    Settings *dialog = new Settings(this, fileHandler->getFilePath());
    connect(dialog, &Settings::setOutputFileName, fileHandler, &FileHandler::setOutputFile);
    dialog->show();
}

void MainWindow::adjustProgressBarAppearance(int value){
    (value>=50) ? ui->progressBar->setStyleSheet(highLevel) :
        ui->progressBar->setStyleSheet(lowLevel);
}

void MainWindow::setUiMeasurementState(bool _ongoingMeasurement){
    ui->menuSettings->setDisabled(_ongoingMeasurement);
    ongoingMeasurement = _ongoingMeasurement;
    ui->devicesGroupBox->setDisabled(_ongoingMeasurement);
    ui->scanValueGroupBox->setDisabled(_ongoingMeasurement);
    ui->noLimitCheck->setDisabled(_ongoingMeasurement);
    ui->intervalLabel->setDisabled(_ongoingMeasurement);
    ui->intervalLineEdit->setDisabled(_ongoingMeasurement);
    ui->startMeasurementButton->setText(_ongoingMeasurement ? "force stop" : "start measurement");
}

void MainWindow::onStartMeasurementButtonClicked(){
    setUiMeasurementState(!ongoingMeasurement); // ongoingMeasurement is false at the start of the program
    if (ongoingMeasurement){ // now it is true when measurement started
        // start measurement routine
        //pendingScanParameters = ui->scanValuesHorizontalLayout->count()-2; // beware there are already 2 items in this layout
        connectScanValues(true); // connect
        bool ok = false;
        int interval = ui->intervalLineEdit->text().toInt(&ok);
        intervalTimer.setInterval(ok ? interval : 500);
        if (!ok){
            int button = QMessageBox::warning(this,tr("Could not parse Interval to int"),
                                         tr("Set Interval to 500 ms instead!"),
                                         QMessageBox::Ok, QMessageBox::Abort);
            ok = (button==QMessageBox::Ok);
            emit scanInit();
            ui->progressBar->setValue(0);
        }
        if (!ok){
            onStartMeasurementButtonClicked();
            return;
        }
        intervalTimer.start();
    }else{
        connectScanValues(false);
        intervalTimer.stop();
        // put here any command for force quit
        QMessageBox::warning(this,tr("Attention!"),tr("Measurement was canceled early"),QMessageBox::Ok);
    }
}

void MainWindow::finishedMeasurement(){
    intervalTimer.stop();
    connectScanValues(false);
    ongoingMeasurement = false;
    setUiMeasurementState(ongoingMeasurement);
    ui->progressBar->setValue(100);
    // put here any command for successful finished measurement
    QMessageBox::information(this, tr("Success!"), tr("Measurement finished"),QMessageBox::Ok);
}

void MainWindow::connectScanValues(bool doConnect){
    if (doConnect){
        for (int i = ui->scanValuesHorizontalLayout->count()-2; i>1 ; i--){
            connect(dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(i)->widget()), &ScanParameterSelection::completedLoop,
                    dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(i-1)->widget()), &ScanParameterSelection::nextScanParameterStep);
            connect(dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(i)->widget()), &ScanParameterSelection::addProgress,
                    dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(i-1)->widget()), &ScanParameterSelection::progressCarry);
            connect(this, &MainWindow::scanInit, dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(i)->widget()), &ScanParameterSelection::scanParameterInit);
        }
        connect(this, &MainWindow::probeProgress, dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(ui->scanValuesHorizontalLayout->count()-2)->widget()),
                &ScanParameterSelection::progressCarry);
        connect(this, &MainWindow::scanInit, dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(1)->widget()), &ScanParameterSelection::scanParameterInit);
        connect(dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(1)->widget()), &ScanParameterSelection::addProgress,
                this, &MainWindow::onProgressReceived);
        connect(this, &MainWindow::nextInterval,
                dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(ui->scanValuesHorizontalLayout->count()-2)->widget()),
                &ScanParameterSelection::nextScanParameterStep);
        connect(dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(1)->widget()), &ScanParameterSelection::completedLoop,
                this, &MainWindow::finishedMeasurement);
    }else{
        for (int i = ui->scanValuesHorizontalLayout->count()-2; i>1 ; i--){
            disconnect(dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(i)->widget()), &ScanParameterSelection::completedLoop,
                       dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(i-1)->widget()), &ScanParameterSelection::nextScanParameterStep);
            disconnect(dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(i)->widget()), &ScanParameterSelection::addProgress,
                    dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(i-1)->widget()), &ScanParameterSelection::progressCarry);
            disconnect(this, &MainWindow::scanInit, dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(i)->widget()), &ScanParameterSelection::scanParameterInit);
        }
        disconnect(this, &MainWindow::scanInit, dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(1)->widget()), &ScanParameterSelection::scanParameterInit);
        disconnect(this, &MainWindow::nextInterval,
                dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(ui->scanValuesHorizontalLayout->count()-2)->widget()),
                &ScanParameterSelection::nextScanParameterStep);
        disconnect(dynamic_cast<ScanParameterSelection *>(ui->scanValuesHorizontalLayout->itemAt(1)->widget()), &ScanParameterSelection::completedLoop,
                this, &MainWindow::finishedMeasurement);
    }
}

void MainWindow::onScanParameterReceived(MeasurementDevice *device, DeviceParameterConstraint constraint){
    /*loopDevices.insert(constraint.name, device);
    loopParameters.insert(constraint.name, constraint);
    if (pendingScanParameters==0){
        qDebug() << "error more scan parameters received than requested!!";
    }
    pendingScanParameters--;
    if (pendingScanParameters==0){
    }*/
}

void MainWindow::onProgressReceived(int progress){
    //qDebug() << progress;
    if (progress>100){
        qDebug() << "warning progress > 100% (progress = " << progress << ")";
        progress = 1;
    }
    ui->progressBar->setValue(progress);
}
