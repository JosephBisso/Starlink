/********************************************************************************
** Form generated from reading UI file 'portugal.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORTUGAL_H
#define UI_PORTUGAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Portugal
{
public:

    void setupUi(QDialog *Portugal)
    {
        if (Portugal->objectName().isEmpty())
            Portugal->setObjectName(QString::fromUtf8("Portugal"));
        Portugal->resize(400, 300);

        retranslateUi(Portugal);

        QMetaObject::connectSlotsByName(Portugal);
    } // setupUi

    void retranslateUi(QDialog *Portugal)
    {
        Portugal->setWindowTitle(QApplication::translate("Portugal", "Portugal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Portugal: public Ui_Portugal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTUGAL_H
