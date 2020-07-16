/********************************************************************************
** Form generated from reading UI file 'schweden.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHWEDEN_H
#define UI_SCHWEDEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Schweden
{
public:

    void setupUi(QDialog *Schweden)
    {
        if (Schweden->objectName().isEmpty())
            Schweden->setObjectName(QString::fromUtf8("Schweden"));
        Schweden->resize(400, 300);

        retranslateUi(Schweden);

        QMetaObject::connectSlotsByName(Schweden);
    } // setupUi

    void retranslateUi(QDialog *Schweden)
    {
        Schweden->setWindowTitle(QApplication::translate("Schweden", "Schweden", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Schweden: public Ui_Schweden {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHWEDEN_H
