#include "deutschland.h"
#include "ui_deutschland.h"

#include <QDialog>
#include <QMessageBox>  //Dienst nur der Darstellung, damit du verstehst.

//Muss included sein!!!!!!!!!!!!!!1
#include "laender.h"
#include "databank.h" // aufpassen: datAbank und nicht datENbank

Deutschland::Deutschland(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Deutschland)
{
    ui->setupUi(this);

    /*
     * Beispiel Datenzugriff für Toni: Ich zeige dir, wie du auf die Daten zugreifst
     * (1) Erstmal ein Element aus der Klasse "Laender" erstellen
     * (2) Die Methode "gibLandDaten für den gewünschten "Tag" und "Monat" für ein land mit geoID "geoID"
            Ich kann dir ein Liste von GeoIDs geben, wenn du sie nicht kennst
     * (3) Dann dich für eine der beiden unten beschrieben Vorgehensweisen entscheiden
     */

   //(1)
    Laender Land;

   //(2)
    Land.gibLandDaten("01", "04", "DE"); //Oder Land.gibLandDaten (ui->Day, ui->Month, "DE")


   //(3)

       // (3.1)     entweder direkt so "Land.DbLandDaten.Datum", "Land.DbLandDaten.Infiziierte"
                                          //fürs Datum              für Anzahl Infiziierte an dem Datum
    QMessageBox::information(this, Land.DbLandDaten.Datum , QString::number(Land.DbLandDaten.Infiziierte));

       //(3.2)
    QString Datum = Land.DbLandDaten.Datum;
    int Tode = Land.DbLandDaten.Tode;


                    //oder so; mit Datum = Land.DbLandDaten.Datum, Tode = Land.DbLandDaten.Tode;
                                            //fürs Datum                  für Anzahl von Tode an dem Datum
    QMessageBox::information(this, Datum , QString::number(Tode));

    //QMessageBox dient hier lediglich zur Darstellung, damit du verstehst was abgehst
    //(Du kannst das Programm ausführen)

    //Klemmens. Analog für die Gesammtzahlen:
   // hier beachten: Gesamst Zahlen für den Monat "Monat" im Land mit geoID "geoID"

    Land.DbLandDaten.gibGesamtInfizierte("04", "DE");

    Land.DbLandDaten.gibGesamtTode("04", "DE");


}

Deutschland::~Deutschland()
{
    delete ui;
}
