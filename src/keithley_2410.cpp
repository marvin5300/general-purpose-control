#include "keithley_2410.h"
#include "ui_keithley_2410.h"

Keithley_2410::Keithley_2410(QWidget *parent) :
    Keithley_2xxx(parent),
    ui(new Ui::Keithley_2410)
{
    ui->setupUi(this);
    deviceName = "2410";
}

Keithley_2410::~Keithley_2410()
{
    delete ui;
}
