#include "settings.h"
#include "ui_settings.h"
#include <QFileDialog>
#include <QStandardPaths>
#include <QDebug>

Settings::Settings(QWidget *parent, QString filePath, QStringList masks, Qt::WindowFlags flags) :
    QDialog(parent, flags),
    ui(new Ui::Settings)
{
    this->setWindowTitle("Settings");
    this->setWindowIcon(QIcon(":/settings1.png"));
    ui->setupUi(this);
    ui->filePathEdit->setText(filePath);
    connect(ui->deleteFilePathButton, &QPushButton::clicked, ui->filePathEdit, &QLineEdit::clear);
    ui->deleteFilePathButton->setStyleSheet(":!hover{ border-image: url(:/close1.png)}:hover{ border-image: url(:/close2.png);}");
    connect(ui->openButton, &QPushButton::clicked, this, [this](){
       this->ui->filePathEdit->setText(QFileDialog::getSaveFileName(this, tr("Open File"),
                                                                    QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
                                                                    tr("Any File (*)"),
                                                                    nullptr,
                                                                    QFileDialog::DontConfirmOverwrite));
    });
    ui->buttonBox->button(QDialogButtonBox::Apply)->setEnabled(false);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &Settings::applySettings);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, [this](){ui->buttonBox->button(QDialogButtonBox::Apply)->setDisabled(true);});
    connect(ui->filePathEdit, &QLineEdit::textChanged, this, &Settings::enableApplyButton);
    for (auto child : ui->groupBox->children()){
        if (QCheckBox *box = qobject_cast<QCheckBox *>(child)){
            box->setChecked(false);
            for (auto mask : masks){
                qDebug() << "mask: " << mask;
                qDebug() << "text: " << box->text();
                if (box->text().contains(mask)){
                    box->setChecked(true);
                }
            }
            connect(box,&QCheckBox::clicked,this,&Settings::enableApplyButton);
        }
    }
}

void Settings::enableApplyButton(){
    ui->buttonBox->button(QDialogButtonBox::Apply)->setEnabled(true);
}

void Settings::applySettings(){
    emit setOutputFileName(ui->filePathEdit->text());
    QStringList masks;
    for (auto child : ui->groupBox->children()){
        if (QCheckBox *box = dynamic_cast<QCheckBox*>(child)){
            if (box->isChecked()){
                QStringList tmp1 = box->text().split("'");
                if (tmp1.size()<2){
                    qDebug() << "tmp empty";
                    return;
                }
                QStringList tmp2 = tmp1.at(1).split("/");
                if (tmp2.size()<3){
                    qDebug() << "tmp empty";
                    return;
                }
                masks.append(tmp2.at(2));
            }
        }
    }
    emit setSerialMask(masks);
}

Settings::~Settings()
{
    delete ui;
}
