#include "mainwindow.h"
#include "ui_mainwindow.h"
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
//
    ui->setupUi(this);

    Downloader* startUpDownloader = new Downloader;
    startUpDownloader->updateRawData();
    connect(startUpDownloader, SIGNAL(updateSuccessful()), this, SLOT(dataUpdateConfirmed()));
//    startUpDownloader->deleteLater();

    QPixmap pix(":/img/Landkarte.jpg");
    ui->label_pic->setPixmap(pix.scaled(1000,1000));

    dbMain.jsDbShort(); /*Eine Verbindung mit der Datenbank wird automatisch am Start des Programms aufgebaut
                          und Auszug aus der covidRaw Datei wird dabei erstellt.
                          dbMain ist ein privates
                          Attribut vom Typ databank der Klasse MainWindow.
                          jsBdShort ist eine
                          Methode der Klasse databank
                        */

}


MainWindow::~MainWindow()
{

    delete ui;
}

//Ein neues Fenster zum Interagieren mit der Datenbank wird erstellt
void MainWindow::on_actionDatenbank_triggered()
{
    Datenbank* datenbank = new Datenbank(this);
            datenbank->show();
}

void MainWindow::on_actionNew_Windows_triggered()
{
    QMessageBox::information(this, "Information", "Um genauere Informationen zu den einzelnen Ländern zu bekommen, müssen diese ungefähr mittig angeklickt werden.");
}

void MainWindow::on_actionDatenquelle_aendern_triggered()
{

}

//
//Hinweis: Es sind weitere Methoden nach den Länder-Signal Definitionen definiert
//

void MainWindow::on_Frankreich_clicked()
{

}

void MainWindow::on_Deutschland_clicked()
{

}

void MainWindow::on_Spanien_clicked()
{

}

void MainWindow::on_Portugal_clicked()
{

}

void MainWindow::on_Belgien_clicked()
{

}

void MainWindow::on_Niederlande_clicked()
{

}

void MainWindow::on_Schweiz_clicked()
{

}

void MainWindow::on_Oesterreich_clicked()
{

}

void MainWindow::on_Grossbritannien_clicked()
{

}

void MainWindow::on_Irland_clicked()
{

}

void MainWindow::on_Island_clicked()
{

}

void MainWindow::on_Polen_clicked()
{

}

void MainWindow::on_Tschechien_clicked()
{

}

void MainWindow::on_Slowakei_clicked()
{

}

void MainWindow::on_Ungarn_clicked()
{

}

void MainWindow::on_Italien_clicked()
{

}

void MainWindow::on_Slowenien_clicked()
{

}

void MainWindow::on_Kroatien_clicked()
{

}

void MainWindow::on_Montenegro_clicked()
{

}

void MainWindow::on_Kosovo_clicked()
{

}

void MainWindow::on_Serbien_clicked()
{

}

void MainWindow::on_Rumanien_clicked()
{

}

void MainWindow::on_Albanien_clicked()
{

}

void MainWindow::on_Mazedonien_clicked()
{

}

void MainWindow::on_Bulgarien_clicked()
{

}

void MainWindow::on_Griechenland_clicked()
{

}

void MainWindow::on_Moldawien_clicked()
{

}

void MainWindow::on_Ukraine_clicked()
{

}

void MainWindow::on_Weissrussland_clicked()
{

}

void MainWindow::on_Daenemark_clicked()
{

}

void MainWindow::on_Norwegen_clicked()
{

}

void MainWindow::on_Schweden_clicked()
{

}

void MainWindow::on_Finnland_clicked()
{

}

void MainWindow::on_Estland_clicked()
{

}

void MainWindow::on_Lettland_clicked()
{

}

void MainWindow::on_Litauen_clicked()
{

}

//Slot deaktiviert den Button und erzeugt eine Instanz der Klasse Downloader zum Herunterladen neuer Daten.
void MainWindow::on_refreshButton_clicked()
{
    Downloader* myDownloader = new Downloader;
    myDownloader->updateRawData();
    connect(myDownloader, SIGNAL(updateSuccessful()), this, SLOT(dataUpdateConfirmed()));

}


//Dieser Slot reagiert auf das Signal "updateSuccessful" der Downloader-Klasse. Er verändert den Timestamp in der
//Textbox, die die letzte Aktualisierung anzeigt.
void MainWindow::dataUpdateConfirmed()
{
    QString refreshStateText = "Letzter Stand: ";
    refreshStateText.append(dbMain.gibUpdateDatum()); //Das Datum des letzten hinzugefügten Eintrags wird gegeben
    ui->statusbar->showMessage(refreshStateText);
}

void MainWindow::on_Bosnien_clicked()
{

}
