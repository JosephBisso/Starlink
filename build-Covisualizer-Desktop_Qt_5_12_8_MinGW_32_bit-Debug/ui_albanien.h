/********************************************************************************
** Form generated from reading UI file 'albanien.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALBANIEN_H
#define UI_ALBANIEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Albanien
{
public:

    void setupUi(QDialog *Albanien)
    {
        if (Albanien->objectName().isEmpty())
            Albanien->setObjectName(QString::fromUtf8("Albanien"));
        Albanien->resize(400, 300);

        retranslateUi(Albanien);

        QMetaObject::connectSlotsByName(Albanien);
    } // setupUi

    void retranslateUi(QDialog *Albanien)
    {
        Albanien->setWindowTitle(QApplication::translate("Albanien", "Albanien", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Albanien: public Ui_Albanien {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALBANIEN_H
