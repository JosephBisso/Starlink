/********************************************************************************
** Form generated from reading UI file 'estland.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESTLAND_H
#define UI_ESTLAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Estland
{
public:

    void setupUi(QDialog *Estland)
    {
        if (Estland->objectName().isEmpty())
            Estland->setObjectName(QString::fromUtf8("Estland"));
        Estland->resize(400, 300);

        retranslateUi(Estland);

        QMetaObject::connectSlotsByName(Estland);
    } // setupUi

    void retranslateUi(QDialog *Estland)
    {
        Estland->setWindowTitle(QApplication::translate("Estland", "Estland", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Estland: public Ui_Estland {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESTLAND_H
