#include "settings.h"
#include "ui_settings.h"
#include <QFileDialog>

Settings::Settings(QWidget *parent, QString filePath, Qt::WindowFlags flags) :
    QDialog(parent, flags),
    ui(new Ui::Settings)
{
    this->setWindowTitle("Settings");
    this->setWindowIcon(QIcon(":/res/settings1.png"));
    ui->setupUi(this);
    ui->filePathEdit->setText(filePath);
    connect(ui->deleteFilePathButton, &QPushButton::clicked, ui->filePathEdit, &QLineEdit::clear);
    ui->deleteFilePathButton->setStyleSheet(":!hover{ border-image: url(:/res/close1.png)}:hover{ border-image: url(:/res/close2.png);}");
    connect(ui->openButton, &QPushButton::clicked, this, [this](){
       this->ui->filePathEdit->setText(QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("Any File (*)")));
    });
    ui->buttonBox->button(QDialogButtonBox::Apply)->setEnabled(false);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &Settings::applySettings);
    connect(ui->filePathEdit, &QLineEdit::textChanged, this, &Settings::enableApplyButton);
}

void Settings::enableApplyButton(){
    ui->buttonBox->button(QDialogButtonBox::Apply)->setEnabled(true);
}

void Settings::applySettings(){
    emit setOutputFileName(ui->filePathEdit->text());
}

Settings::~Settings()
{
    delete ui;
}
