/********************************************************************************
** Form generated from reading UI file 'measurementdevice.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEASUREMENTDEVICE_H
#define UI_MEASUREMENTDEVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MeasurementDevice
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QComboBox *deviceNameSelectBox;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QPushButton *closeButton;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *interfaceNameSelectBox;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *parameterTableWidget;

    void setupUi(QFrame *MeasurementDevice)
    {
        if (MeasurementDevice->objectName().isEmpty())
            MeasurementDevice->setObjectName(QString::fromUtf8("MeasurementDevice"));
        MeasurementDevice->resize(285, 271);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MeasurementDevice->sizePolicy().hasHeightForWidth());
        MeasurementDevice->setSizePolicy(sizePolicy);
        MeasurementDevice->setMinimumSize(QSize(285, 271));
        MeasurementDevice->setMaximumSize(QSize(285, 16777215));
        MeasurementDevice->setBaseSize(QSize(0, 100));
        verticalLayout_4 = new QVBoxLayout(MeasurementDevice);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, -1, -1, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 7, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(MeasurementDevice);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(50, 0));
        label->setBaseSize(QSize(100, 0));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 7, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        deviceNameSelectBox = new QComboBox(MeasurementDevice);
        deviceNameSelectBox->setObjectName(QString::fromUtf8("deviceNameSelectBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(deviceNameSelectBox->sizePolicy().hasHeightForWidth());
        deviceNameSelectBox->setSizePolicy(sizePolicy1);
        deviceNameSelectBox->setMinimumSize(QSize(150, 0));

        verticalLayout_2->addWidget(deviceNameSelectBox);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(35, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        closeButton = new QPushButton(MeasurementDevice);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy2);
        closeButton->setMinimumSize(QSize(20, 20));
        closeButton->setMaximumSize(QSize(20, 20));
        closeButton->setSizeIncrement(QSize(20, 20));
        closeButton->setBaseSize(QSize(20, 20));

        verticalLayout_3->addWidget(closeButton);

        verticalSpacer_3 = new QSpacerItem(20, 7, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(3, -1, -1, -1);
        label_2 = new QLabel(MeasurementDevice);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(50, 0));
        label_2->setBaseSize(QSize(100, 0));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        interfaceNameSelectBox = new QComboBox(MeasurementDevice);
        interfaceNameSelectBox->setObjectName(QString::fromUtf8("interfaceNameSelectBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(interfaceNameSelectBox->sizePolicy().hasHeightForWidth());
        interfaceNameSelectBox->setSizePolicy(sizePolicy3);
        interfaceNameSelectBox->setMinimumSize(QSize(150, 0));

        horizontalLayout_2->addWidget(interfaceNameSelectBox);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_2);

        parameterTableWidget = new QTableWidget(MeasurementDevice);
        parameterTableWidget->setObjectName(QString::fromUtf8("parameterTableWidget"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(parameterTableWidget->sizePolicy().hasHeightForWidth());
        parameterTableWidget->setSizePolicy(sizePolicy4);
        parameterTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        parameterTableWidget->setTabKeyNavigation(false);
        parameterTableWidget->setProperty("showDropIndicator", QVariant(false));
        parameterTableWidget->setDragDropOverwriteMode(false);
        parameterTableWidget->verticalHeader()->setVisible(false);
        parameterTableWidget->verticalHeader()->setHighlightSections(false);

        verticalLayout_4->addWidget(parameterTableWidget);


        retranslateUi(MeasurementDevice);

        QMetaObject::connectSlotsByName(MeasurementDevice);
    } // setupUi

    void retranslateUi(QFrame *MeasurementDevice)
    {
        MeasurementDevice->setWindowTitle(QCoreApplication::translate("MeasurementDevice", "Device", nullptr));
        label->setText(QCoreApplication::translate("MeasurementDevice", "device", nullptr));
        closeButton->setText(QString());
        label_2->setText(QCoreApplication::translate("MeasurementDevice", "port", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MeasurementDevice: public Ui_MeasurementDevice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEASUREMENTDEVICE_H
