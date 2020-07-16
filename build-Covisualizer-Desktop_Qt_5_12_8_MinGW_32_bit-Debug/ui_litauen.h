/********************************************************************************
** Form generated from reading UI file 'litauen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LITAUEN_H
#define UI_LITAUEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Litauen
{
public:

    void setupUi(QDialog *Litauen)
    {
        if (Litauen->objectName().isEmpty())
            Litauen->setObjectName(QString::fromUtf8("Litauen"));
        Litauen->resize(400, 300);

        retranslateUi(Litauen);

        QMetaObject::connectSlotsByName(Litauen);
    } // setupUi

    void retranslateUi(QDialog *Litauen)
    {
        Litauen->setWindowTitle(QApplication::translate("Litauen", "Litauen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Litauen: public Ui_Litauen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LITAUEN_H
