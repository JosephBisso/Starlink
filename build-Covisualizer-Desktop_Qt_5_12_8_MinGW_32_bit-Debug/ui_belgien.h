/********************************************************************************
** Form generated from reading UI file 'belgien.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BELGIEN_H
#define UI_BELGIEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Belgien
{
public:

    void setupUi(QDialog *Belgien)
    {
        if (Belgien->objectName().isEmpty())
            Belgien->setObjectName(QString::fromUtf8("Belgien"));
        Belgien->resize(400, 300);

        retranslateUi(Belgien);

        QMetaObject::connectSlotsByName(Belgien);
    } // setupUi

    void retranslateUi(QDialog *Belgien)
    {
        Belgien->setWindowTitle(QApplication::translate("Belgien", "Belgien", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Belgien: public Ui_Belgien {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BELGIEN_H
