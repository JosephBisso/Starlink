/********************************************************************************
** Form generated from reading UI file 'kroatien.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KROATIEN_H
#define UI_KROATIEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Kroatien
{
public:

    void setupUi(QDialog *Kroatien)
    {
        if (Kroatien->objectName().isEmpty())
            Kroatien->setObjectName(QString::fromUtf8("Kroatien"));
        Kroatien->resize(400, 300);

        retranslateUi(Kroatien);

        QMetaObject::connectSlotsByName(Kroatien);
    } // setupUi

    void retranslateUi(QDialog *Kroatien)
    {
        Kroatien->setWindowTitle(QApplication::translate("Kroatien", "Kroatien", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Kroatien: public Ui_Kroatien {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KROATIEN_H
