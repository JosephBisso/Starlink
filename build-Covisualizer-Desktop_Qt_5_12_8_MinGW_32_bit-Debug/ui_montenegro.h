/********************************************************************************
** Form generated from reading UI file 'montenegro.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONTENEGRO_H
#define UI_MONTENEGRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Montenegro
{
public:

    void setupUi(QDialog *Montenegro)
    {
        if (Montenegro->objectName().isEmpty())
            Montenegro->setObjectName(QString::fromUtf8("Montenegro"));
        Montenegro->resize(400, 300);

        retranslateUi(Montenegro);

        QMetaObject::connectSlotsByName(Montenegro);
    } // setupUi

    void retranslateUi(QDialog *Montenegro)
    {
        Montenegro->setWindowTitle(QApplication::translate("Montenegro", "Montenegro", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Montenegro: public Ui_Montenegro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONTENEGRO_H
