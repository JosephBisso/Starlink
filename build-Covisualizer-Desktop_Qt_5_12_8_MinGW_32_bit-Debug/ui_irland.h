/********************************************************************************
** Form generated from reading UI file 'irland.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IRLAND_H
#define UI_IRLAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Irland
{
public:

    void setupUi(QDialog *Irland)
    {
        if (Irland->objectName().isEmpty())
            Irland->setObjectName(QString::fromUtf8("Irland"));
        Irland->resize(400, 300);

        retranslateUi(Irland);

        QMetaObject::connectSlotsByName(Irland);
    } // setupUi

    void retranslateUi(QDialog *Irland)
    {
        Irland->setWindowTitle(QApplication::translate("Irland", "Irland", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Irland: public Ui_Irland {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IRLAND_H
