/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSerial_Console;
    QAction *actionopen_settings;
    QAction *actionselect_output_file;
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_1;
    QPushButton *pushButton_New;
    QPushButton *pushButton_Open;
    QPlainTextEdit *plainTextEdit;
    QWidget *page_2;
    QWidget *page_3;
    QGroupBox *scanValueGroupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *scanValuesHorizontalLayout;
    QVBoxLayout *addButtonLayout;
    QPushButton *addAdjustValueButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QGroupBox *devicesGroupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *deviceConfigHorizontalLayout;
    QVBoxLayout *addButtonLayout_2;
    QPushButton *addDeviceButton;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *timeSelectionGroupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *intervalLabel;
    QSpinBox *intervalspinbox;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QSpinBox *cyclesspinbox;
    QPushButton *startMeasurementButton;
    QLabel *fileStatusLabel;
    QCheckBox *autoFileCheckbox;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *noLimitCheck;
    QFrame *line_2;
    QFrame *line;
    QProgressBar *progressBar;
    QWidget *page_41;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_Logger;
    QPlainTextEdit *plainTextEdit_Logger;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_Menu;
    QPushButton *pushButton_Measurements;
    QPushButton *pushButton_Prober;
    QPushButton *pushButton_MeasDevs;
    QMenuBar *menubar;
    QMenu *menuSettings;
    QMenu *menuTools;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1400, 900);
        actionSerial_Console = new QAction(MainWindow);
        actionSerial_Console->setObjectName(QString::fromUtf8("actionSerial_Console"));
        actionopen_settings = new QAction(MainWindow);
        actionopen_settings->setObjectName(QString::fromUtf8("actionopen_settings"));
        actionselect_output_file = new QAction(MainWindow);
        actionselect_output_file->setObjectName(QString::fromUtf8("actionselect_output_file"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(180, 10, 1200, 800));
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        pushButton_New = new QPushButton(page_1);
        pushButton_New->setObjectName(QString::fromUtf8("pushButton_New"));
        pushButton_New->setGeometry(QRect(30, 20, 75, 24));
        pushButton_Open = new QPushButton(page_1);
        pushButton_Open->setObjectName(QString::fromUtf8("pushButton_Open"));
        pushButton_Open->setGeometry(QRect(130, 20, 75, 24));
        plainTextEdit = new QPlainTextEdit(page_1);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(30, 80, 701, 311));
        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        scanValueGroupBox = new QGroupBox(page_3);
        scanValueGroupBox->setObjectName(QString::fromUtf8("scanValueGroupBox"));
        scanValueGroupBox->setGeometry(QRect(50, 360, 900, 300));
        scanValueGroupBox->setBaseSize(QSize(0, 400));
        gridLayout = new QGridLayout(scanValueGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scanValuesHorizontalLayout = new QHBoxLayout();
        scanValuesHorizontalLayout->setObjectName(QString::fromUtf8("scanValuesHorizontalLayout"));
        scanValuesHorizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        addButtonLayout = new QVBoxLayout();
        addButtonLayout->setObjectName(QString::fromUtf8("addButtonLayout"));
        addAdjustValueButton = new QPushButton(scanValueGroupBox);
        addAdjustValueButton->setObjectName(QString::fromUtf8("addAdjustValueButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addAdjustValueButton->sizePolicy().hasHeightForWidth());
        addAdjustValueButton->setSizePolicy(sizePolicy);
        addAdjustValueButton->setMinimumSize(QSize(25, 25));
        addAdjustValueButton->setMaximumSize(QSize(25, 25));
        addAdjustValueButton->setBaseSize(QSize(25, 25));

        addButtonLayout->addWidget(addAdjustValueButton);

        verticalSpacer = new QSpacerItem(20, 400, QSizePolicy::Minimum, QSizePolicy::Expanding);

        addButtonLayout->addItem(verticalSpacer);


        scanValuesHorizontalLayout->addLayout(addButtonLayout);

        horizontalSpacer = new QSpacerItem(600, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        scanValuesHorizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(scanValuesHorizontalLayout, 0, 0, 1, 1);

        devicesGroupBox = new QGroupBox(page_3);
        devicesGroupBox->setObjectName(QString::fromUtf8("devicesGroupBox"));
        devicesGroupBox->setGeometry(QRect(50, 10, 900, 300));
        devicesGroupBox->setBaseSize(QSize(0, 400));
        gridLayout_2 = new QGridLayout(devicesGroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        deviceConfigHorizontalLayout = new QHBoxLayout();
        deviceConfigHorizontalLayout->setObjectName(QString::fromUtf8("deviceConfigHorizontalLayout"));
        deviceConfigHorizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        addButtonLayout_2 = new QVBoxLayout();
        addButtonLayout_2->setObjectName(QString::fromUtf8("addButtonLayout_2"));
        addDeviceButton = new QPushButton(devicesGroupBox);
        addDeviceButton->setObjectName(QString::fromUtf8("addDeviceButton"));
        sizePolicy.setHeightForWidth(addDeviceButton->sizePolicy().hasHeightForWidth());
        addDeviceButton->setSizePolicy(sizePolicy);
        addDeviceButton->setMinimumSize(QSize(25, 25));
        addDeviceButton->setMaximumSize(QSize(25, 25));
        addDeviceButton->setBaseSize(QSize(25, 25));

        addButtonLayout_2->addWidget(addDeviceButton);

        verticalSpacer_2 = new QSpacerItem(20, 400, QSizePolicy::Minimum, QSizePolicy::Expanding);

        addButtonLayout_2->addItem(verticalSpacer_2);


        deviceConfigHorizontalLayout->addLayout(addButtonLayout_2);

        horizontalSpacer_2 = new QSpacerItem(600, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        deviceConfigHorizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(deviceConfigHorizontalLayout, 1, 0, 1, 1);

        timeSelectionGroupBox = new QGroupBox(page_3);
        timeSelectionGroupBox->setObjectName(QString::fromUtf8("timeSelectionGroupBox"));
        timeSelectionGroupBox->setGeometry(QRect(30, 690, 951, 60));
        horizontalLayout = new QHBoxLayout(timeSelectionGroupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        intervalLabel = new QLabel(timeSelectionGroupBox);
        intervalLabel->setObjectName(QString::fromUtf8("intervalLabel"));

        horizontalLayout->addWidget(intervalLabel);

        intervalspinbox = new QSpinBox(timeSelectionGroupBox);
        intervalspinbox->setObjectName(QString::fromUtf8("intervalspinbox"));
        intervalspinbox->setMinimum(1);
        intervalspinbox->setMaximum(10000000);
        intervalspinbox->setSingleStep(500);
        intervalspinbox->setValue(1000);

        horizontalLayout->addWidget(intervalspinbox);

        label = new QLabel(timeSelectionGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label_2 = new QLabel(timeSelectionGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        cyclesspinbox = new QSpinBox(timeSelectionGroupBox);
        cyclesspinbox->setObjectName(QString::fromUtf8("cyclesspinbox"));
        cyclesspinbox->setMinimum(1);
        cyclesspinbox->setMaximum(99999);

        horizontalLayout->addWidget(cyclesspinbox);

        startMeasurementButton = new QPushButton(timeSelectionGroupBox);
        startMeasurementButton->setObjectName(QString::fromUtf8("startMeasurementButton"));

        horizontalLayout->addWidget(startMeasurementButton);

        fileStatusLabel = new QLabel(timeSelectionGroupBox);
        fileStatusLabel->setObjectName(QString::fromUtf8("fileStatusLabel"));

        horizontalLayout->addWidget(fileStatusLabel);

        autoFileCheckbox = new QCheckBox(timeSelectionGroupBox);
        autoFileCheckbox->setObjectName(QString::fromUtf8("autoFileCheckbox"));
        autoFileCheckbox->setEnabled(false);
        autoFileCheckbox->setCheckable(false);
        autoFileCheckbox->setChecked(false);

        horizontalLayout->addWidget(autoFileCheckbox);

        horizontalSpacer_3 = new QSpacerItem(408, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        noLimitCheck = new QCheckBox(timeSelectionGroupBox);
        noLimitCheck->setObjectName(QString::fromUtf8("noLimitCheck"));

        horizontalLayout->addWidget(noLimitCheck);

        line_2 = new QFrame(page_3);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(30, 680, 950, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line = new QFrame(page_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(30, 330, 950, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        progressBar = new QProgressBar(page_3);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(30, 760, 951, 24));
        progressBar->setValue(42);
        stackedWidget->addWidget(page_3);
        page_41 = new QWidget();
        page_41->setObjectName(QString::fromUtf8("page_41"));
        verticalLayoutWidget_2 = new QWidget(page_41);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(60, 0, 551, 521));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_Logger = new QLabel(verticalLayoutWidget_2);
        label_Logger->setObjectName(QString::fromUtf8("label_Logger"));
        QFont font;
        font.setPointSize(14);
        label_Logger->setFont(font);

        verticalLayout_2->addWidget(label_Logger);

        plainTextEdit_Logger = new QPlainTextEdit(verticalLayoutWidget_2);
        plainTextEdit_Logger->setObjectName(QString::fromUtf8("plainTextEdit_Logger"));

        verticalLayout_2->addWidget(plainTextEdit_Logger);

        stackedWidget->addWidget(page_41);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 154, 191));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_Menu = new QLabel(verticalLayoutWidget);
        label_Menu->setObjectName(QString::fromUtf8("label_Menu"));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        label_Menu->setFont(font1);
        label_Menu->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_Menu);

        pushButton_Measurements = new QPushButton(verticalLayoutWidget);
        pushButton_Measurements->setObjectName(QString::fromUtf8("pushButton_Measurements"));

        verticalLayout->addWidget(pushButton_Measurements);

        pushButton_Prober = new QPushButton(verticalLayoutWidget);
        pushButton_Prober->setObjectName(QString::fromUtf8("pushButton_Prober"));

        verticalLayout->addWidget(pushButton_Prober);

        pushButton_MeasDevs = new QPushButton(verticalLayoutWidget);
        pushButton_MeasDevs->setObjectName(QString::fromUtf8("pushButton_MeasDevs"));

        verticalLayout->addWidget(pushButton_MeasDevs);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1011, 22));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menuTools->menuAction());
        menuSettings->addAction(actionopen_settings);
        menuSettings->addAction(actionselect_output_file);
        menuTools->addAction(actionSerial_Console);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Measurement Control", nullptr));
        actionSerial_Console->setText(QCoreApplication::translate("MainWindow", "&Serial Console", nullptr));
        actionopen_settings->setText(QCoreApplication::translate("MainWindow", "&open settings", nullptr));
        actionselect_output_file->setText(QCoreApplication::translate("MainWindow", "&select output file", nullptr));
        pushButton_New->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        pushButton_Open->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        scanValueGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Scan Value Selection", nullptr));
        addAdjustValueButton->setText(QString());
        devicesGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Devices Configurator", nullptr));
        addDeviceButton->setText(QString());
        timeSelectionGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Measurement Time Selection", nullptr));
        intervalLabel->setText(QCoreApplication::translate("MainWindow", "delay set - measure:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "[ms]", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "n cycles:", nullptr));
        startMeasurementButton->setText(QCoreApplication::translate("MainWindow", "start measurement", nullptr));
        fileStatusLabel->setText(QCoreApplication::translate("MainWindow", "no file", nullptr));
        autoFileCheckbox->setText(QCoreApplication::translate("MainWindow", "auto", nullptr));
        noLimitCheck->setText(QCoreApplication::translate("MainWindow", "no limit", nullptr));
        label_Logger->setText(QCoreApplication::translate("MainWindow", "Logger", nullptr));
        label_Menu->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        pushButton_Measurements->setText(QCoreApplication::translate("MainWindow", "Measurements", nullptr));
        pushButton_Prober->setText(QCoreApplication::translate("MainWindow", "Prober", nullptr));
        pushButton_MeasDevs->setText(QCoreApplication::translate("MainWindow", "Measurement devices", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Setti&ngs", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Too&ls", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
