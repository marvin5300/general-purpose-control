/********************************************************************************
** Form generated from reading UI file 'serialconsole.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALCONSOLE_H
#define UI_SERIALCONSOLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SerialConsole
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *portNameEdit;
    QLabel *label_3;
    QLineEdit *baudRateEdit;
    QPushButton *connectButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *SCPImessageEdit;
    QPushButton *sendButton;
    QPlainTextEdit *outputTextEdit;

    void setupUi(QDialog *SerialConsole)
    {
        if (SerialConsole->objectName().isEmpty())
            SerialConsole->setObjectName(QString::fromUtf8("SerialConsole"));
        SerialConsole->resize(520, 488);
        SerialConsole->setBaseSize(QSize(0, 400));
        gridLayout = new QGridLayout(SerialConsole);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(SerialConsole);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        portNameEdit = new QLineEdit(SerialConsole);
        portNameEdit->setObjectName(QString::fromUtf8("portNameEdit"));

        horizontalLayout->addWidget(portNameEdit);

        label_3 = new QLabel(SerialConsole);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        baudRateEdit = new QLineEdit(SerialConsole);
        baudRateEdit->setObjectName(QString::fromUtf8("baudRateEdit"));

        horizontalLayout->addWidget(baudRateEdit);

        connectButton = new QPushButton(SerialConsole);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));

        horizontalLayout->addWidget(connectButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(SerialConsole);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        SCPImessageEdit = new QLineEdit(SerialConsole);
        SCPImessageEdit->setObjectName(QString::fromUtf8("SCPImessageEdit"));

        horizontalLayout_2->addWidget(SCPImessageEdit);

        sendButton = new QPushButton(SerialConsole);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        horizontalLayout_2->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout_2);

        outputTextEdit = new QPlainTextEdit(SerialConsole);
        outputTextEdit->setObjectName(QString::fromUtf8("outputTextEdit"));
        outputTextEdit->setMinimumSize(QSize(500, 400));
        outputTextEdit->setReadOnly(true);

        verticalLayout->addWidget(outputTextEdit);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(SerialConsole);

        QMetaObject::connectSlotsByName(SerialConsole);
    } // setupUi

    void retranslateUi(QDialog *SerialConsole)
    {
        SerialConsole->setWindowTitle(QCoreApplication::translate("SerialConsole", "GroupBox", nullptr));
        label->setText(QCoreApplication::translate("SerialConsole", "serialPort", nullptr));
        portNameEdit->setText(QCoreApplication::translate("SerialConsole", "/dev/ttyUSB0", nullptr));
        label_3->setText(QCoreApplication::translate("SerialConsole", "baudRate", nullptr));
        baudRateEdit->setText(QCoreApplication::translate("SerialConsole", "9600", nullptr));
        connectButton->setText(QCoreApplication::translate("SerialConsole", "connect", nullptr));
        label_2->setText(QCoreApplication::translate("SerialConsole", "message", nullptr));
        sendButton->setText(QCoreApplication::translate("SerialConsole", "send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SerialConsole: public Ui_SerialConsole {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALCONSOLE_H
