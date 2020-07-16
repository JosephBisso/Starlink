/********************************************************************************
** Form generated from reading UI file 'finnland.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINNLAND_H
#define UI_FINNLAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Finnland
{
public:

    void setupUi(QDialog *Finnland)
    {
        if (Finnland->objectName().isEmpty())
            Finnland->setObjectName(QString::fromUtf8("Finnland"));
        Finnland->resize(400, 300);

        retranslateUi(Finnland);

        QMetaObject::connectSlotsByName(Finnland);
    } // setupUi

    void retranslateUi(QDialog *Finnland)
    {
        Finnland->setWindowTitle(QApplication::translate("Finnland", "Finnland", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Finnland: public Ui_Finnland {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINNLAND_H
