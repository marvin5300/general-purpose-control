#include "serialconsole.h"
#include "ui_serialconsole.h"
#include "rs232.h"
#include <QThread>

SerialConsole::SerialConsole(QWidget *parent):
    QFrame(parent),
    ui(new Ui::SerialConsole)
{
    ui->setupUi(this);
}

SerialConsole::~SerialConsole()
{
    delete ui;
}

void SerialConsole::onReceivedMessage(QString message){
    onConnectionStatusChanged(true);
}

void SerialConsole::onConnectionStatusChanged(bool connected){

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
    connect(serialConnection, &RS232::receivedMessage, this, &SerialConsole::onReceivedMessage);

    // connect all send/receive messages
    connect(this, &SerialConsole::scpiCommand, serialConnection, &RS232::sendScpiCommand);
    connect(serialConnection, &RS232::receivedMessage, this, &SerialConsole::onReceivedMessage);

    // after thread start there will be a signal emitted which starts the RS232 makeConnection function
    serialThread->start();
}
