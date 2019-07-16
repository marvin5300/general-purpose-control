#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "measurementdevice.h"
#include "scanparameterselection.h"
#include "devicemanager.h"
#include "settings.h"
#include <QFileDialog>
#include <QPalette>
//#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileHandler = new FileHandler(this);
    connect(fileHandler, &FileHandler::openFileStatus, this, [this](bool open){
        this->ui->fileStatusLabel->setText(open ? "file open" :  "no file");
    });
    this->setWindowTitle("General Purpose Control");
    this->setWindowIcon(QIcon(":/res/tune.png"));
    ui->addAdjustValueButton->setStyleSheet(":!hover{ border-image: url(:/res/plus1.png)}:hover{ border-image: url(:/res/plus2.png);}");
    ui->addDeviceButton->setStyleSheet(":!hover{ border-image: url(:/res/plus1.png)}:hover{ border-image: url(:/res/plus2.png);}");
    ui->progressBar->setValue(0);
    connect(ui->progressBar, &QProgressBar::valueChanged, this, &MainWindow::adjustProgressBarAppearance);
    ui->progressBar->setStyleSheet(lowLevel);
    connect(ui->addAdjustValueButton, &QPushButton::clicked, this, &MainWindow::onAddAdjustValuesButtonClicked);
    connect(ui->addDeviceButton, &QPushButton::clicked, this, &MainWindow::onAddMeasureValuesButtonClicked);
    connect(ui->actionSerial_Console, &QAction::triggered, this, &MainWindow::openSerialConsole);
    DeviceManager::generateInterfaceList();
    connect(ui->actionselect_output_file, &QAction::triggered, this, [this](){
        QString outputFileName = QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("Any File (*)"));
        this->setOutputFile(outputFileName);
    });
    connect(ui->actionopen_settings, &QAction::triggered, this, &MainWindow::onSettingsClicked);
}
//Add_PB->setStyleSheet( "*{border-image: url(:/icons/maximize.bmp);}"
//":pressed{ border-image: url(:/icons/maximize_pressed.bmp);}");

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAddAdjustValuesButtonClicked(){
    ScanParameterSelection *widget = new ScanParameterSelection(this);
    //unsigned int n = ui->setValuesVerticalLayout->count();
    //ui->setValuesVerticalLayout->insertWidget(n-2,widget);
    ui->setValuesVerticalLayout->insertWidget(ui->setValuesVerticalLayout->count()-1,widget);
}

void MainWindow::onAddMeasureValuesButtonClicked(){
    //MeasurementDevice *device = DeviceManager::getDevice("default","default");
    QPointer<MeasurementDevice> device = DeviceManager::getDevice("not selected", "not selected");
    connect(device, &MeasurementDevice::deviceSelectionChange, this, &MainWindow::onDeviceSelectionChange);
    //unsigned int n = ui->measureValuesVerticalLayout->count();
    //ui->measureValuesVerticalLayout->insertWidget(n-2,widget);
    DeviceManager::actualizeDeviceNameModel();
    ui->deviceConfigVerticalLayout->insertWidget(ui->deviceConfigVerticalLayout->count()-1,device);
}

void MainWindow::onDeviceSelectionChange(QPointer<MeasurementDevice> device, QString _newDeviceName, QString _newInterfaceName){
    QPointer<MeasurementDevice> neoDevice = DeviceManager::getDevice(_newDeviceName, _newInterfaceName);
    //unsigned int i = ui->deviceConfigVerticalLayout->indexOf(device);
    ui->deviceConfigVerticalLayout->replaceWidget(device,neoDevice);
    DeviceManager::actualizeDeviceNameModel();
    connect(neoDevice, &MeasurementDevice::deviceSelectionChange, this, &MainWindow::onDeviceSelectionChange);
}

void MainWindow::openSerialConsole(){
    QMainWindow *serialConsoleWindow = new QMainWindow(this);
    serialConsoleWindow->setWindowTitle("Serial Console");
    serialConsoleWindow->setWindowIcon(QIcon(":/res/rs232.png"));
    serialConsoleWindow->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    SerialConsole *serialConsole = new SerialConsole(serialConsoleWindow);
    serialConsole->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    serialConsoleWindow->setCentralWidget(serialConsole);
    serialConsoleWindow->show();
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
