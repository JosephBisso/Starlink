/********************************************************************************
** Form generated from reading UI file 'frankreich.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRANKREICH_H
#define UI_FRANKREICH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Frankreich
{
public:
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;

    void setupUi(QDialog *Frankreich)
    {
        if (Frankreich->objectName().isEmpty())
            Frankreich->setObjectName(QString::fromUtf8("Frankreich"));
        Frankreich->resize(554, 490);
        Frankreich->setSizeGripEnabled(true);
        horizontalLayout = new QHBoxLayout(Frankreich);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));

        horizontalLayout->addLayout(formLayout);


        retranslateUi(Frankreich);

        QMetaObject::connectSlotsByName(Frankreich);
    } // setupUi

    void retranslateUi(QDialog *Frankreich)
    {
        Frankreich->setWindowTitle(QApplication::translate("Frankreich", "Frankreich", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frankreich: public Ui_Frankreich {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRANKREICH_H
