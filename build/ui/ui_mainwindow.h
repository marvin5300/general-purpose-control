/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLineEdit *portNameEdit;
    QPlainTextEdit *outputTextEdit;
    QPushButton *sendButton;
    QPushButton *connectButton;
    QLabel *label_2;
    QLineEdit *SCPImessageEdit;
    QLabel *label;
    QComboBox *deviceSelectBox;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 357);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        portNameEdit = new QLineEdit(centralWidget);
        portNameEdit->setObjectName(QStringLiteral("portNameEdit"));

        gridLayout->addWidget(portNameEdit, 1, 1, 1, 1);

        outputTextEdit = new QPlainTextEdit(centralWidget);
        outputTextEdit->setObjectName(QStringLiteral("outputTextEdit"));
        outputTextEdit->setReadOnly(true);

        gridLayout->addWidget(outputTextEdit, 3, 0, 1, 2);

        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        gridLayout->addWidget(sendButton, 2, 2, 1, 1);

        connectButton = new QPushButton(centralWidget);
        connectButton->setObjectName(QStringLiteral("connectButton"));

        gridLayout->addWidget(connectButton, 1, 2, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        SCPImessageEdit = new QLineEdit(centralWidget);
        SCPImessageEdit->setObjectName(QStringLiteral("SCPImessageEdit"));

        gridLayout->addWidget(SCPImessageEdit, 2, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        deviceSelectBox = new QComboBox(centralWidget);
        deviceSelectBox->setObjectName(QStringLiteral("deviceSelectBox"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(deviceSelectBox->sizePolicy().hasHeightForWidth());
        deviceSelectBox->setSizePolicy(sizePolicy);

        gridLayout->addWidget(deviceSelectBox, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        sendButton->setText(QApplication::translate("MainWindow", "send", Q_NULLPTR));
        connectButton->setText(QApplication::translate("MainWindow", "connect", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "message", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "serialPort", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
