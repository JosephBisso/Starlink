/********************************************************************************
** Form generated from reading UI file 'lettland.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LETTLAND_H
#define UI_LETTLAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Lettland
{
public:

    void setupUi(QDialog *Lettland)
    {
        if (Lettland->objectName().isEmpty())
            Lettland->setObjectName(QString::fromUtf8("Lettland"));
        Lettland->resize(400, 300);

        retranslateUi(Lettland);

        QMetaObject::connectSlotsByName(Lettland);
    } // setupUi

    void retranslateUi(QDialog *Lettland)
    {
        Lettland->setWindowTitle(QApplication::translate("Lettland", "Lettland", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lettland: public Ui_Lettland {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LETTLAND_H
