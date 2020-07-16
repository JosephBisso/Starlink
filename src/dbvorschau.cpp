#include "dbvorschau.h"
#include "ui_dbvorschau.h"
#include "datenbank.h"

dbVorschau::dbVorschau(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dbVorschau)
{
    ui->setupUi(this);

    VorschauFillTable();
}

dbVorschau::~dbVorschau()
{
    delete ui;
}

//Die Tabelle wird gefüllt
void dbVorschau::VorschauFillTable()
{
    //Objekt der Klasse Datenbank erstellen, um die Methoden der Klasse Datenbank benutzen zu können
    Datenbank DbVorschauDE, DbVorschauFR, DbVorschauIT, DbVorschauAL, DbVorschauES;

    QString Datum = DbVorschauDE.gibDatum("01", "06"); //setzt und gibt Datum aus Tag "01" und Monat "06".
                                                       //Hier: 01/06/2020.

    QString InfiziierteDE = QString::number(DbVorschauDE.gibInfiierte(Datum, "DE"));
   // Die Anzahl von Infiierte am "Datum" für Deutschland aus der Datenbank
    //geslesen und für das Objekt DbVorschau(.Infiziierte) gesetzt und an uns zurück gegeben.
    //Außerdem wird diise Anzahl aus int to QString konvertiert und an den Variabel "InfiziierteDE gegeben"

    //Analog:
    QString TodeDE = QString::number(DbVorschauDE.gibTode(Datum, "DE" ));
    QString LandDE = DbVorschauDE.gibLand("DE");
    QString gsmtInfiDE = QString::number (DbVorschauDE.gibGesamtInfizierte("06", "DE"));
    QString gsmtTodeDE = QString::number (DbVorschauDE.gibGesamtTode("06", "DE"));

    QString InfiziierteFR = QString::number(DbVorschauFR.gibInfiierte(Datum, "FR"));
    QString TodeFR = QString::number(DbVorschauFR.gibTode(Datum, "FR" ));
    QString LandFR = DbVorschauFR.gibLand("FR");
    QString gsmtInfiFR = QString::number (DbVorschauFR.gibGesamtInfizierte("06", "FR"));
    QString gsmtTodeFR = QString::number (DbVorschauFR.gibGesamtTode("06", "FR"));


    QString InfiziierteIT = QString::number(DbVorschauIT.gibInfiierte(Datum, "IT"));
    QString TodeIT = QString::number(DbVorschauIT.gibTode(Datum, "IT" ));
    QString LandIT = DbVorschauIT.gibLand("IT");
    QString gsmtInfiIT = QString::number (DbVorschauIT.gibGesamtInfizierte("06", "IT"));
    QString gsmtTodeIT = QString::number (DbVorschauIT.gibGesamtTode("06", "IT"));


    QString InfiziierteAL = QString::number(DbVorschauAL.gibInfiierte(Datum, "AL"));
    QString TodeAL = QString::number(DbVorschauAL.gibTode(Datum, "AL" ));
    QString LandAL = DbVorschauAL.gibLand("AL");
    QString gsmtInfiAL = QString::number (DbVorschauAL.gibGesamtInfizierte("06", "AL"));
    QString gsmtTodeAL = QString::number (DbVorschauAL.gibGesamtTode("06", "AL"));


    QString InfiziierteES = QString::number(DbVorschauES.gibInfiierte(Datum, "ES"));
    QString TodeES = QString::number(DbVorschauES.gibTode(Datum, "ES" ));
    QString LandES = DbVorschauAL.gibLand("ES");
    QString gsmtInfiES = QString::number (DbVorschauES.gibGesamtInfizierte("06", "ES"));
    QString gsmtTodeES = QString::number (DbVorschauES.gibGesamtTode("06", "ES"));


    ui->tblVorschau->setRowCount(0);
    ui->tblVorschau->insertRow(0);
    ui->tblVorschau->setItem(0, 1, new QTableWidgetItem(Datum));
    ui->tblVorschau->setItem(0, 4, new QTableWidgetItem("Juni")); //hier "Juni" anstatt "06" fürs Verständnis
    ui->tblVorschau->setItem(0, 2, new QTableWidgetItem(InfiziierteDE));
    ui->tblVorschau->setItem(0, 5, new QTableWidgetItem(gsmtInfiDE));
    ui->tblVorschau->setItem(0, 3, new QTableWidgetItem(TodeDE));
    ui->tblVorschau->setItem(0, 6, new QTableWidgetItem(gsmtTodeDE));
    ui->tblVorschau->setItem(0, 0, new QTableWidgetItem(LandDE));

    ui->tblVorschau->insertRow(1);
    ui->tblVorschau->setItem(1, 1, new QTableWidgetItem(Datum));
    ui->tblVorschau->setItem(1, 4, new QTableWidgetItem("Juni"));
    ui->tblVorschau->setItem(1, 2, new QTableWidgetItem(InfiziierteFR));
    ui->tblVorschau->setItem(1, 5, new QTableWidgetItem(gsmtInfiFR));
    ui->tblVorschau->setItem(1, 3, new QTableWidgetItem(TodeFR));
    ui->tblVorschau->setItem(1, 6, new QTableWidgetItem(gsmtTodeFR));
    ui->tblVorschau->setItem(1, 0, new QTableWidgetItem(LandFR));

    ui->tblVorschau->insertRow(2);
    ui->tblVorschau->setItem(2, 1, new QTableWidgetItem(Datum));
    ui->tblVorschau->setItem(2, 4, new QTableWidgetItem("Juni"));
    ui->tblVorschau->setItem(2, 2, new QTableWidgetItem(InfiziierteES));
    ui->tblVorschau->setItem(2, 5, new QTableWidgetItem(gsmtInfiES));
    ui->tblVorschau->setItem(2, 3, new QTableWidgetItem(TodeES));
    ui->tblVorschau->setItem(2, 6, new QTableWidgetItem(gsmtTodeES));
    ui->tblVorschau->setItem(2, 0, new QTableWidgetItem(LandES));

    ui->tblVorschau->insertRow(3);
    ui->tblVorschau->setItem(3, 1, new QTableWidgetItem(Datum));
    ui->tblVorschau->setItem(3, 4, new QTableWidgetItem("Juni"));
    ui->tblVorschau->setItem(3, 2, new QTableWidgetItem(InfiziierteIT));
    ui->tblVorschau->setItem(3, 5, new QTableWidgetItem(gsmtInfiIT));
    ui->tblVorschau->setItem(3, 3, new QTableWidgetItem(TodeIT));
    ui->tblVorschau->setItem(3, 6, new QTableWidgetItem(gsmtTodeIT));
    ui->tblVorschau->setItem(3, 0, new QTableWidgetItem(LandIT));

    ui->tblVorschau->insertRow(4);
    ui->tblVorschau->setItem(4, 1, new QTableWidgetItem(Datum));
    ui->tblVorschau->setItem(4, 4, new QTableWidgetItem("Juni"));
    ui->tblVorschau->setItem(4, 2, new QTableWidgetItem(InfiziierteAL));
    ui->tblVorschau->setItem(4, 5, new QTableWidgetItem(gsmtInfiAL));
    ui->tblVorschau->setItem(4, 3, new QTableWidgetItem(TodeAL));
    ui->tblVorschau->setItem(4, 6, new QTableWidgetItem(gsmtTodeAL));
    ui->tblVorschau->setItem(4, 0, new QTableWidgetItem(LandAL));

}
