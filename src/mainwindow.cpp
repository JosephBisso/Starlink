#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydialog.h"
#include "frankreich.h"
#include "deutschland.h"
#include <QPixmap>
#include <QtGui>
#include <QtCore>
#include <qicon.h>
#include <QMessageBox>
#include "downloader.h"

#include "databank.h"
#include "datenbank.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/Landkarte.jpg");

    ui->label_pic->setPixmap(pix.scaled(1000,1000));

    dbMain.jsDbShort();

//    QDateTime upDateTime = QFileInfo("covidRaw.json").birthTime();
//    QString refreshStateText = "Daten aktualisiert am: ";
//    refreshStateText.append(upDateTime.toString());
//    ui->refreshState->setText(refreshStateText);

}


MainWindow::~MainWindow()
{
    delete ui;
}

//...
void MainWindow::on_actionDatenbank_triggered()
{
    Datenbank* datenbank = new Datenbank(this);
            datenbank->show();
}

void MainWindow::on_actionNew_Windows_triggered()
{
    QMessageBox::information(this, "Information", "Um genauere Informationen zu den einzelnen Ländern zu bekommen, müssen diese ungefähr mittig angeklickt werden.");
}

void MainWindow::on_Frankreich_clicked()
{
    Frankreich mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Deutschland_clicked()
{
    Deutschland mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}




void MainWindow::on_Spanien_clicked()
{
    Spanien mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Portugal_clicked()
{
    Portugal mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Andorra_clicked()
{
    Andorra mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Belgien_clicked()
{
    Belgien mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Niederlande_clicked()
{
    Niederlande mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Schweiz_clicked()
{
    Schweiz mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Oesterreich_clicked()
{
    Oesterreich mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Grossbritannien_clicked()
{
    Grossbritannien mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Irland_clicked()
{
    Irland mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Island_clicked()
{
    Island mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Polen_clicked()
{
    Polen mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Tschechien_clicked()
{
    Tschechien mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Slowakei_clicked()
{
    Slowakei mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Ungarn_clicked()
{
    Ungarn mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Italien_clicked()
{
    Italien mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Slowenien_clicked()
{
    Slowenien mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Kroatien_clicked()
{
    Kroatien mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Montenegro_clicked()
{
    Montenegro mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Kosovo_clicked()
{
    Kosovo mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Serbien_clicked()
{
    Serbien mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Rumanien_clicked()
{
    Rumanien mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Albanien_clicked()
{
    Albanien mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Mazedonien_clicked()
{
    Mazedonien mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Bulgarien_clicked()
{
    Bulgarien mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Griechenland_clicked()
{
    Griechenland mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Moldawien_clicked()
{
    Moldawien mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Ukraine_clicked()
{
    Ukraine mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Weissrussland_clicked()
{
    Weissrussland mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Daenemark_clicked()
{
    Daenemark mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Norwegen_clicked()
{
    Norwegen mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Schweden_clicked()
{
    Schweden mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Finnland_clicked()
{
    Finnland mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Estland_clicked()
{
    Estland mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Lettland_clicked()
{
    Lettland mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

void MainWindow::on_Litauen_clicked()
{
    Lettland mDialog;
       mDialog.setModal(true);
       mDialog.exec();
}

//Slot deaktiviert den Button und erzeugt eine Instanz der Klasse Downloader zum Herunterladen neuer Daten.
void MainWindow::on_refreshButton_clicked()
{
    ui->refreshButton->setDown(true);
    Downloader* myDownloader = new Downloader;
    myDownloader->updateRawData();
    connect(myDownloader, SIGNAL(updateSuccessful()), this, SLOT(dataUpdateConfirmed()));

}

//Dieser Slot reagiert auf das Signal "updateSuccessful" der Downloader-Klasse. Er verändert den Timestamp in der
//Textbox, die die letzte Aktualisierung anzeigt und bringt den "refreshButton" wieder in Normalstellung.
void MainWindow::dataUpdateConfirmed()
{
    QDateTime upDateTime = QDateTime::currentDateTime();
    QString refreshStateText = "Daten aktualisiert am: ";
    refreshStateText.append(upDateTime.toString());
    ui->refreshState->setText(refreshStateText);
    ui->refreshButton->setDown(false);
}
