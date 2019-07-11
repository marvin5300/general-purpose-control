/********************************************************************************
** Form generated from reading UI file 'keithley_2000.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEITHLEY_2000_H
#define UI_KEITHLEY_2000_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Keithley_2000
{
public:

    void setupUi(QGroupBox *Keithley_2000)
    {
        if (Keithley_2000->objectName().isEmpty())
            Keithley_2000->setObjectName(QStringLiteral("Keithley_2000"));
        Keithley_2000->resize(400, 300);

        retranslateUi(Keithley_2000);

        QMetaObject::connectSlotsByName(Keithley_2000);
    } // setupUi

    void retranslateUi(QGroupBox *Keithley_2000)
    {
        Keithley_2000->setWindowTitle(QApplication::translate("Keithley_2000", "GroupBox", Q_NULLPTR));
        Keithley_2000->setTitle(QApplication::translate("Keithley_2000", "Keithley 2000", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Keithley_2000: public Ui_Keithley_2000 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEITHLEY_2000_H
