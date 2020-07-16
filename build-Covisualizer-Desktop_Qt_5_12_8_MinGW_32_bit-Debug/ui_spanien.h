/********************************************************************************
** Form generated from reading UI file 'spanien.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPANIEN_H
#define UI_SPANIEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Spanien
{
public:

    void setupUi(QDialog *Spanien)
    {
        if (Spanien->objectName().isEmpty())
            Spanien->setObjectName(QString::fromUtf8("Spanien"));
        Spanien->resize(400, 300);

        retranslateUi(Spanien);

        QMetaObject::connectSlotsByName(Spanien);
    } // setupUi

    void retranslateUi(QDialog *Spanien)
    {
        Spanien->setWindowTitle(QApplication::translate("Spanien", "Spanien", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Spanien: public Ui_Spanien {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPANIEN_H
