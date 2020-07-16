/********************************************************************************
** Form generated from reading UI file 'schweiz.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHWEIZ_H
#define UI_SCHWEIZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Schweiz
{
public:

    void setupUi(QDialog *Schweiz)
    {
        if (Schweiz->objectName().isEmpty())
            Schweiz->setObjectName(QString::fromUtf8("Schweiz"));
        Schweiz->resize(400, 300);

        retranslateUi(Schweiz);

        QMetaObject::connectSlotsByName(Schweiz);
    } // setupUi

    void retranslateUi(QDialog *Schweiz)
    {
        Schweiz->setWindowTitle(QApplication::translate("Schweiz", "Schweiz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Schweiz: public Ui_Schweiz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHWEIZ_H
