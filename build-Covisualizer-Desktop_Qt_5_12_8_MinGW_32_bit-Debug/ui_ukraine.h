/********************************************************************************
** Form generated from reading UI file 'ukraine.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UKRAINE_H
#define UI_UKRAINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Ukraine
{
public:

    void setupUi(QDialog *Ukraine)
    {
        if (Ukraine->objectName().isEmpty())
            Ukraine->setObjectName(QString::fromUtf8("Ukraine"));
        Ukraine->resize(400, 300);

        retranslateUi(Ukraine);

        QMetaObject::connectSlotsByName(Ukraine);
    } // setupUi

    void retranslateUi(QDialog *Ukraine)
    {
        Ukraine->setWindowTitle(QApplication::translate("Ukraine", "Ukraine", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ukraine: public Ui_Ukraine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UKRAINE_H
