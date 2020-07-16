/********************************************************************************
** Form generated from reading UI file 'dbvorschau.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBVORSCHAU_H
#define UI_DBVORSCHAU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dbVorschau
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tblVorschau;
    QDialogButtonBox *closeVorschau;

    void setupUi(QDialog *dbVorschau)
    {
        if (dbVorschau->objectName().isEmpty())
            dbVorschau->setObjectName(QString::fromUtf8("dbVorschau"));
        dbVorschau->resize(751, 300);
        verticalLayout = new QVBoxLayout(dbVorschau);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tblVorschau = new QTableWidget(dbVorschau);
        if (tblVorschau->columnCount() < 7)
            tblVorschau->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblVorschau->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblVorschau->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblVorschau->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblVorschau->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblVorschau->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblVorschau->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblVorschau->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tblVorschau->setObjectName(QString::fromUtf8("tblVorschau"));

        verticalLayout->addWidget(tblVorschau);

        closeVorschau = new QDialogButtonBox(dbVorschau);
        closeVorschau->setObjectName(QString::fromUtf8("closeVorschau"));
        closeVorschau->setOrientation(Qt::Horizontal);
        closeVorschau->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout->addWidget(closeVorschau);


        retranslateUi(dbVorschau);
        QObject::connect(closeVorschau, SIGNAL(accepted()), dbVorschau, SLOT(accept()));
        QObject::connect(closeVorschau, SIGNAL(rejected()), dbVorschau, SLOT(reject()));

        QMetaObject::connectSlotsByName(dbVorschau);
    } // setupUi

    void retranslateUi(QDialog *dbVorschau)
    {
        dbVorschau->setWindowTitle(QApplication::translate("dbVorschau", "Vorschau", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblVorschau->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("dbVorschau", "Land", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblVorschau->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("dbVorschau", "Datum", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblVorschau->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("dbVorschau", "Anzahl Infiziierte", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblVorschau->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("dbVorschau", "Anzahl Tode", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblVorschau->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("dbVorschau", "Monat", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblVorschau->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("dbVorschau", "Gesamt Infiziierte", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblVorschau->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("dbVorschau", "Gesamt Tode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dbVorschau: public Ui_dbVorschau {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBVORSCHAU_H
