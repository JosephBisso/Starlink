/********************************************************************************
** Form generated from reading UI file 'tschechien.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TSCHECHIEN_H
#define UI_TSCHECHIEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Tschechien
{
public:

    void setupUi(QDialog *Tschechien)
    {
        if (Tschechien->objectName().isEmpty())
            Tschechien->setObjectName(QString::fromUtf8("Tschechien"));
        Tschechien->resize(400, 300);

        retranslateUi(Tschechien);

        QMetaObject::connectSlotsByName(Tschechien);
    } // setupUi

    void retranslateUi(QDialog *Tschechien)
    {
        Tschechien->setWindowTitle(QApplication::translate("Tschechien", "Tschechien", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tschechien: public Ui_Tschechien {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TSCHECHIEN_H
