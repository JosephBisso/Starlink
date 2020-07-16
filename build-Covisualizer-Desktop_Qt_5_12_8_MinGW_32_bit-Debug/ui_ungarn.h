/********************************************************************************
** Form generated from reading UI file 'ungarn.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNGARN_H
#define UI_UNGARN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Ungarn
{
public:

    void setupUi(QDialog *Ungarn)
    {
        if (Ungarn->objectName().isEmpty())
            Ungarn->setObjectName(QString::fromUtf8("Ungarn"));
        Ungarn->resize(400, 300);

        retranslateUi(Ungarn);

        QMetaObject::connectSlotsByName(Ungarn);
    } // setupUi

    void retranslateUi(QDialog *Ungarn)
    {
        Ungarn->setWindowTitle(QApplication::translate("Ungarn", "Ungarn", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ungarn: public Ui_Ungarn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNGARN_H
