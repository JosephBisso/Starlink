/********************************************************************************
** Form generated from reading UI file 'rumanien.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUMANIEN_H
#define UI_RUMANIEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Rumanien
{
public:

    void setupUi(QDialog *Rumanien)
    {
        if (Rumanien->objectName().isEmpty())
            Rumanien->setObjectName(QString::fromUtf8("Rumanien"));
        Rumanien->resize(400, 300);

        retranslateUi(Rumanien);

        QMetaObject::connectSlotsByName(Rumanien);
    } // setupUi

    void retranslateUi(QDialog *Rumanien)
    {
        Rumanien->setWindowTitle(QApplication::translate("Rumanien", "Rum\303\244nien", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Rumanien: public Ui_Rumanien {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUMANIEN_H
