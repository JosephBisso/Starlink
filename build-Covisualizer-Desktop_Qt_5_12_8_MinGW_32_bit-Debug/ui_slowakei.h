/********************************************************************************
** Form generated from reading UI file 'slowakei.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLOWAKEI_H
#define UI_SLOWAKEI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Slowakei
{
public:

    void setupUi(QDialog *Slowakei)
    {
        if (Slowakei->objectName().isEmpty())
            Slowakei->setObjectName(QString::fromUtf8("Slowakei"));
        Slowakei->resize(400, 300);

        retranslateUi(Slowakei);

        QMetaObject::connectSlotsByName(Slowakei);
    } // setupUi

    void retranslateUi(QDialog *Slowakei)
    {
        Slowakei->setWindowTitle(QApplication::translate("Slowakei", "Slowakei", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Slowakei: public Ui_Slowakei {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLOWAKEI_H
