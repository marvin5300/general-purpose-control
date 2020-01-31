#include "serialconsole.h"
#include "ui_serialconsole.h"
#include "rs232.h"
#include <QThread>

SerialConsole::SerialConsole(QWidget *parent, Qt::WindowFlags flags):
    QDialog(parent,flags),
    ui(new Ui::SerialConsole)
{
    ui->setupUi(this);
    setWindowTitle("Serial Console");
    setWindowIcon(QIcon(":/res/rs232.png"));
    connect(ui->connectButton, &QPushButton::clicked, this, &SerialConsole::onConnectButtonClicked);
    connect(ui->sendButton, &QPushButton::clicked, this, &SerialConsole::onSendButtonClicked);
    raise();
    show();
}

SerialConsole::~SerialConsole()
{
    closeConnection();
    delete ui;
}

void SerialConsole::onReceivedMessage(QString message){
    onConnectionStatusChanged(true);
    ui->outputTextEdit->appendPlainText(QString(message));
}

void SerialConsole::onConnectionStatusChanged(bool connected){
    QString unconn = "color: darkred;";
    QString conn = "color: darkgreen;";
    if (connected){
        ui->baudRateEdit->setStyleSheet(conn);
        ui->connectButton->setStyleSheet(conn);
        ui->portNameEdit->setStyleSheet(conn);
    }else{
        ui->baudRateEdit->setStyleSheet(unconn);
        ui->connectButton->setStyleSheet(unconn);
        ui->portNameEdit->setStyleSheet(unconn);
    }
}

void SerialConsole::onSendButtonClicked(){
    emit scpiCommand(ui->SCPImessageEdit->text());
}

void SerialConsole::onConnectButtonClicked(){
    bool ok = false;
    quint32 baudRate = ui->baudRateEdit->text().toUInt(&ok);
    if (!ok){
        return;
    }
    connectRS232(ui->portNameEdit->text(), baudRate);
}

void SerialConsole::connectRS232(QString _interfaceName, quint32 _baudRate) {
    // here is where the magic threading happens look closely
    QThread *serialThread = new QThread();
    RS232 *serialConnection = new RS232(_interfaceName, _baudRate);
    serialConnection->moveToThread(serialThread);
    // connect all signals about quitting
    connect(serialThread, &QThread::finished, serialThread, &QThread::deleteLater);
    connect(serialThread, &QThread::started, serialConnection, &RS232::makeConnection);
    //connect(serialConnection, &RS232::serialRestart, this, &MainWindow::connectRS232);
    connect(serialConnection, &RS232::connectionStatus, this, &SerialConsole::onConnectionStatusChanged);

    // connect all send/receive messages
    connect(this, &SerialConsole::scpiCommand, serialConnection, &RS232::sendScpiCommand);
    connect(serialConnection, &RS232::receivedMessage, this, &SerialConsole::onReceivedMessage);

    // after thread start there will be a signal emitted which starts the RS232 makeConnection function
    serialThread->start();
}
