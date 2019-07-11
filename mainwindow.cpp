#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <rs232.h>
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->connectButton, &QPushButton::clicked, this, &MainWindow::onConnectButtonClicked);
    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::onSendButtonClicked);
    ui->deviceSelectBox->insertItems(0,devices);
    ui->portNameEdit->set
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onConnectButtonClicked(){
    if (ui->connectButton->text()=="connect"){
        connectRS232(ui->portNameEdit->text(), 9600, ui->deviceSelectBox->currentText());
    }else{
        emit disconnectRS232(ui->portNameEdit->text());
    }
}

void MainWindow::onSendButtonClicked(){
    emit scpiCommand(ui->SCPImessageEdit->text());
}

void MainWindow::onReceivedMessage(QString message){
    ui->outputTextEdit->appendPlainText(QString(message));
}

void MainWindow::onReceivedConnectionStatus(bool connected, QString portName){
    if (connected==true){
        ui->connectButton->setText("disconnect");
        ui->portNameEdit->setEnabled(false);
        ui->deviceSelectBox->setEnabled(false);
    }else{
        ui->connectButton->setText("connect");
        ui->portNameEdit->setEnabled(true);
        ui->deviceSelectBox->setEnabled(true);
        ui->outputTextEdit->appendPlainText(QString("device on port "+portName+" disconnected or failed to connect"));
    }
}

void MainWindow::connectRS232(QString portName, quint32 baudRate, QString deviceName) {
    // here is where the magic threading happens look closely
    QThread *serialThread = new QThread();
    RS232 *serialConnection = new RS232(portName, baudRate, deviceName, serialThread);
    serialConnection->moveToThread(serialThread);
    // connect all signals about quitting
    connect(serialThread, &QThread::finished, serialThread, &QThread::deleteLater);
    // connect all signals not coming from Daemon to gps
    connect(serialThread, &QThread::started, serialConnection, &RS232::makeConnection);
    //connect(serialConnection, &RS232::serialRestart, this, &MainWindow::connectRS232);
    connect(serialConnection, &RS232::connectionStatus, this, &MainWindow::onReceivedConnectionStatus);
    connect(this, &MainWindow::disconnectRS232, serialConnection, &RS232::closeConnection);

    // connect all send/receive messages
    connect(this, &MainWindow::scpiCommand, serialConnection, &RS232::sendScpiCommand);
    connect(serialConnection, &RS232::receivedMessage, this, &MainWindow::onReceivedMessage);

    // after thread start there will be a signal emitted which starts the RS232 makeConnection function
    serialThread->start();
}
