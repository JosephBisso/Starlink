/********************************************************************************
** Form generated from reading UI file 'datenbank.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATENBANK_H
#define UI_DATENBANK_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Datenbank
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *dbConnect;
    QLabel *label;
    QFrame *line_2;
    QPushButton *dbShow;
    QFrame *formFrame;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_4;
    QFrame *line;
    QSpacerItem *horizontalSpacer;
    QPushButton *dbUpdate;
    QLabel *label_3;
    QFrame *line_3;
    QSpacerItem *horizontalSpacer_2;
    QDialogButtonBox *dbOK;

    void setupUi(QDialog *Datenbank)
    {
        if (Datenbank->objectName().isEmpty())
            Datenbank->setObjectName(QString::fromUtf8("Datenbank"));
        Datenbank->resize(630, 432);
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        Datenbank->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/dbIMG.png"), QSize(), QIcon::Normal, QIcon::Off);
        Datenbank->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Datenbank);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        dbConnect = new QPushButton(Datenbank);
        dbConnect->setObjectName(QString::fromUtf8("dbConnect"));

        verticalLayout->addWidget(dbConnect);

        label = new QLabel(Datenbank);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        line_2 = new QFrame(Datenbank);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        dbShow = new QPushButton(Datenbank);
        dbShow->setObjectName(QString::fromUtf8("dbShow"));

        verticalLayout->addWidget(dbShow);

        formFrame = new QFrame(Datenbank);
        formFrame->setObjectName(QString::fromUtf8("formFrame"));
        verticalLayout_2 = new QVBoxLayout(formFrame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(formFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_4 = new QLabel(formFrame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);


        verticalLayout->addWidget(formFrame);

        line = new QFrame(Datenbank);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        dbUpdate = new QPushButton(Datenbank);
        dbUpdate->setObjectName(QString::fromUtf8("dbUpdate"));

        verticalLayout->addWidget(dbUpdate);

        label_3 = new QLabel(Datenbank);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        line_3 = new QFrame(Datenbank);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        dbOK = new QDialogButtonBox(Datenbank);
        dbOK->setObjectName(QString::fromUtf8("dbOK"));
        dbOK->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(dbOK);


        retranslateUi(Datenbank);

        QMetaObject::connectSlotsByName(Datenbank);
    } // setupUi

    void retranslateUi(QDialog *Datenbank)
    {
        Datenbank->setWindowTitle(QApplication::translate("Datenbank", "Datenbank", nullptr));
        dbConnect->setText(QApplication::translate("Datenbank", "Verbindung zur Datenbank aufbauen", nullptr));
        label->setText(QApplication::translate("Datenbank", "Es wird eine neue Datenbank erstellt oder eine Verbindung zur existierenden Datenbank augebaut", nullptr));
        dbShow->setText(QApplication::translate("Datenbank", "Vorschau", nullptr));
        label_2->setText(QApplication::translate("Datenbank", "Es werden Zahlen aus verschiedenen L\303\244nder vom Juni vorgestellt. Sind Daten zu sehen, dann ist die Datenbank verbunden.", nullptr));
        label_4->setText(QApplication::translate("Datenbank", "Dies kann einige Sekunden dauern.", nullptr));
        dbUpdate->setText(QApplication::translate("Datenbank", "Datenbank aktualisieren", nullptr));
        label_3->setText(QApplication::translate("Datenbank", "Die Datenbank wird aktualiesiert. Bei First Use als Erstes machen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Datenbank: public Ui_Datenbank {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATENBANK_H
