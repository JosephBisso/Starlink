#include "laender.h"
#include "databank.h"

Laender::Laender(QObject *parent) : QObject(parent)
{
   //(gibLandDaten(ui->,ui->, ui->));
   //int ok = DbLandDaten.Infiziierte;

}
 // Für ein Tag "dd", und Monat "mm" und für ein Land mit geoID "geoID"
//wird erstmal die geoID gespeichert und dann die Daten aus der Datenbank "covidShort.Json"
//dank derMethonde aus der Klasse databank  gelesen und  im Attribut "DbLandDaten" vom Typ databank
// der Klasse Laender gespeichert.
void Laender::gibLandDaten(QString Tag, QString Monat, QString geoID)
{
    DbLandDaten.geoID = geoID;

    QString Datum = DbLandDaten.gibDatum(Tag, Monat);

    DbLandDaten.gibInfiierte(Datum, geoID);

    DbLandDaten.gibTode(Datum, geoID );

    DbLandDaten.gibLand(geoID);

    DbLandDaten.gibGesamtInfizierte(Datum, geoID);

    DbLandDaten.gibGesamtTode(Datum, geoID);

}

double* Laender::InfiMonat (QString geoID)
{
    double infMonat [12];

    double* InfiMonatSTR = infMonat;

    QString Monat;
    /*Es werden nacheinander ein Attribut vom Typ databank der Klasse Laender "DbLandDaten" und eine Methode
      von der Klasse databank "gibGesamtInfizierte (Monat, geoID)" mit RückgabeTyp int gerufen
    */

    for (int i=0; i<13; i++)
    {
        Monat = QString::number(i);
            if (Monat.size()==1)
            {
                Monat.insert(0,"0");
            }

        infMonat[i]= DbLandDaten.gibGesamtInfizierte(Monat, geoID); // Gesamt Infiziierte für Januar ("01")

    }

    return InfiMonatSTR;
}

double* Laender::TodeMonat(QString geoID)
{
    double todMonat [12];

    double* TodeMonatSTR = todMonat;

    QString Monat;
    /*Es werden nacheinander ein Attribut vom Typ databank der Klasse Laender "DbLandDaten" und eine Methode
      von der Klasse databank "gibGesamtInfizierte (Monat, geoID)" mit RückgabeTyp int gerufen
    */

    for (int i=0; i<13; i++)
    {
        Monat = QString::number(i);
            if (Monat.size()==1)
            {
                Monat.insert(0,"0");
            }

        todMonat[i]= DbLandDaten.gibGesamtTode(Monat, geoID); // Gesamt Infiziierte für Januar ("01")

    }

    return TodeMonatSTR;
}
