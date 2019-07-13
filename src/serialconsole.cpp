#include "serialconsole.h"
#include "ui_serialconsole.h"

SerialConsole::SerialConsole(QWidget *parent) :
    MeasurementDevice(""),
    ui(new Ui::SerialConsole)
{
    ui->setupUi(this);
}

SerialConsole::~SerialConsole()
{
    delete ui;
}
