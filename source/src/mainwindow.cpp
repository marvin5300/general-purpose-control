

#include <mainwindow.h>
#include <scanparameterselection.h>
#include <devicemanager.h>
#include <settings.h>

#include <QAction>
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QThread * _consumer, QThread * _producer, QWidget *parent )
    : QMainWindow(parent)
{

    setupUi(this);
    this->setWindowIcon(QIcon(":/ProgramIcon.png"));
    m_consumer = _consumer;
    m_producer = _producer;
    m_prober.setDeviceName("PA200 BlueRay");
    m_prober.connectDeviceToThread(m_consumer, m_producer);
    measurementDelay.setSingleShot(true);
    // set start page
    stackedWidget->setCurrentIndex(PAGE_PROBER);
    // prober visu
    m_ptrProberVisu = new CProberVisu(50, 50, 800, 600, &m_prober, stackedWidget->currentWidget());
    m_ptrProberVisu->setThreads(_consumer, _producer);
    // set read data display
    m_prober.setResponseDisplay(m_ptrProberVisu->getReadDataDisplay());
    m_ptrMeasCtrl = new CMeasurementControl(&m_prober, m_ptrProberVisu->getLabelActState(), m_ptrProberVisu->getPushButtonGoOn());
    m_ptrMeasCtrl->setThreads(_consumer, _producer);
    m_ptrMeasCtrl->setGoOnButton(m_ptrProberVisu->getPushButtonGoOn());
    
    // Measurement devices
    addAdjustValueButton->setStyleSheet(":!hover{ border-image: url(:/plus1.png)}:hover{ border-image: url(:/plus2.png);}");
    addDeviceButton->setStyleSheet(":!hover{ border-image: url(:/plus1.png)}:hover{ border-image: url(:/plus2.png);}");
    progressBar->setValue(0);
    connect(progressBar, &QProgressBar::valueChanged, this, &MainWindow::adjustProgressBarAppearance);
    progressBar->setStyleSheet(lowLevel);

    //connect(&intervalTimer, &QTimer::timeout, this, &MainWindow::onTimerTimeout);
    connect(&measurementDelay, &QTimer::timeout, this, &MainWindow::onTimerTimeout);
    intervalTimer.setSingleShot(true);

    connect(startMeasurementButton, &QPushButton::clicked, this, &MainWindow::onStartMeasurementButtonClicked);
    connect(addAdjustValueButton, &QPushButton::clicked, this, &MainWindow::onAddAdjustValuesButtonClicked);
    connect(addDeviceButton, &QPushButton::clicked, this, &MainWindow::onAddMeasureValuesButtonClicked);
    connect(actionSerial_Console, &QAction::triggered, this, [this](){SerialConsole *console = new SerialConsole(this);});
    DeviceManager::generateInterfaceList();
    // all settings related stuff
    connect(actionopen_settings, &QAction::triggered, this, &MainWindow::onSettingsClicked);

    // all filehandler related stuff
    fileHandler = new FileHandler(this);
    connect(this, &MainWindow::setOutputFile, fileHandler, &FileHandler::setOutputFile);
    connect(this, &MainWindow::finishedMeasurement, fileHandler, &FileHandler::onFinishedMeasurement);
    connect(this, &MainWindow::startMeasurement, fileHandler, &FileHandler::onNewMeasurementStarted);
    connect(fileHandler, &FileHandler::openedFileName, fileStatusLabel, &QLabel::setText);
    connect(actionselect_output_file, &QAction::triggered, this, [this](){
    QString outputFileName = QFileDialog::getSaveFileName(this, tr("Open File"),
                                                              QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
                                                              tr("Any File (*)"),
                                                              nullptr,
                                                              QFileDialog::DontConfirmOverwrite);
        if(!outputFileName.isEmpty()){emit setOutputFile(outputFileName);}
    });
    emit setAutoOutputFile(autoFileCheckbox->isChecked());

    
    initConnections();
    m_ptrProberVisu->requestMeasurementControlData();
    // init measurement devices and scan parameters for idss neasurement
    onAddMeasurementDevices(DRAINSOURCE_LEACKAGE);
 }

MainWindow::~MainWindow()
{
    // stop consumer thread
    m_prober.quitConsumer();
    m_prober.wakeUpConsumer();
    //m_consumer->exit();
    m_consumer->terminate();
    m_consumer->wait();

    // stop producer thread
    m_prober.quitProducer();
    m_prober.wakeUpProducer();
    //m_producer->exit();
    m_producer->terminate();
    m_producer->wait();

}


void MainWindow::initConnections(void)
{
    // MeasCtrl and MainWindow
    // MeasCtrl >> MainWindow
    connect(m_ptrMeasCtrl, &CMeasurementControl::startMeasurement, this, &MainWindow::onStartMeasurementButtonClicked);
    connect(m_ptrMeasCtrl,&CMeasurementControl::stopMeasurement,this,&MainWindow::onStartMeasurementButtonClicked);
    

    // MeasCtrl << MainWindow
    connect(this, &MainWindow::finishedMeasurement, m_ptrMeasCtrl, &CMeasurementControl::on_measurementFinished); 
    connect(this, &MainWindow::ongoingMeasurementChanged, m_ptrMeasCtrl, &CMeasurementControl::on_ongoingMeasurementChanged);
    
    //ProberVisu >> MainWindow
    // connect signals and slots for automatic settings from state machine
    //connect(m_ptrProberVisu, &CProberVisu::deleteMeasurementDevices, this, &MainWindow::onDeletMeasurementDevices);
    //connect(m_ptrProberVisu, &CProberVisu::measurementParam, this, &MainWindow::onAddMeasurementDevices);
   
    
    // proberVisu and prober
    // proberVisu >> prober
    connect(m_ptrProberVisu, &CProberVisu::addCommand, m_prober.getSynchCommProducer(), &CSynchCommProducer::on_addCommand);
    // proberVisu << prober
    connect(&m_prober, &CProberSystem::inZPosition, m_ptrProberVisu,&CProberVisu::on_proberInZPosition);
    connect(&m_prober, &CProberSystem::notInZPosition, m_ptrProberVisu,&CProberVisu::on_proberNotInZPosition);
    connect(&m_prober, &CProberSystem::inXYPosition, m_ptrProberVisu,&CProberVisu::on_proberInXYPosition);
    connect(&m_prober, &CProberSystem::notInXYPosition, m_ptrProberVisu,&CProberVisu::on_proberNotInXYPosition);
    connect(&m_prober, &CDevice::connected, m_ptrProberVisu, &CProberVisu::on_Connected);
    connect(&m_prober, &CDevice::bufferSizeChanged, m_ptrProberVisu, &CProberVisu::on_bufferSizeChanged);void writePositionToTextEdit(CPosition _position);
    connect(&m_prober, &CDevice::error, m_ptrProberVisu, &CProberVisu::on_ErrorMsg);
    connect(&m_prober, &CDevice::warning, m_ptrProberVisu, &CProberVisu::on_WarningMsg);
    connect(&m_prober, &CDevice::information, m_ptrProberVisu, &CProberVisu::on_InformationMsg);
    connect(&m_prober, &CDevice::displayResponse, m_ptrProberVisu, &CProberVisu::on_readData);
    connect(&m_prober, &CProberSystem::actPosition, m_ptrProberVisu->getActPositionVisuSM(),&CPositionVisuXYZ::on_writePositionToTextEdit);

    // m_ptrMeasCtrl and m_prober
    // m_ptrMeasCtrl >> m_prober
    connect(m_ptrMeasCtrl,&CMeasurementControl::requestMoveChuckXY, &m_prober, &CProberSystem::on_requestMoveChuckXY);
    connect(m_ptrMeasCtrl,&CMeasurementControl::requestMoveChuckZ, &m_prober, &CProberSystem::on_requestMoveChuckZ);
    connect(m_ptrMeasCtrl,&CMeasurementControl::requestReadChuckPos, &m_prober, &CProberSystem::on_synchReadChuckPos);
    connect(m_ptrMeasCtrl,&CMeasurementControl::requestInXYPosition, &m_prober, &CProberSystem::on_requestInPosition);
    connect(m_ptrMeasCtrl,&CMeasurementControl::requestInZPosition, &m_prober, &CProberSystem::on_requestInPosition);
    // m_ptrMeasCtrl << m_prober
    connect(&m_prober, &CProberSystem::stopStateMachine, m_ptrMeasCtrl, &CMeasurementControl::on_stopStateMachine);


    // m_ptrMeasCtrl and proberVisu
    // m_ptrMeasCtrl >> proberVisu
    connect(m_ptrMeasCtrl->getStateMachine(), &QStateMachine::finished, m_ptrProberVisu, &CProberVisu::on_stateMachineFinished);
   // connect(m_ptrMeasCtrl, &CMeasurementControl::requestZValue, m_ptrProberVisu, &CProberVisu::on_requestZValue);
    connect(m_ptrMeasCtrl, &CMeasurementControl::stateMachineRunningChanged, m_ptrProberVisu, &CProberVisu::on_stateMachineRunningChanged);
    connect(m_ptrMeasCtrl,&CMeasurementControl::measurePositionChanged, m_ptrProberVisu, &CProberVisu::on_measurementPositionChanged);
    connect(m_ptrMeasCtrl, &CMeasurementControl::informationPopUp, m_ptrProberVisu, &CProberVisu::on_InformationMsg);
    connect(m_ptrMeasCtrl,&CMeasurementControl::warning, m_ptrProberVisu, &CProberVisu::on_WarningMsg);
    connect(m_ptrMeasCtrl,&CMeasurementControl::measurementControlData, m_ptrProberVisu,&CProberVisu::on_measurementControlData);
    // m_ptrMeasCtrl << proberVisu
    connect(m_ptrProberVisu, &CProberVisu::startStateMachine, m_ptrMeasCtrl, &CMeasurementControl::on_startStateMachine);
    connect(m_ptrProberVisu, &CProberVisu::stopStateMachine, m_ptrMeasCtrl, &CMeasurementControl::on_stopStateMachine);
    connect(m_ptrProberVisu, &CProberVisu::paramNameInFileChanged,m_ptrMeasCtrl, &CMeasurementControl::on_parameterNameChanged);
    connect(m_ptrProberVisu, &CProberVisu::zValuePrePos, m_ptrMeasCtrl, &CMeasurementControl::on_zValuePrePosChanged);
    connect(m_ptrProberVisu, &CProberVisu::zValueFinalPos, m_ptrMeasCtrl, &CMeasurementControl::on_zValueFinalPosChanged);
    connect(m_ptrProberVisu, &CProberVisu::changedPosition, m_ptrMeasCtrl,&CMeasurementControl::on_positionChanged);
    connect(m_ptrProberVisu, &CProberVisu::requesMeasCtrlData, m_ptrMeasCtrl, &CMeasurementControl::on_requestMeasurementControlData);

    // m_ptrMeasVtrl >> filehandler
    connect(m_ptrMeasCtrl, &CMeasurementControl::createFile, fileHandler, &FileHandler::setOutputFile);

    // Qthread >> prober
    connect(m_consumer,&QThread::started, &m_prober, &CProberSystem::on_threadStarted);

    
}

// Page changes for stacked widget

void MainWindow::on_pushButton_Logger_clicked()
{
    stackedWidget->setCurrentIndex(LOGGER);

    //device.searchForDevice();
}

void MainWindow::on_pushButton_Measurements_clicked()
{
    stackedWidget->setCurrentIndex(MEASUREMENTS);
}

void MainWindow::on_pushButton_Prober_clicked()
{
    stackedWidget->setCurrentIndex(PAGE_PROBER);
}

void MainWindow::on_pushButton_Open_clicked()
{
     QDesktopServices::openUrl(QUrl("file:///C:/Users/erikj/Documents"));
}

void MainWindow::on_pushButton_MeasDevs_clicked()
{
    stackedWidget->setCurrentIndex(PAGE_MEASUREMENT_DEVS);
}

// MEasurementDevice from Marvin Peter


void MainWindow::onAddAdjustValuesButtonClicked(){
    
    ScanParameterSelection *widget = new ScanParameterSelection(this);
    scanParramWindows.append(widget);
    widget->layout=scanValuesHorizontalLayout; 
    //unsigned int n = ui->scanValuesHorizontalLayout->count();
    //ui->scanValuesHorizontalLayout->insertWidget(n-2,widget);
    scanValuesHorizontalLayout->insertWidget(scanValuesHorizontalLayout->count()-1,widget);
    //connect(widget, &ScanParameterSelection::scanParameterSelectionChanged, device, &Keithley_2410::on_scanParameterSelectionBoxChanged);
    //scanParramWindows.takeAt(0)->deleteLater();
}

void MainWindow::onAddMeasureValuesButtonClicked(){
    //MeasurementDevice *device = DeviceManager::getDevice("default","default");
    QPointer<MeasurementDevice> device = DeviceManager::getDevice("not selected", "not selected");
    device->setParent(this);
    device->layout=deviceConfigHorizontalLayout;
    connect(device, &MeasurementDevice::deviceSelectionChange, this, &MainWindow::onDeviceSelectionChange);
    //unsigned int n = ui->measureValuesVerticalLayout->count();
    //ui->measureValuesVerticalLayout->insertWidget(n-2,widget);
    DeviceManager::actualizeDeviceNameModel();
    deviceConfigHorizontalLayout->insertWidget(deviceConfigHorizontalLayout->count()-1,device);
    //qDebug() << "number of devices" <<  DeviceManager::activeDevicesList.size(); use to get number of active devices
}

void MainWindow::adjustProgressBarAppearance(int value){
    (value>=50) ? progressBar->setStyleSheet(highLevel) :
        progressBar->setStyleSheet(lowLevel);
}

void MainWindow::onStartMeasurementButtonClicked(){
    qDebug() << "start cycle "<< measCycle;
    ongoingMeasurement = !ongoingMeasurement;
    emit ongoingMeasurementChanged(ongoingMeasurement);
    setUiMeasurementState(ongoingMeasurement); // ongoingMeasurement is false at the start of the program
    if (ongoingMeasurement){
         // now it is true when measurement started
        // connect all measure devices and signals
        for (QPointer<MeasurementDevice> device : DeviceManager::activeDevicesList){
            connect(qobject_cast<ScpiDevice *>(device), &ScpiDevice::startMeasurementTimer,this, &MainWindow::onTimerStart);
            connect(this,&MainWindow::measure, device, &MeasurementDevice::queueMeasure);
            connect(device,&MeasurementDevice::measuredValues,fileHandler,&FileHandler::onReceivingValues);
            connect(device,&MeasurementDevice::measureReady,this,&MainWindow::onMeasureReady);
            
            
        }

        // start measurement routine
        //pendingScanParameters = ui->scanValuesHorizontalLayout->count()-2; // beware there are already 2 items in this layout
        int interval = intervalspinbox->value();
        intervalTimer.setInterval(interval);
        measurementDelay.setInterval(interval);
        connectScanValues(true); // connect
        qDebug()<<"Start?";
        scanParameterReadyCounter = numberOfScanparameterSelections;
        emit scanInit();
        progressBar->setValue(0);
    }else{ 
        for (QPointer<MeasurementDevice> device : DeviceManager::activeDevicesList){
            disconnect(this,&MainWindow::measure, device, &MeasurementDevice::queueMeasure);
            disconnect(device,&MeasurementDevice::measuredValues,fileHandler,&FileHandler::onReceivingValues);
            disconnect(device,&MeasurementDevice::measureReady,this,&MainWindow::onMeasureReady);
           if(qobject_cast<Keithley_2410 *>(device))
            {
                qobject_cast<Keithley_2410 *>(device)->switchOutputOff(); // turns output if if function is available
            }
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

void MainWindow::onFinishedMeasurement(){
    qDebug() << "finished cycle "<< measCycle;
    if (!noLimitCheck->isChecked()){
        // if it is checked, measCycle will not go up and measurements will continue forever
        measCycle++;
    }
    intervalTimer.stop();
    for (QPointer<MeasurementDevice> device : DeviceManager::activeDevicesList){
        disconnect(this,&MainWindow::measure, device, &MeasurementDevice::queueMeasure);
        disconnect(device,&MeasurementDevice::measuredValues,fileHandler,&FileHandler::onReceivingValues);
        disconnect(device,&MeasurementDevice::measureReady,this,&MainWindow::onMeasureReady);
        if(qobject_cast<Keithley_2410 *>(device))
        {
            qobject_cast<Keithley_2410 *>(device)->switchOutputOff(); // turns output if if function is available
        }

    }
    connectScanValues(false);
    ongoingMeasurement = false;
    setUiMeasurementState(ongoingMeasurement);
    if (measCycle < cyclesspinbox->value()){
        onStartMeasurementButtonClicked();
        return;
    }
    measCycle = 0;
    progressBar->setValue(100);
    // put here any command for successful finished measurement
    qDebug() << "emit finished";
    emit finishedMeasurement();
    //QMessageBox::information(this, tr("Success!"), tr("Measurement finished"),QMessageBox::Ok);
}


// public slots
void MainWindow::onDeviceSelectionChange(QPointer<MeasurementDevice> device, QString _newDeviceName, QString _newInterfaceName){
    QPointer<MeasurementDevice> neoDevice = DeviceManager::getDevice(_newDeviceName, _newInterfaceName);
    neoDevice->setParent(this);
    neoDevice->layout=deviceConfigHorizontalLayout;
    //unsigned int i = ui->deviceConfigHorizontalLayout->indexOf(device);
    deviceConfigHorizontalLayout->replaceWidget(device,neoDevice);
    DeviceManager::actualizeDeviceNameModel();
    connect(neoDevice, &MeasurementDevice::deviceSelectionChange, this, &MainWindow::onDeviceSelectionChange);
}

void MainWindow::onSettingsClicked(){
    Settings *dialog = new Settings(this, fileHandler->getFilePath(),DeviceManager::_masks);
    connect(dialog, &Settings::setOutputFileName, fileHandler, &FileHandler::setOutputFile);
    connect(dialog, &Settings::setSerialMask, this, &MainWindow::setSerialMask);
    dialog->show();
}

void MainWindow::onProgressReceived(int progress){
    //qDebug() << progress;
    if (progress>100){
        qDebug() << "warning progress > 100% (progress = " << progress << ")";
        progress = 1;
    }
    progressBar->setValue(progress);
}

void MainWindow::onMeasureReady(QString deviceName, quint64 number){
    measurementReadyCounter--;
    if (measurementReadyCounter>0){
        return;
    }
    qDebug() << "measurement ongoing = "<<ongoingMeasurement;
    scanParameterReadyCounter = numberOfScanparameterSelections;
    this->nextInterval();
    this->probeProgress(0);
}

void MainWindow::onScanParamSelReady(QString deviceName, quint64 number){
    if (scanParameterReadyCounter>0){
        scanParameterReadyCounter--;
    }
    if (scanParameterReadyCounter>0){
        return;
    }
    intervalTimer.start();
}

void MainWindow::onTimerTimeout(){
    measurementReadyCounter = DeviceManager::activeDevicesList.size();
    qDebug() << "timer timeout";
    emit measure(++measCount);
}

void MainWindow::setUiMeasurementState(bool _ongoingMeasurement){
    menuSettings->setDisabled(_ongoingMeasurement);
    devicesGroupBox->setDisabled(_ongoingMeasurement);
    scanValueGroupBox->setDisabled(_ongoingMeasurement);
    noLimitCheck->setDisabled(_ongoingMeasurement);
    intervalLabel->setDisabled(_ongoingMeasurement);
    intervalspinbox->setDisabled(_ongoingMeasurement);
    startMeasurementButton->setText(_ongoingMeasurement ? "force stop" : "start measurement");
}

void MainWindow::setSerialMask(QStringList masks){
    DeviceManager::setSerialMask(masks);
}

void MainWindow::onDeletMeasurementDevices(void)
{
    if(!DeviceManager::activeDevicesList.isEmpty())
    {
        int len = DeviceManager::activeDevicesList.size();
        // delete devices
        for(int i = 0; i < len; i++)
        {
            DeviceManager::activeDevicesList.takeFirst()->exit();
        } 
    }
    
    if(!scanParramWindows.isEmpty())
    {
        int windowsLen = scanParramWindows.size();
        // delete scanparamselections
        for(int i = 0; i < windowsLen; i++)
        {
         
         delete scanParramWindows.at(i);
         scanParramWindows.removeAt(i);
        } 
    }
    
}

void MainWindow::onAddMeasurementDevices(int _measurementParam)
{
    QPointer<MeasurementDevice> device;
    ScanParameterSelection *widget;

    switch(_measurementParam){
        case THRESHOLD_VOLTAGE:
            // add KEYLIGHT2410 Device
            device = DeviceManager::getDevice("2410","ttyUSB0");
            device->setParent(this);
            device->layout=deviceConfigHorizontalLayout;
            connect(device, &MeasurementDevice::deviceSelectionChange, this, &MainWindow::onDeviceSelectionChange);
            DeviceManager::actualizeDeviceNameModel();
            deviceConfigHorizontalLayout->insertWidget(deviceConfigHorizontalLayout->count()-1,device);
            // configure params from code
            device->setMeasureParam(DeviceParameterConstraint("V", 0.0, 0.0, READWRITE)); // select current source and voltage sense
            // connect state machine and measurementdevice
            //connect(m_ptrMeasCtrl,&CMeasurementControl::startMeasurement, this, &MainWindow::onStartMeasurementButtonClicked);
            // add scan parameter
            widget = new ScanParameterSelection(this);
            scanParramWindows.append(widget);
            widget->layout=scanValuesHorizontalLayout; 
            scanValuesHorizontalLayout->insertWidget(scanValuesHorizontalLayout->count()-1,widget);
            // set scanparams
            widget->setScanparameters("2410", "I", "ramped", 41, -20.0, 20.0);
            widget->scanParameterInit();
            break;
        case DRAINSOURCE_LEACKAGE:
            // add KEYLIGHT2410 Device
            device = DeviceManager::getDevice("2410","ttyUSB0");
            device->setParent(this);
            device->layout=deviceConfigHorizontalLayout;
            connect(device, &MeasurementDevice::deviceSelectionChange, this, &MainWindow::onDeviceSelectionChange);
            DeviceManager::actualizeDeviceNameModel();
            deviceConfigHorizontalLayout->insertWidget(deviceConfigHorizontalLayout->count()-1,device);
            // configure params from code
            device->setMeasureParam(DeviceParameterConstraint("V", 0.0, 0.0, READWRITE)); // select voltage source
             device->setMeasureParam(DeviceParameterConstraint("I", 0.0, 0.0, READWRITE)); // select current sense
            // connect state machine and measurementdevice
            //connect(m_ptrMeasCtrl,&CMeasurementControl::startMeasurement, this, &MainWindow::onStartMeasurementButtonClicked);
            // add scan parameter
            widget = new ScanParameterSelection(this);
            scanParramWindows.append(widget);
            widget->layout=scanValuesHorizontalLayout; 
            scanValuesHorizontalLayout->insertWidget(scanValuesHorizontalLayout->count()-1,widget);
            // set scanparams
            widget->setScanparameters("2410", "V", "ramp", 37, 0.0, 36.0);
            widget->scanParameterInit();
            break;
        case GATESOURCE_LECKAGE:
            // add KEYLIGHT2410 Device
            device = DeviceManager::getDevice("2410","ttyUSB0");
            device->setParent(this);
            device->layout=deviceConfigHorizontalLayout;
            connect(device, &MeasurementDevice::deviceSelectionChange, this, &MainWindow::onDeviceSelectionChange);
            DeviceManager::actualizeDeviceNameModel();
            deviceConfigHorizontalLayout->insertWidget(deviceConfigHorizontalLayout->count()-1,device);
            // configure params from code
            device->setMeasureParam(DeviceParameterConstraint("V", 0.0, 0.0, READWRITE)); // select voltage source
             device->setMeasureParam(DeviceParameterConstraint("I", 0.0, 0.0, READWRITE)); // select current sense
            // connect state machine and measurementdevice
            //connect(m_ptrMeasCtrl,&CMeasurementControl::startMeasurement, this, &MainWindow::onStartMeasurementButtonClicked);
            // add scan parameter
            widget = new ScanParameterSelection(this);
            scanParramWindows.append(widget);
            widget->layout=scanValuesHorizontalLayout; 
            scanValuesHorizontalLayout->insertWidget(scanValuesHorizontalLayout->count()-1,widget);
            // set scanparams
            widget->setScanparameters("2410", "V", "ramp", 41, -20, 20.0);
            widget->scanParameterInit();
            break;
        case INPUT_CAPACITANCE:
            device = DeviceManager::getDevice("2410","ttyUSB0");
            device->setParent(this);
            device->layout=deviceConfigHorizontalLayout;
            connect(device, &MeasurementDevice::deviceSelectionChange, this, &MainWindow::onDeviceSelectionChange);
            DeviceManager::actualizeDeviceNameModel();
            deviceConfigHorizontalLayout->insertWidget(deviceConfigHorizontalLayout->count()-1,device);
            // configure params from code
            device->setMeasureParam(DeviceParameterConstraint("V", 0.0, 0.0, READWRITE)); // select voltage source
            // add ST2826
            device = DeviceManager::getDevice("ST2826","ttyUSB2");
            device->setParent(this);
            device->layout=deviceConfigHorizontalLayout;
            connect(device, &MeasurementDevice::deviceSelectionChange, this, &MainWindow::onDeviceSelectionChange);
            DeviceManager::actualizeDeviceNameModel();
            deviceConfigHorizontalLayout->insertWidget(deviceConfigHorizontalLayout->count()-1,device);
            // configure params from code
            device->setMeasureParam(DeviceParameterConstraint("C,x", 0.0, 0.0, READONLY)); // select voltage source
            // add scan parameter
            widget = new ScanParameterSelection(this);
            scanParramWindows.append(widget);
            widget->layout=scanValuesHorizontalLayout; 
            scanValuesHorizontalLayout->insertWidget(scanValuesHorizontalLayout->count()-1,widget);
            // set scanparams
            widget->setScanparameters("2410", "V", "ramp", 31, 0.0, 30);

            widget = new ScanParameterSelection(this);
            scanParramWindows.append(widget);
            widget->layout=scanValuesHorizontalLayout; 
            scanValuesHorizontalLayout->insertWidget(scanValuesHorizontalLayout->count()-1,widget);
            // set scanparams
            widget->setScanparameters("ST2826", "F", "fixed", 0, 1000000.0, 20.0); // min val as fixed val
            widget->scanParameterInit();
            break;
        case OUTPUT_CAPACITANCE:
            break;
        case FEEDBACK_CAPACITANCE:
            break;
    }
}

// private 

void MainWindow::connectScanValues(bool doConnect){
    if (doConnect){
        numberOfScanparameterSelections = scanValuesHorizontalLayout->count()-2;
        if (numberOfScanparameterSelections < 1){
            // if there is no scan value only measurement:
            scanParameterReadyCounter = numberOfScanparameterSelections;
            connect(this, &MainWindow::nextInterval, this, &MainWindow::onFinishedMeasurement);
            intervalTimer.start();
            return;
        }
        for (int i = scanValuesHorizontalLayout->count()-2; i>1 ; i--){
            connect(dynamic_cast<ScanParameterSelection *>(scanValuesHorizontalLayout->itemAt(i)->widget()), &ScanParameterSelection::completedLoop,
                    dynamic_cast<ScanParameterSelection *>(scanValuesHorizontalLayout->itemAt(i-1)->widget()), &ScanParameterSelection::nextScanParameterStep);
            connect(dynamic_cast<ScanParameterSelection *>(scanValuesHorizontalLayout->itemAt(i)->widget()), &ScanParameterSelection::addProgress,
                    dynamic_cast<ScanParameterSelection *>(scanValuesHorizontalLayout->itemAt(i-1)->widget()), &ScanParameterSelection::progressCarry);
            connect(this, &MainWindow::scanInit, dynamic_cast<ScanParameterSelection *>(scanValuesHorizontalLayout->itemAt(i)->widget()), &ScanParameterSelection::scanParameterInit);
            connect(dynamic_cast<ScanParameterSelection *>(scanValuesHorizontalLayout->itemAt(i)->widget()), &ScanParameterSelection::scanParameterReady,this, &MainWindow::onScanParamSelReady);
        }
        connect(this, &MainWindow::probeProgress, dynamic_cast<ScanParameterSelection *>(scanValuesHorizontalLayout->itemAt(scanValuesHorizontalLayout->count()-2)->widget()),
                &ScanParameterSelection::progressCarry);
        connect(this, &MainWindow::scanInit, dynamic_cast<ScanParameterSelection *>(scanValuesHorizontalLayout->itemAt(1)->widget()), &ScanParameterSelection::scanParameterInit);
        connect(dynamic_cast<ScanParameterSelection *>(scanValuesHorizontalLayout->itemAt(1)->widget()), &ScanParameterSelection::scanParameterReady,this, &MainWindow::onScanParamSelReady);
        connect(dynamic_cast<ScanParameterSelection *>(scanValuesHorizontalLayout->itemAt(1)->widget()), &ScanParameterSelection::addProgress,
                this, &MainWindow::onProgressReceived);
        connect(this, &MainWindow::nextInterval,
                dynamic_cast<ScanParameterSelection *>(scanValuesHorizontalLayout->itemAt(scanValuesHorizontalLayout->count()-2)->widget()),
                &ScanParameterSelection::nextScanParameterStep);
        connect(dynamic_cast<ScanParameterSelection *>(scanValuesHorizontalLayout->itemAt(1)->widget()), &ScanParameterSelection::completedLoop,
                this, &MainWindow::onFinishedMeasurement);
    }else{ qDebug()<<"Test2";
        if (numberOfScanparameterSelections < 1){
            // if there is no scan value only measurement:
            disconnect(this, &MainWindow::nextInterval, this, &MainWindow::onFinishedMeasurement);
            return;
        }
        for (int i = scanValuesHorizontalLayout->count()-2; i>1 ; i--){
            disconnect(dynamic_cast<ScanParameterSelection *>(scanValuesHorizontalLayout->itemAt(i)->widget()), &ScanParameterSelection::completedLoop,
                       dynamic_cast<ScanParameterSelection *>(scanValuesHorizontalLayout->itemAt(i-1)->widget()), &ScanParameterSelection::nextScanParameterStep);
            disconnect(dynamic_cast<ScanParameterSelection *>(scanValuesHorizontalLayout->itemAt(i)->widget()), &ScanParameterSelection::addProgress,
                    dynamic_cast<ScanParameterSelection *>(scanValuesHorizontalLayout->itemAt(i-1)->widget()), &ScanParameterSelection::progressCarry);
            disconnect(this, &MainWindow::scanInit, dynamic_cast<ScanParameterSelection *>(scanValuesHorizontalLayout->itemAt(i)->widget()), &ScanParameterSelection::scanParameterInit);
            disconnect(dynamic_cast<ScanParameterSelection *>(scanValuesHorizontalLayout->itemAt(i)->widget()), &ScanParameterSelection::scanParameterReady,this, &MainWindow::onScanParamSelReady);
        }
        disconnect(this, &MainWindow::scanInit, dynamic_cast<ScanParameterSelection *>(scanValuesHorizontalLayout->itemAt(1)->widget()), &ScanParameterSelection::scanParameterInit);
        disconnect(dynamic_cast<ScanParameterSelection *>(scanValuesHorizontalLayout->itemAt(1)->widget()), &ScanParameterSelection::scanParameterReady,this, &MainWindow::onScanParamSelReady);
        disconnect(this, &MainWindow::nextInterval,
                dynamic_cast<ScanParameterSelection *>(scanValuesHorizontalLayout->itemAt(scanValuesHorizontalLayout->count()-2)->widget()),
                &ScanParameterSelection::nextScanParameterStep);
        disconnect(dynamic_cast<ScanParameterSelection *>(scanValuesHorizontalLayout->itemAt(1)->widget()), &ScanParameterSelection::completedLoop,
                this, &MainWindow::onFinishedMeasurement);
    }
}

void MainWindow::onTimerStart(void){
    measurementDelay.start();
}