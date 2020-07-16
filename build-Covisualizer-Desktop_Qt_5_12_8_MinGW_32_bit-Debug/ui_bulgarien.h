/********************************************************************************
** Form generated from reading UI file 'bulgarien.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BULGARIEN_H
#define UI_BULGARIEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Bulgarien
{
public:

    void setupUi(QDialog *Bulgarien)
    {
        if (Bulgarien->objectName().isEmpty())
            Bulgarien->setObjectName(QString::fromUtf8("Bulgarien"));
        Bulgarien->resize(400, 300);

        retranslateUi(Bulgarien);

        QMetaObject::connectSlotsByName(Bulgarien);
    } // setupUi

    void retranslateUi(QDialog *Bulgarien)
    {
        Bulgarien->setWindowTitle(QApplication::translate("Bulgarien", "Bulgarien", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Bulgarien: public Ui_Bulgarien {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BULGARIEN_H
