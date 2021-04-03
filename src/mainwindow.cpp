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

void MainWindow::on_Frankreich_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("FR");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);

    land->exec();
}

void MainWindow::on_Deutschland_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("DE");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);

    land->exec();
}

void MainWindow::on_Spanien_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("ES");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Portugal_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("PT");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Belgien_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("BE");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Niederlande_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("NL");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Schweiz_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("CH");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Oesterreich_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("AT");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Grossbritannien_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("UK");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Irland_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("IE");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Island_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("IS");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Polen_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("PL");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Tschechien_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("CZ");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Slowakei_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("SK");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Ungarn_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("HU");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Italien_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("IT");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Slowenien_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("SI");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Kroatien_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("HR");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Montenegro_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("ME");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Kosovo_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("XK");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Serbien_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("RS");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Rumanien_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("RO");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Albanien_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("AL");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Mazedonien_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("MK");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Bulgarien_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("BG");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Griechenland_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("EL");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Moldawien_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("MD");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Ukraine_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("UA");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Weissrussland_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("BY");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Daenemark_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("DK");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Norwegen_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("NO");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Schweden_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("SE");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Finnland_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("FI");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Estland_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("EE");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Lettland_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("LV");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Litauen_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("LT");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}

void MainWindow::on_Bosnien_clicked()
{
    Land* land = new Land(this);
    land->setGeoID("BA");
    land->setWindowTitle(land->setTitle());

    QIcon* icon = new QIcon (*land->setIcon());
    land->setWindowIcon(*icon);
    land->exec();
}
