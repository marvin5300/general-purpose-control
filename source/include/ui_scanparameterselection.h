/********************************************************************************
** Form generated from reading UI file 'scanparameterselection.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANPARAMETERSELECTION_H
#define UI_SCANPARAMETERSELECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScanParameterSelection
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPushButton *closeButton;
    QSpacerItem *verticalSpacer_2;
    QComboBox *deviceSelectionCombobox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *scanParameterLabel;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *scanParameterSelectionCombobox;
    QWidget *checkBoxWidget;
    QGridLayout *gridLayout;
    QComboBox *scanParameterAdjustMode;
    QHBoxLayout *horizontalLayout_3;
    QLabel *delayLabel;
    QLineEdit *delayEdit;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *intervalSettingLayout;
    QLabel *fromLabel;
    QLineEdit *fromEdit;
    QLabel *toLabel;
    QLineEdit *toEdit;
    QHBoxLayout *rampSettingLayout;
    QComboBox *stepsCombobox;
    QLineEdit *stepsEdit;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *logStepsButton;
    QSpacerItem *scanParameterSpacer;
    QTableWidget *scanParameterTableWidget;

    void setupUi(QFrame *ScanParameterSelection)
    {
        if (ScanParameterSelection->objectName().isEmpty())
            ScanParameterSelection->setObjectName(QString::fromUtf8("ScanParameterSelection"));
        ScanParameterSelection->resize(285, 395);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ScanParameterSelection->sizePolicy().hasHeightForWidth());
        ScanParameterSelection->setSizePolicy(sizePolicy);
        ScanParameterSelection->setMinimumSize(QSize(285, 0));
        ScanParameterSelection->setMaximumSize(QSize(285, 16777215));
        ScanParameterSelection->setBaseSize(QSize(280, 0));
        ScanParameterSelection->setFrameShape(QFrame::Box);
        verticalLayout_3 = new QVBoxLayout(ScanParameterSelection);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(7, -1, -1, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 7, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(ScanParameterSelection);
        label->setObjectName(QString::fromUtf8("label"));
        label->setBaseSize(QSize(100, 0));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        closeButton = new QPushButton(ScanParameterSelection);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy1);
        closeButton->setMinimumSize(QSize(20, 20));
        closeButton->setMaximumSize(QSize(20, 20));
        closeButton->setSizeIncrement(QSize(0, 0));
        closeButton->setBaseSize(QSize(20, 20));

        verticalLayout_2->addWidget(closeButton);

        verticalSpacer_2 = new QSpacerItem(20, 7, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        deviceSelectionCombobox = new QComboBox(ScanParameterSelection);
        deviceSelectionCombobox->setObjectName(QString::fromUtf8("deviceSelectionCombobox"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(deviceSelectionCombobox->sizePolicy().hasHeightForWidth());
        deviceSelectionCombobox->setSizePolicy(sizePolicy2);
        deviceSelectionCombobox->setMinimumSize(QSize(150, 0));
        deviceSelectionCombobox->setMaximumSize(QSize(16777215, 16777215));
        deviceSelectionCombobox->setBaseSize(QSize(180, 0));
        deviceSelectionCombobox->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);
        deviceSelectionCombobox->setMinimumContentsLength(0);

        verticalLayout_3->addWidget(deviceSelectionCombobox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(7, -1, 7, -1);
        scanParameterLabel = new QLabel(ScanParameterSelection);
        scanParameterLabel->setObjectName(QString::fromUtf8("scanParameterLabel"));

        horizontalLayout_2->addWidget(scanParameterLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        scanParameterSelectionCombobox = new QComboBox(ScanParameterSelection);
        scanParameterSelectionCombobox->setObjectName(QString::fromUtf8("scanParameterSelectionCombobox"));
        scanParameterSelectionCombobox->setMinimumSize(QSize(95, 0));

        horizontalLayout_2->addWidget(scanParameterSelectionCombobox);


        verticalLayout_3->addLayout(horizontalLayout_2);

        checkBoxWidget = new QWidget(ScanParameterSelection);
        checkBoxWidget->setObjectName(QString::fromUtf8("checkBoxWidget"));
        gridLayout = new QGridLayout(checkBoxWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scanParameterAdjustMode = new QComboBox(checkBoxWidget);
        scanParameterAdjustMode->setObjectName(QString::fromUtf8("scanParameterAdjustMode"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(scanParameterAdjustMode->sizePolicy().hasHeightForWidth());
        scanParameterAdjustMode->setSizePolicy(sizePolicy3);
        scanParameterAdjustMode->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(scanParameterAdjustMode, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        delayLabel = new QLabel(checkBoxWidget);
        delayLabel->setObjectName(QString::fromUtf8("delayLabel"));

        horizontalLayout_3->addWidget(delayLabel);

        delayEdit = new QLineEdit(checkBoxWidget);
        delayEdit->setObjectName(QString::fromUtf8("delayEdit"));
        sizePolicy3.setHeightForWidth(delayEdit->sizePolicy().hasHeightForWidth());
        delayEdit->setSizePolicy(sizePolicy3);
        delayEdit->setMinimumSize(QSize(40, 0));
        delayEdit->setMaximumSize(QSize(40, 16777215));
        delayEdit->setBaseSize(QSize(50, 0));
        delayEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(delayEdit);


        gridLayout->addLayout(horizontalLayout_3, 0, 2, 1, 1);

        checkBox_4 = new QCheckBox(checkBoxWidget);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        gridLayout->addWidget(checkBox_4, 1, 0, 1, 1);

        checkBox_5 = new QCheckBox(checkBoxWidget);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        gridLayout->addWidget(checkBox_5, 1, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 1, 1, 1);


        verticalLayout_3->addWidget(checkBoxWidget);

        intervalSettingLayout = new QHBoxLayout();
        intervalSettingLayout->setObjectName(QString::fromUtf8("intervalSettingLayout"));
        intervalSettingLayout->setContentsMargins(7, -1, 7, -1);
        fromLabel = new QLabel(ScanParameterSelection);
        fromLabel->setObjectName(QString::fromUtf8("fromLabel"));
        sizePolicy.setHeightForWidth(fromLabel->sizePolicy().hasHeightForWidth());
        fromLabel->setSizePolicy(sizePolicy);

        intervalSettingLayout->addWidget(fromLabel);

        fromEdit = new QLineEdit(ScanParameterSelection);
        fromEdit->setObjectName(QString::fromUtf8("fromEdit"));
        fromEdit->setAlignment(Qt::AlignCenter);

        intervalSettingLayout->addWidget(fromEdit);

        toLabel = new QLabel(ScanParameterSelection);
        toLabel->setObjectName(QString::fromUtf8("toLabel"));
        sizePolicy.setHeightForWidth(toLabel->sizePolicy().hasHeightForWidth());
        toLabel->setSizePolicy(sizePolicy);

        intervalSettingLayout->addWidget(toLabel);

        toEdit = new QLineEdit(ScanParameterSelection);
        toEdit->setObjectName(QString::fromUtf8("toEdit"));
        toEdit->setAlignment(Qt::AlignCenter);

        intervalSettingLayout->addWidget(toEdit);


        verticalLayout_3->addLayout(intervalSettingLayout);

        rampSettingLayout = new QHBoxLayout();
        rampSettingLayout->setObjectName(QString::fromUtf8("rampSettingLayout"));
        rampSettingLayout->setContentsMargins(7, -1, 7, -1);
        stepsCombobox = new QComboBox(ScanParameterSelection);
        stepsCombobox->addItem(QString());
        stepsCombobox->addItem(QString());
        stepsCombobox->setObjectName(QString::fromUtf8("stepsCombobox"));
        sizePolicy1.setHeightForWidth(stepsCombobox->sizePolicy().hasHeightForWidth());
        stepsCombobox->setSizePolicy(sizePolicy1);
        stepsCombobox->setMinimumSize(QSize(150, 0));

        rampSettingLayout->addWidget(stepsCombobox);

        stepsEdit = new QLineEdit(ScanParameterSelection);
        stepsEdit->setObjectName(QString::fromUtf8("stepsEdit"));
        stepsEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        rampSettingLayout->addWidget(stepsEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        rampSettingLayout->addItem(horizontalSpacer_2);

        logStepsButton = new QCheckBox(ScanParameterSelection);
        logStepsButton->setObjectName(QString::fromUtf8("logStepsButton"));

        rampSettingLayout->addWidget(logStepsButton);


        verticalLayout_3->addLayout(rampSettingLayout);

        scanParameterSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_3->addItem(scanParameterSpacer);

        scanParameterTableWidget = new QTableWidget(ScanParameterSelection);
        scanParameterTableWidget->setObjectName(QString::fromUtf8("scanParameterTableWidget"));
        scanParameterTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scanParameterTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scanParameterTableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scanParameterTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        scanParameterTableWidget->setTabKeyNavigation(true);
        scanParameterTableWidget->setProperty("showDropIndicator", QVariant(false));
        scanParameterTableWidget->setDragDropOverwriteMode(false);
        scanParameterTableWidget->setAlternatingRowColors(false);
        scanParameterTableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        scanParameterTableWidget->setCornerButtonEnabled(false);
        scanParameterTableWidget->horizontalHeader()->setHighlightSections(false);
        scanParameterTableWidget->verticalHeader()->setVisible(false);
        scanParameterTableWidget->verticalHeader()->setHighlightSections(false);

        verticalLayout_3->addWidget(scanParameterTableWidget);


        retranslateUi(ScanParameterSelection);

        QMetaObject::connectSlotsByName(ScanParameterSelection);
    } // setupUi

    void retranslateUi(QFrame *ScanParameterSelection)
    {
        ScanParameterSelection->setWindowTitle(QCoreApplication::translate("ScanParameterSelection", "Frame", nullptr));
        label->setText(QCoreApplication::translate("ScanParameterSelection", "device:", nullptr));
        closeButton->setText(QString());
        scanParameterLabel->setText(QCoreApplication::translate("ScanParameterSelection", "scan parameter:", nullptr));
        delayLabel->setText(QCoreApplication::translate("ScanParameterSelection", "delay [ms]", nullptr));
        delayEdit->setText(QCoreApplication::translate("ScanParameterSelection", "0", nullptr));
        checkBox_4->setText(QCoreApplication::translate("ScanParameterSelection", "CheckBox", nullptr));
        checkBox_5->setText(QCoreApplication::translate("ScanParameterSelection", "CheckBox", nullptr));
        fromLabel->setText(QCoreApplication::translate("ScanParameterSelection", "from:", nullptr));
        fromEdit->setText(QCoreApplication::translate("ScanParameterSelection", "0.0", nullptr));
        toLabel->setText(QCoreApplication::translate("ScanParameterSelection", "to:", nullptr));
        toEdit->setText(QCoreApplication::translate("ScanParameterSelection", "1.0", nullptr));
        stepsCombobox->setItemText(0, QCoreApplication::translate("ScanParameterSelection", "number of steps:", nullptr));
        stepsCombobox->setItemText(1, QCoreApplication::translate("ScanParameterSelection", "in increments of:", nullptr));

        stepsEdit->setText(QCoreApplication::translate("ScanParameterSelection", "100", nullptr));
        logStepsButton->setText(QCoreApplication::translate("ScanParameterSelection", "log", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScanParameterSelection: public Ui_ScanParameterSelection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANPARAMETERSELECTION_H
