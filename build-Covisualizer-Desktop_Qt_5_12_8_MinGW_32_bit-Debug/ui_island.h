/********************************************************************************
** Form generated from reading UI file 'island.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ISLAND_H
#define UI_ISLAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Island
{
public:

    void setupUi(QDialog *Island)
    {
        if (Island->objectName().isEmpty())
            Island->setObjectName(QString::fromUtf8("Island"));
        Island->resize(400, 300);

        retranslateUi(Island);

        QMetaObject::connectSlotsByName(Island);
    } // setupUi

    void retranslateUi(QDialog *Island)
    {
        Island->setWindowTitle(QApplication::translate("Island", "Island", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Island: public Ui_Island {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ISLAND_H
