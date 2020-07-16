/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Windows;
    QAction *actionDatenba;
    QAction *actionDatenbank;
    QWidget *centralwidget;
    QLabel *label_pic;
    QPushButton *Frankreich;
    QPushButton *Deutschland;
    QPushButton *Spanien;
    QPushButton *Portugal;
    QPushButton *Andorra;
    QPushButton *Belgien;
    QPushButton *Niederlande;
    QPushButton *Schweiz;
    QPushButton *Oesterreich;
    QPushButton *Grossbritannien;
    QPushButton *Irland;
    QPushButton *Island;
    QPushButton *Polen;
    QPushButton *Tschechien;
    QPushButton *Slowakei;
    QPushButton *Ungarn;
    QPushButton *Italien;
    QPushButton *Slowenien;
    QPushButton *Kroatien;
    QPushButton *Bosnien;
    QPushButton *Montenegro;
    QPushButton *Kosovo;
    QPushButton *Serbien;
    QPushButton *Rumanien;
    QPushButton *Albanien;
    QPushButton *Mazedonien;
    QPushButton *Bulgarien;
    QPushButton *Griechenland;
    QPushButton *Moldawien;
    QPushButton *Ukraine;
    QPushButton *Weissrussland;
    QPushButton *Daenemark;
    QPushButton *Norwegen;
    QPushButton *Schweden;
    QPushButton *Finnland;
    QPushButton *Estland;
    QPushButton *Lettland;
    QPushButton *Litauen;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuDatei;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 1100);
        MainWindow->setMinimumSize(QSize(100, 100));
        MainWindow->setMaximumSize(QSize(1000, 1100));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Landkarte.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNew_Windows = new QAction(MainWindow);
        actionNew_Windows->setObjectName(QString::fromUtf8("actionNew_Windows"));
        actionDatenba = new QAction(MainWindow);
        actionDatenba->setObjectName(QString::fromUtf8("actionDatenba"));
        actionDatenbank = new QAction(MainWindow);
        actionDatenbank->setObjectName(QString::fromUtf8("actionDatenbank"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_pic = new QLabel(centralwidget);
        label_pic->setObjectName(QString::fromUtf8("label_pic"));
        label_pic->setEnabled(true);
        label_pic->setGeometry(QRect(0, -20, 1000, 1000));
        label_pic->setMinimumSize(QSize(500, 500));
        label_pic->setMaximumSize(QSize(1000, 1000));
        label_pic->setMouseTracking(false);
        label_pic->setPixmap(QPixmap(QString::fromUtf8(":/Landkarte.jpg")));
        label_pic->setScaledContents(true);
        Frankreich = new QPushButton(centralwidget);
        Frankreich->setObjectName(QString::fromUtf8("Frankreich"));
        Frankreich->setGeometry(QRect(270, 580, 141, 161));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Frankreich->sizePolicy().hasHeightForWidth());
        Frankreich->setSizePolicy(sizePolicy);
        Frankreich->setMinimumSize(QSize(0, 151));
        Frankreich->setCheckable(false);
        Frankreich->setAutoDefault(false);
        Frankreich->setFlat(true);
        Deutschland = new QPushButton(centralwidget);
        Deutschland->setObjectName(QString::fromUtf8("Deutschland"));
        Deutschland->setGeometry(QRect(420, 470, 111, 151));
        Deutschland->setFlat(true);
        Spanien = new QPushButton(centralwidget);
        Spanien->setObjectName(QString::fromUtf8("Spanien"));
        Spanien->setGeometry(QRect(140, 740, 151, 161));
        Spanien->setFlat(true);
        Portugal = new QPushButton(centralwidget);
        Portugal->setObjectName(QString::fromUtf8("Portugal"));
        Portugal->setGeometry(QRect(80, 750, 61, 131));
        Portugal->setFlat(true);
        Andorra = new QPushButton(centralwidget);
        Andorra->setObjectName(QString::fromUtf8("Andorra"));
        Andorra->setGeometry(QRect(290, 750, 41, 41));
        Andorra->setFlat(true);
        Belgien = new QPushButton(centralwidget);
        Belgien->setObjectName(QString::fromUtf8("Belgien"));
        Belgien->setGeometry(QRect(350, 540, 71, 41));
        Belgien->setFlat(true);
        Niederlande = new QPushButton(centralwidget);
        Niederlande->setObjectName(QString::fromUtf8("Niederlande"));
        Niederlande->setGeometry(QRect(350, 490, 71, 51));
        Niederlande->setFlat(true);
        Schweiz = new QPushButton(centralwidget);
        Schweiz->setObjectName(QString::fromUtf8("Schweiz"));
        Schweiz->setGeometry(QRect(410, 630, 61, 61));
        Schweiz->setFlat(true);
        Oesterreich = new QPushButton(centralwidget);
        Oesterreich->setObjectName(QString::fromUtf8("Oesterreich"));
        Oesterreich->setGeometry(QRect(470, 620, 111, 51));
        Oesterreich->setFlat(true);
        Grossbritannien = new QPushButton(centralwidget);
        Grossbritannien->setObjectName(QString::fromUtf8("Grossbritannien"));
        Grossbritannien->setGeometry(QRect(230, 320, 91, 221));
        Grossbritannien->setFlat(true);
        Irland = new QPushButton(centralwidget);
        Irland->setObjectName(QString::fromUtf8("Irland"));
        Irland->setGeometry(QRect(150, 400, 81, 91));
        Irland->setFlat(true);
        Island = new QPushButton(centralwidget);
        Island->setObjectName(QString::fromUtf8("Island"));
        Island->setGeometry(QRect(120, 90, 91, 81));
        Island->setFlat(true);
        Polen = new QPushButton(centralwidget);
        Polen->setObjectName(QString::fromUtf8("Polen"));
        Polen->setGeometry(QRect(530, 470, 151, 101));
        Polen->setFlat(true);
        Tschechien = new QPushButton(centralwidget);
        Tschechien->setObjectName(QString::fromUtf8("Tschechien"));
        Tschechien->setGeometry(QRect(530, 570, 71, 51));
        Tschechien->setFlat(true);
        Slowakei = new QPushButton(centralwidget);
        Slowakei->setObjectName(QString::fromUtf8("Slowakei"));
        Slowakei->setGeometry(QRect(600, 570, 71, 51));
        Slowakei->setFlat(true);
        Ungarn = new QPushButton(centralwidget);
        Ungarn->setObjectName(QString::fromUtf8("Ungarn"));
        Ungarn->setGeometry(QRect(580, 620, 91, 51));
        Ungarn->setFlat(true);
        Italien = new QPushButton(centralwidget);
        Italien->setObjectName(QString::fromUtf8("Italien"));
        Italien->setGeometry(QRect(410, 700, 171, 231));
        Italien->setFlat(true);
        Slowenien = new QPushButton(centralwidget);
        Slowenien->setObjectName(QString::fromUtf8("Slowenien"));
        Slowenien->setGeometry(QRect(500, 670, 71, 31));
        Slowenien->setFlat(true);
        Kroatien = new QPushButton(centralwidget);
        Kroatien->setObjectName(QString::fromUtf8("Kroatien"));
        Kroatien->setGeometry(QRect(570, 670, 61, 31));
        Kroatien->setFlat(true);
        Bosnien = new QPushButton(centralwidget);
        Bosnien->setObjectName(QString::fromUtf8("Bosnien"));
        Bosnien->setGeometry(QRect(580, 700, 51, 51));
        Bosnien->setFlat(true);
        Montenegro = new QPushButton(centralwidget);
        Montenegro->setObjectName(QString::fromUtf8("Montenegro"));
        Montenegro->setGeometry(QRect(630, 740, 31, 31));
        Montenegro->setFlat(true);
        Kosovo = new QPushButton(centralwidget);
        Kosovo->setObjectName(QString::fromUtf8("Kosovo"));
        Kosovo->setGeometry(QRect(660, 740, 31, 21));
        Kosovo->setFlat(true);
        Serbien = new QPushButton(centralwidget);
        Serbien->setObjectName(QString::fromUtf8("Serbien"));
        Serbien->setGeometry(QRect(630, 670, 61, 71));
        Serbien->setFlat(true);
        Rumanien = new QPushButton(centralwidget);
        Rumanien->setObjectName(QString::fromUtf8("Rumanien"));
        Rumanien->setGeometry(QRect(690, 600, 81, 111));
        Rumanien->setFlat(true);
        Albanien = new QPushButton(centralwidget);
        Albanien->setObjectName(QString::fromUtf8("Albanien"));
        Albanien->setGeometry(QRect(630, 770, 41, 71));
        Albanien->setFlat(true);
        Mazedonien = new QPushButton(centralwidget);
        Mazedonien->setObjectName(QString::fromUtf8("Mazedonien"));
        Mazedonien->setGeometry(QRect(670, 760, 41, 51));
        Mazedonien->setFlat(true);
        Bulgarien = new QPushButton(centralwidget);
        Bulgarien->setObjectName(QString::fromUtf8("Bulgarien"));
        Bulgarien->setGeometry(QRect(710, 710, 91, 71));
        Bulgarien->setFlat(true);
        Griechenland = new QPushButton(centralwidget);
        Griechenland->setObjectName(QString::fromUtf8("Griechenland"));
        Griechenland->setGeometry(QRect(670, 810, 151, 151));
        Griechenland->setFlat(true);
        Moldawien = new QPushButton(centralwidget);
        Moldawien->setObjectName(QString::fromUtf8("Moldawien"));
        Moldawien->setGeometry(QRect(770, 580, 51, 71));
        Moldawien->setFlat(true);
        Ukraine = new QPushButton(centralwidget);
        Ukraine->setObjectName(QString::fromUtf8("Ukraine"));
        Ukraine->setGeometry(QRect(700, 490, 231, 91));
        Ukraine->setFlat(true);
        Weissrussland = new QPushButton(centralwidget);
        Weissrussland->setObjectName(QString::fromUtf8("Weissrussland"));
        Weissrussland->setGeometry(QRect(700, 420, 121, 71));
        Weissrussland->setFlat(true);
        Daenemark = new QPushButton(centralwidget);
        Daenemark->setObjectName(QString::fromUtf8("Daenemark"));
        Daenemark->setGeometry(QRect(440, 400, 71, 71));
        Daenemark->setFlat(true);
        Norwegen = new QPushButton(centralwidget);
        Norwegen->setObjectName(QString::fromUtf8("Norwegen"));
        Norwegen->setGeometry(QRect(410, 160, 81, 241));
        Norwegen->setFlat(true);
        Schweden = new QPushButton(centralwidget);
        Schweden->setObjectName(QString::fromUtf8("Schweden"));
        Schweden->setGeometry(QRect(490, 120, 101, 281));
        Schweden->setFlat(true);
        Finnland = new QPushButton(centralwidget);
        Finnland->setObjectName(QString::fromUtf8("Finnland"));
        Finnland->setGeometry(QRect(600, 80, 101, 241));
        Finnland->setFlat(true);
        Estland = new QPushButton(centralwidget);
        Estland->setObjectName(QString::fromUtf8("Estland"));
        Estland->setGeometry(QRect(630, 320, 71, 41));
        Estland->setFlat(true);
        Lettland = new QPushButton(centralwidget);
        Lettland->setObjectName(QString::fromUtf8("Lettland"));
        Lettland->setGeometry(QRect(610, 360, 91, 41));
        Lettland->setFlat(true);
        Litauen = new QPushButton(centralwidget);
        Litauen->setObjectName(QString::fromUtf8("Litauen"));
        Litauen->setGeometry(QRect(630, 400, 71, 61));
        Litauen->setFlat(true);
        MainWindow->setCentralWidget(centralwidget);
        label_pic->raise();
        Finnland->raise();
        Montenegro->raise();
        Tschechien->raise();
        Moldawien->raise();
        Slowenien->raise();
        Bosnien->raise();
        Griechenland->raise();
        Estland->raise();
        Norwegen->raise();
        Lettland->raise();
        Ungarn->raise();
        Deutschland->raise();
        Kosovo->raise();
        Mazedonien->raise();
        Portugal->raise();
        Ukraine->raise();
        Serbien->raise();
        Weissrussland->raise();
        Schweden->raise();
        Rumanien->raise();
        Spanien->raise();
        Polen->raise();
        Belgien->raise();
        Andorra->raise();
        Schweiz->raise();
        Bulgarien->raise();
        Niederlande->raise();
        Italien->raise();
        Irland->raise();
        Island->raise();
        Grossbritannien->raise();
        Frankreich->raise();
        Albanien->raise();
        Oesterreich->raise();
        Litauen->raise();
        Kroatien->raise();
        Daenemark->raise();
        Slowakei->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuDatei = new QMenu(menubar);
        menuDatei->setObjectName(QString::fromUtf8("menuDatei"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuDatei->menuAction());
        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew_Windows);
        menuDatei->addAction(actionDatenbank);

        retranslateUi(MainWindow);

        Frankreich->setDefault(false);
        Deutschland->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew_Windows->setText(QApplication::translate("MainWindow", "Wie benutze ich die Karte?", nullptr));
        actionDatenba->setText(QApplication::translate("MainWindow", "Datenbank", nullptr));
        actionDatenbank->setText(QApplication::translate("MainWindow", "Datenbank", nullptr));
        label_pic->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "Info", nullptr));
        menuDatei->setTitle(QApplication::translate("MainWindow", "Datei", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
