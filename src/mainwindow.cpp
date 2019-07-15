#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "measurementdevice.h"
#include "scanparameterselection.h"
#include "devicemanager.h"
//#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("General Purpose Control");
    this->setWindowIcon(QIcon(":/res/tune.png"));
    ui->addAdjustValueButton->setStyleSheet(":!hover{ border-image: url(:/res/plus1.png)}:hover{ border-image: url(:/res/plus2.png);}");
    ui->addDeviceButton->setStyleSheet(":!hover{ border-image: url(:/res/plus1.png)}:hover{ border-image: url(:/res/plus2.png);}");
    connect(ui->addAdjustValueButton, &QPushButton::clicked, this, &MainWindow::onAddAdjustValuesButtonClicked);
    connect(ui->addDeviceButton, &QPushButton::clicked, this, &MainWindow::onAddMeasureValuesButtonClicked);
    connect(ui->actionSerial_Console, &QAction::triggered, this, &MainWindow::openSerialConsole);
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

    //unsigned int n = ui->measureValuesVerticalLayout->count();
    //ui->measureValuesVerticalLayout->insertWidget(n-2,widget);
    DeviceManager::actualizeDeviceNameModel();
    ui->deviceConfigVerticalLayout->insertWidget(ui->deviceConfigVerticalLayout->count()-1,device);
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
