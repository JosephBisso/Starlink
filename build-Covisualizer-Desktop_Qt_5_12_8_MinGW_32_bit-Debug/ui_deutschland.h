/********************************************************************************
** Form generated from reading UI file 'deutschland.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEUTSCHLAND_H
#define UI_DEUTSCHLAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Deutschland
{
public:

    void setupUi(QDialog *Deutschland)
    {
        if (Deutschland->objectName().isEmpty())
            Deutschland->setObjectName(QString::fromUtf8("Deutschland"));
        Deutschland->resize(400, 300);

        retranslateUi(Deutschland);

        QMetaObject::connectSlotsByName(Deutschland);
    } // setupUi

    void retranslateUi(QDialog *Deutschland)
    {
        Deutschland->setWindowTitle(QApplication::translate("Deutschland", "Deutschland", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Deutschland: public Ui_Deutschland {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEUTSCHLAND_H
