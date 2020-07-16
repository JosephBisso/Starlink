/********************************************************************************
** Form generated from reading UI file 'serbien.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERBIEN_H
#define UI_SERBIEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Serbien
{
public:

    void setupUi(QDialog *Serbien)
    {
        if (Serbien->objectName().isEmpty())
            Serbien->setObjectName(QString::fromUtf8("Serbien"));
        Serbien->resize(400, 300);

        retranslateUi(Serbien);

        QMetaObject::connectSlotsByName(Serbien);
    } // setupUi

    void retranslateUi(QDialog *Serbien)
    {
        Serbien->setWindowTitle(QApplication::translate("Serbien", "Serbien", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Serbien: public Ui_Serbien {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERBIEN_H
