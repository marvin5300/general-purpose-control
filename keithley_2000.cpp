#include "keithley_2000.h"
#include "ui_keithley_2000.h"

Keithley_2000::Keithley_2000(QWidget *parent) :
    Keithley_2xxx(parent),
    ui(new Ui::Keithley_2000)
{
    ui->setupUi(this);
    deviceName = "2000";
}

Keithley_2000::~Keithley_2000()
{
    delete ui;
}
