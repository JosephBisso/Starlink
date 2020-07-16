/********************************************************************************
** Form generated from reading UI file 'daenemark.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAENEMARK_H
#define UI_DAENEMARK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Daenemark
{
public:

    void setupUi(QDialog *Daenemark)
    {
        if (Daenemark->objectName().isEmpty())
            Daenemark->setObjectName(QString::fromUtf8("Daenemark"));
        Daenemark->resize(400, 300);

        retranslateUi(Daenemark);

        QMetaObject::connectSlotsByName(Daenemark);
    } // setupUi

    void retranslateUi(QDialog *Daenemark)
    {
        Daenemark->setWindowTitle(QApplication::translate("Daenemark", "D\303\244nemark", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Daenemark: public Ui_Daenemark {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAENEMARK_H
