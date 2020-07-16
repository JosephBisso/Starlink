/********************************************************************************
** Form generated from reading UI file 'weissrussland.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEISSRUSSLAND_H
#define UI_WEISSRUSSLAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Weissrussland
{
public:

    void setupUi(QDialog *Weissrussland)
    {
        if (Weissrussland->objectName().isEmpty())
            Weissrussland->setObjectName(QString::fromUtf8("Weissrussland"));
        Weissrussland->resize(400, 300);

        retranslateUi(Weissrussland);

        QMetaObject::connectSlotsByName(Weissrussland);
    } // setupUi

    void retranslateUi(QDialog *Weissrussland)
    {
        Weissrussland->setWindowTitle(QApplication::translate("Weissrussland", "Wei\303\237russland", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Weissrussland: public Ui_Weissrussland {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEISSRUSSLAND_H
