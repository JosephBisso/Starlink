/********************************************************************************
** Form generated from reading UI file 'moldawien.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOLDAWIEN_H
#define UI_MOLDAWIEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Moldawien
{
public:

    void setupUi(QDialog *Moldawien)
    {
        if (Moldawien->objectName().isEmpty())
            Moldawien->setObjectName(QString::fromUtf8("Moldawien"));
        Moldawien->resize(400, 300);

        retranslateUi(Moldawien);

        QMetaObject::connectSlotsByName(Moldawien);
    } // setupUi

    void retranslateUi(QDialog *Moldawien)
    {
        Moldawien->setWindowTitle(QApplication::translate("Moldawien", "Moldawien", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Moldawien: public Ui_Moldawien {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOLDAWIEN_H
