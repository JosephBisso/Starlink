/********************************************************************************
** Form generated from reading UI file 'griechenland.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRIECHENLAND_H
#define UI_GRIECHENLAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Griechenland
{
public:

    void setupUi(QDialog *Griechenland)
    {
        if (Griechenland->objectName().isEmpty())
            Griechenland->setObjectName(QString::fromUtf8("Griechenland"));
        Griechenland->resize(400, 300);

        retranslateUi(Griechenland);

        QMetaObject::connectSlotsByName(Griechenland);
    } // setupUi

    void retranslateUi(QDialog *Griechenland)
    {
        Griechenland->setWindowTitle(QApplication::translate("Griechenland", "Griechenland", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Griechenland: public Ui_Griechenland {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRIECHENLAND_H
