/********************************************************************************
** Form generated from reading UI file 'keithley_2410.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEITHLEY_2410_H
#define UI_KEITHLEY_2410_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Keithley_2410
{
public:

    void setupUi(QGroupBox *Keithley_2410)
    {
        if (Keithley_2410->objectName().isEmpty())
            Keithley_2410->setObjectName(QStringLiteral("Keithley_2410"));
        Keithley_2410->resize(400, 300);

        retranslateUi(Keithley_2410);

        QMetaObject::connectSlotsByName(Keithley_2410);
    } // setupUi

    void retranslateUi(QGroupBox *Keithley_2410)
    {
        Keithley_2410->setWindowTitle(QApplication::translate("Keithley_2410", "GroupBox", Q_NULLPTR));
        Keithley_2410->setTitle(QApplication::translate("Keithley_2410", "Keithley 2410", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Keithley_2410: public Ui_Keithley_2410 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEITHLEY_2410_H
