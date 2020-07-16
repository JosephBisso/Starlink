/********************************************************************************
** Form generated from reading UI file 'slowenien.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLOWENIEN_H
#define UI_SLOWENIEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Slowenien
{
public:

    void setupUi(QDialog *Slowenien)
    {
        if (Slowenien->objectName().isEmpty())
            Slowenien->setObjectName(QString::fromUtf8("Slowenien"));
        Slowenien->resize(400, 300);

        retranslateUi(Slowenien);

        QMetaObject::connectSlotsByName(Slowenien);
    } // setupUi

    void retranslateUi(QDialog *Slowenien)
    {
        Slowenien->setWindowTitle(QApplication::translate("Slowenien", "Slowenien", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Slowenien: public Ui_Slowenien {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLOWENIEN_H
