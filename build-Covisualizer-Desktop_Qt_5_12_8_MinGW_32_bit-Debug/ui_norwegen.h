/********************************************************************************
** Form generated from reading UI file 'norwegen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NORWEGEN_H
#define UI_NORWEGEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Norwegen
{
public:

    void setupUi(QDialog *Norwegen)
    {
        if (Norwegen->objectName().isEmpty())
            Norwegen->setObjectName(QString::fromUtf8("Norwegen"));
        Norwegen->resize(400, 300);

        retranslateUi(Norwegen);

        QMetaObject::connectSlotsByName(Norwegen);
    } // setupUi

    void retranslateUi(QDialog *Norwegen)
    {
        Norwegen->setWindowTitle(QApplication::translate("Norwegen", "Norwegen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Norwegen: public Ui_Norwegen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NORWEGEN_H
