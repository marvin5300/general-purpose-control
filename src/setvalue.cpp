#include "setvalue.h"
#include "ui_setvalue.h"

SetValue::SetValue(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SetValue)
{
    ui->setupUi(this);
    this->setFrameShadow(QFrame::Plain);
    this->setFrameShape(QFrame::StyledPanel);
    this->setMidLineWidth(1);
    ui->closeButton->setStyleSheet(":!hover{ border-image: url(:/res/close1.png)}:hover{ border-image: url(:/res/close2.png);}");
    connect(ui->closeButton, &QPushButton::clicked, this, &SetValue::deleteLater);
}

SetValue::~SetValue()
{
    delete ui;
}
