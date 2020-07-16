/********************************************************************************
** Form generated from reading UI file 'mazedonien.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAZEDONIEN_H
#define UI_MAZEDONIEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Mazedonien
{
public:

    void setupUi(QDialog *Mazedonien)
    {
        if (Mazedonien->objectName().isEmpty())
            Mazedonien->setObjectName(QString::fromUtf8("Mazedonien"));
        Mazedonien->resize(400, 300);

        retranslateUi(Mazedonien);

        QMetaObject::connectSlotsByName(Mazedonien);
    } // setupUi

    void retranslateUi(QDialog *Mazedonien)
    {
        Mazedonien->setWindowTitle(QApplication::translate("Mazedonien", "Mazedonien", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mazedonien: public Ui_Mazedonien {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAZEDONIEN_H
