#include "serialconsole.h"
#include "ui_serialconsole.h"

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

}

const QString SerialConsole::getInterfaceName(){
    return "default";
}

const QString SerialConsole::getDeviceName(){
    return "default";
}

void SerialConsole::connectRS232(){
}

void SerialConsole::init(){

}
