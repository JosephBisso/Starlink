/********************************************************************************
** Form generated from reading UI file 'andorra.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANDORRA_H
#define UI_ANDORRA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Andorra
{
public:

    void setupUi(QDialog *Andorra)
    {
        if (Andorra->objectName().isEmpty())
            Andorra->setObjectName(QString::fromUtf8("Andorra"));
        Andorra->resize(400, 300);

        retranslateUi(Andorra);

        QMetaObject::connectSlotsByName(Andorra);
    } // setupUi

    void retranslateUi(QDialog *Andorra)
    {
        Andorra->setWindowTitle(QApplication::translate("Andorra", "Andorra", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Andorra: public Ui_Andorra {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANDORRA_H
