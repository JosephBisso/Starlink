/********************************************************************************
** Form generated from reading UI file 'polen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POLEN_H
#define UI_POLEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Polen
{
public:

    void setupUi(QDialog *Polen)
    {
        if (Polen->objectName().isEmpty())
            Polen->setObjectName(QString::fromUtf8("Polen"));
        Polen->resize(400, 300);

        retranslateUi(Polen);

        QMetaObject::connectSlotsByName(Polen);
    } // setupUi

    void retranslateUi(QDialog *Polen)
    {
        Polen->setWindowTitle(QApplication::translate("Polen", "Polen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Polen: public Ui_Polen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POLEN_H
