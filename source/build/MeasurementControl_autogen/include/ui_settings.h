/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *filePathEdit;
    QPushButton *openButton;
    QPushButton *deleteFilePathButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QCheckBox *dev_i2c_box;
    QCheckBox *dev_all_box;
    QCheckBox *dev_s_box;
    QCheckBox *dev_usb_box;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(606, 431);
        verticalLayout = new QVBoxLayout(Settings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Settings);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        filePathEdit = new QLineEdit(Settings);
        filePathEdit->setObjectName(QString::fromUtf8("filePathEdit"));

        horizontalLayout->addWidget(filePathEdit);

        openButton = new QPushButton(Settings);
        openButton->setObjectName(QString::fromUtf8("openButton"));

        horizontalLayout->addWidget(openButton);

        deleteFilePathButton = new QPushButton(Settings);
        deleteFilePathButton->setObjectName(QString::fromUtf8("deleteFilePathButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(deleteFilePathButton->sizePolicy().hasHeightForWidth());
        deleteFilePathButton->setSizePolicy(sizePolicy);
        deleteFilePathButton->setMinimumSize(QSize(25, 25));
        deleteFilePathButton->setMaximumSize(QSize(25, 25));
        deleteFilePathButton->setSizeIncrement(QSize(25, 25));
        deleteFilePathButton->setBaseSize(QSize(25, 25));

        horizontalLayout->addWidget(deleteFilePathButton);


        verticalLayout->addLayout(horizontalLayout);

        groupBox = new QGroupBox(Settings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        dev_i2c_box = new QCheckBox(groupBox);
        dev_i2c_box->setObjectName(QString::fromUtf8("dev_i2c_box"));

        gridLayout->addWidget(dev_i2c_box, 2, 0, 1, 1);

        dev_all_box = new QCheckBox(groupBox);
        dev_all_box->setObjectName(QString::fromUtf8("dev_all_box"));

        gridLayout->addWidget(dev_all_box, 2, 1, 1, 1);

        dev_s_box = new QCheckBox(groupBox);
        dev_s_box->setObjectName(QString::fromUtf8("dev_s_box"));

        gridLayout->addWidget(dev_s_box, 0, 0, 1, 1);

        dev_usb_box = new QCheckBox(groupBox);
        dev_usb_box->setObjectName(QString::fromUtf8("dev_usb_box"));
        dev_usb_box->setChecked(true);

        gridLayout->addWidget(dev_usb_box, 0, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(Settings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Settings);
        QObject::connect(buttonBox, SIGNAL(accepted()), Settings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Settings, SLOT(reject()));

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Settings", "Output File:", nullptr));
        openButton->setText(QCoreApplication::translate("Settings", "open", nullptr));
        deleteFilePathButton->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("Settings", "Serial", nullptr));
        dev_i2c_box->setText(QCoreApplication::translate("Settings", "'/dev/i2c*'", nullptr));
        dev_all_box->setText(QCoreApplication::translate("Settings", "'/dev/ttyA*'", nullptr));
        dev_s_box->setText(QCoreApplication::translate("Settings", "'/dev/ttyS*'", nullptr));
        dev_usb_box->setText(QCoreApplication::translate("Settings", "'/dev/ttyUSB*'", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
