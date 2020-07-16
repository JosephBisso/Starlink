/********************************************************************************
** Form generated from reading UI file 'oesterreich.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OESTERREICH_H
#define UI_OESTERREICH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Oesterreich
{
public:

    void setupUi(QDialog *Oesterreich)
    {
        if (Oesterreich->objectName().isEmpty())
            Oesterreich->setObjectName(QString::fromUtf8("Oesterreich"));
        Oesterreich->resize(400, 300);

        retranslateUi(Oesterreich);

        QMetaObject::connectSlotsByName(Oesterreich);
    } // setupUi

    void retranslateUi(QDialog *Oesterreich)
    {
        Oesterreich->setWindowTitle(QApplication::translate("Oesterreich", "\303\226sterreich", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Oesterreich: public Ui_Oesterreich {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OESTERREICH_H
