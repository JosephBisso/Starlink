#include "laender.h"
#include "databank.h"

Laender::Laender(QObject *parent) : QObject(parent)
{

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

//Rechnet und speichert Gesamtinfiziierte für alle Monate in einem Feld
void Laender::InfiTodeMonat(QString geoID)
{

    QString Monat;
    /*Es werden nacheinander ein Attribut vom Typ databank der Klasse Laender "DbLandDaten" und eine Methode
      von der Klasse databank "gibGesamtInfizierte (Monat, geoID)" mit RückgabeTyp int gerufen
    */

    for (int i=0; i<12; i++)
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

        todMonat[i]= DbLandDaten.gibGesamtTode(Monat, geoID);

    }

}

//Liest in der Datenbank dank der Methode gibInfiziierte und gibTode die Daten für alle Tage eines Mont vom 1. bis
//zum vom User ausgewählten Datum für ein Land "geoID". Abhängig davon, ob linear true oder falsch ist, werden
//die Daten normal oder logarithmisch gespeichert (ln). Die Anzahl von Tagen, für die Daten gespeichert wurden
//wird zurückgegeben.
int Laender::FillTab(QDate uiDatum, bool linear, QString geoID)
{
    int n = 0;  //Anzahl von Tagen auf 0 gesetzt

    qDebug()<< "geoID = " << geoID << " und uiDatum = " << uiDatum ;

    QString Monat = QString::number(uiDatum.month()); //Der Monat wird aus dem gelesenen Datum auf dem UI gewonnen
        if (Monat.size()==1)
       {
            Monat.insert(0, "0");      //Aus Monat im Format "m" wird Monat im Format "mm" ("06" statt "6")
       }

        qDebug()<< "Monat = " << Monat ;

    for (int i =0; i<31; i++)
    {
        qreal k = uiDatum.day()-i; //qreal ist der für die Graphen unterstützten Typ. Der Tag wird aus dem Datum
                                  //uiDatum gewonnen und substrahiert.


        if (k>0)
        {
            tblInfi[0][i] = k; //tblInfi ist eine Matrix und ein Attribut der Klasse Laender
            tblTode[0][i] = k;

            qDebug()<< "tblInfi[0]["<<i<<"]  (k) = " << k ;

            QString Tag = QString::number(k);
            if (Tag.size()==1){Tag.insert(0, "0");} //Aus Tag im Format "d" wird Monat im Format "dd" ("06" statt "6")

            qDebug()<< "Tag = " << Tag ;

            QString tblDatum = DbLandDaten.gibDatum(Tag, Monat); //Die Methode gibDatum gib das Datum zurück

             qDebug()<< "tblDatum = " << tblDatum ;

            if (linear)
            {
                tblInfi[1][i] = DbLandDaten.gibInfiierte(tblDatum, geoID);
                tblTode[1][i] = DbLandDaten.gibTode(tblDatum, geoID);

                qDebug()<< "lineare tblInfi[1]["<<i<<"]  (für k="<<k<<") = "<< tblInfi[1][i] ;
            }

            else
            {
                qLn(tblInfi[1][i] = qLn(DbLandDaten.gibInfiierte(tblDatum, geoID))); //Logarithmisch
                qLn(tblTode[1][i] = qLn(DbLandDaten.gibTode(tblDatum, geoID)));

                qDebug()<< " logarithmische tblInfi[1]["<<i<<"]  (für k="<<k<<") = "<< tblInfi[1][i] ;
            }

            n +=1;
        }

        else //(für k<=0, kann kein Datum gewonnen werden.)
        {
            qDebug()<< "k ist kleiner gleich null für i = " << i;

            tblInfi[0][i] = -999;
            tblTode[0][i] = -999;

            tblInfi[1][i] = -999;
            tblTode[1][i] = -999;

        }

    }

    qDebug()<< "Anzahl Einträge (n) = " << n ;

    return n;
}


//Liest in der Datenbank dank der Methode gibInfiziierte und gibTode die Daten für das vom User ausgewählte
//Datum für ein Land "geoID". Speichert sie im Attribut Infi und Tode der Klasse Laender
void Laender::FillLines (QDate uiDatum, QString geoID)
{
    QString Monat = QString::number(uiDatum.month()); //Der Monat wird aus dem gelesenen Datum auf dem UI gewonnen
        if (Monat.size()==1)
       {
            Monat.insert(0, "0");      //Aus Monat im Format "m" wird Monat im Format "mm" ("06" statt "6")
       }

    QString Tag = QString::number(uiDatum.day()); //Der Tag wird aus dem gelesenen Datum auf dem UI gewonnen
        if (Tag.size()==1)
        {
            Tag.insert(0, "0"); //Aus Tag im Format "d" wird Tag im Format "dd" ("1" statt "01")
        }

    QString Datum = DbLandDaten.gibDatum(Tag, Monat); //Die Methode gibDatum, gib das
                                                        // Datum in dem von der Datenbank benutzten Format

    Infi = QString::number(DbLandDaten.gibInfiierte(Datum, geoID)); //Es werden Daten aus der Datenbank gewonnen
    Tode = QString::number(DbLandDaten.gibTode(Datum, geoID));//Es werden Daten aus der Datenbank gewonnen

}
