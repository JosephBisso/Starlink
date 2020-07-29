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

//Rechnet und speichert Gesamtinfiziierte für alle Monate in einem Feld und gibt uns einen
 //Zeiger zurück, der auf dieses Feld zeigt.
double* Laender::InfiMonat (QString geoID)
{
    double infMonat [12]; //Ein Feld mit Größe 12 wir erstellt.

    double* InfiMonatSTR = infMonat; //Ein Zeiger der auf das Feld zeigt wird erstellt.

    QString Monat;
    /*Es werden nacheinander ein Attribut vom Typ databank der Klasse Laender "DbLandDaten" und eine Methode
      von der Klasse databank "gibGesamtInfizierte (Monat, geoID)" mit RückgabeTyp int gerufen
    */

    for (int i=0; i<13; i++)
    {
        Monat = QString::number(i+1); // Die zahl des Monat wird ajustiert weil i mit 0 anfängt
            if (Monat.size()==1)
            {
                Monat.insert(0,"0"); //Aus Monat im Format "m" wird Monat im Format "mm" ("06" statt "6")
            }

        infMonat[i]= DbLandDaten.gibGesamtInfizierte(Monat, geoID); // Gesamt Infiziierte für jedem Monat für ein
                                                       // Land mit einem geoID "geoID" (Siehe Liste geoID in
                                                                 // den Resources Dateien) wird in
                                                       //einem Element des Feldes gespeichert.

    }

    return InfiMonatSTR; //Der Zeiger der auf das Feld mit all den Daten drin wird zurückgegeben
}


//Analog zu InfiMonat
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
        Monat = QString::number(i+1);
            if (Monat.size()==1)
            {
                Monat.insert(0,"0");
            }

        todMonat[i]= DbLandDaten.gibGesamtTode(Monat, geoID); // Gesamt Infiziierte für Januar ("01")

    }

    return TodeMonatSTR;
}
