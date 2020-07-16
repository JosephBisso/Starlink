/********************************************************************************
** Form generated from reading UI file 'kosovo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KOSOVO_H
#define UI_KOSOVO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Kosovo
{
public:

    void setupUi(QDialog *Kosovo)
    {
        if (Kosovo->objectName().isEmpty())
            Kosovo->setObjectName(QString::fromUtf8("Kosovo"));
        Kosovo->resize(400, 300);

        retranslateUi(Kosovo);

        QMetaObject::connectSlotsByName(Kosovo);
    } // setupUi

    void retranslateUi(QDialog *Kosovo)
    {
        Kosovo->setWindowTitle(QApplication::translate("Kosovo", "Kosovo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Kosovo: public Ui_Kosovo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KOSOVO_H
