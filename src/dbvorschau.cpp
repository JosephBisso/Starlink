#include "dbvorschau.h"
#include "ui_dbvorschau.h"
#include "datenbank.h"
#include "ui_datenbank.h"

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

//Die Tabelle wird gefüllt. Das ausführliche Schreiben der Methoden dient zur Verifikation deren Effektivität
void dbVorschau::VorschauFillTable()
{
    ui->tblVorschau->setRowCount(0);

    //Objekt der Klasse Datenbank erstellen, um die Methoden der Klasse Datenbank benutzen zu können
    databank DbVorschau[6]; //Es werden Zahlen aus 6 Länder vorgeschaut.

        DbVorschau[0].geoID = "DE"; //es werden geoIDs von ausgewählten Länder als Attribut gespeichert.
                                    //Siehe Liete geoID
        DbVorschau[1].geoID = "FR";
        DbVorschau[2].geoID = "NL";
        DbVorschau[3].geoID = "ES";
        DbVorschau[4].geoID = "AL";
        DbVorschau[5].geoID = "IT";


    QString Datum[6],

            heuteMonat[6],

            Infiziierte[6],
            Tode[6],
            GesamtInfi[6],
            GesamtTode[6],

            Land[6];


   // Die Anzahl von Infiierte am "Datum" für Deutschland aus der Datenbank
    //geslesen und für das Objekt DbVorschau(.Infiziierte) gesetzt und an uns zurück gegeben.
    //Außerdem wird diise Anzahl aus int to QString konvertiert und an den Variabel "InfiziierteDE gegeben"


    //hier wird das aktuelles Datum benutzt und auf das für die Datenbank benutzte Format ("01" anstatt "1") gesetzt.
    QDate qdHeute = QDate::currentDate();
    QString qsHeuteMonat[6];

    for (int i=0; i<6; i++)
    {
        qsHeuteMonat[i] = QString::number(qdHeute.month()-i); //Aus dem aktuellen Datum wird den Monat gewonnen.
                                                              //Der wird dann um i reduziert um verschiedene Monate
                                                              //vorzuschauen

        if (qsHeuteMonat[i].size()==1)
        {
            qsHeuteMonat[i].insert(0, "0");      //Aus Monat im Format "m" wird Monat im Format "mm" ("06" statt "6")
        }

    }
    QString qsHeuteTag = QString::number(qdHeute.day());
        if (qsHeuteTag.size()==1)
        {
            qsHeuteTag.insert(0, "0"); //Aus Tag im Format "d" wird Tag im Format "dd" ("1" statt "01")
        }

    for (int i=0; i<6; i++)
    {
        Datum[i] = DbVorschau[i].gibDatum(qsHeuteTag, qsHeuteMonat[i]); /*gib von Tag "dd" und Monat "mm"
                                                                          ein Datum in einem Format
                                                                          , das von der Datenbank gelesen und
                                                                           verstehen werden kann
                                                                          */

        heuteMonat[i] = DbVorschau[i].gibMonat(qsHeuteMonat[i]);    /* Gibt aus Monat im Format "mm" den Namen des Monats
                                                                     */


        Infiziierte[i] = QString::number(DbVorschau[i].gibInfiierte(Datum[i], DbVorschau[i].geoID)); // Die Anzahl
        //von Infiierte am "Datum[i]" für ein Land mit geoID DbVorschau[i].geoID wird aus der Datenbank
        //geslesen und in Infiziierte[i] gespeichert.
        //Außerdem wird diise Anzahl aus int to QString konvertiert und an den Variabel "InfiziierteDE gegeben"

        //analog...
        Tode[i] = QString::number(DbVorschau[i].gibTode(Datum[i],DbVorschau[i].geoID));
        Land[i] = DbVorschau[i].gibLand(DbVorschau[i].geoID);
        GesamtInfi[i] = QString::number (DbVorschau[i].gibGesamtInfizierte(qsHeuteMonat[i],DbVorschau[i].geoID));
        GesamtTode[i] = QString::number (DbVorschau[i].gibGesamtTode(qsHeuteMonat[i], DbVorschau[i].geoID));

//Tabelle wird gefüllt. Zeilen aus der Vorlesung geguckt und angepasst.


        ui->tblVorschau->insertRow(i);
        ui->tblVorschau->setItem(i, 0, new QTableWidgetItem(Land[i]));
        ui->tblVorschau->setItem(i, 1, new QTableWidgetItem(Datum[i]));
        ui->tblVorschau->setItem(i, 2, new QTableWidgetItem(Infiziierte[i]));
        ui->tblVorschau->setItem(i, 3, new QTableWidgetItem(Tode[i]));
        ui->tblVorschau->setItem(i, 4, new QTableWidgetItem(heuteMonat[i]));
        ui->tblVorschau->setItem(i, 5, new QTableWidgetItem(GesamtInfi[i]));
        ui->tblVorschau->setItem(i, 6, new QTableWidgetItem(GesamtTode[i]));
    }
 }
