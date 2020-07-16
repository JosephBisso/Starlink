/********************************************************************************
** Form generated from reading UI file 'italien.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITALIEN_H
#define UI_ITALIEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Italien
{
public:

    void setupUi(QDialog *Italien)
    {
        if (Italien->objectName().isEmpty())
            Italien->setObjectName(QString::fromUtf8("Italien"));
        Italien->resize(400, 300);

        retranslateUi(Italien);

        QMetaObject::connectSlotsByName(Italien);
    } // setupUi

    void retranslateUi(QDialog *Italien)
    {
        Italien->setWindowTitle(QApplication::translate("Italien", "Italien", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Italien: public Ui_Italien {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITALIEN_H
