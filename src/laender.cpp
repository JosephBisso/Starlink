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

//Rechnet und speichert Gesamtinfiziierte für alle Monate in 2 Feldern, Attributen der Klasse Laender
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

//Liest in der Datenbank dank der Methoden der Klasse Datenbank 'gibInfiziierte' und 'gibTode' die Daten eines Landes
// mit geografischer Kennung "geoID" für alle Tage eines Monats aus dem Datum "uiDatum" oder vom 1. bis zum vom User
//ausgewählten Datum "uiDatum", wenn der Monat noch am laufen ist. Abhängig davon, ob  "linear" auf true oder falsch
//gesetzt wurde, werden die Daten normal (linear) oder logarithmisch gespeichert (ln). Die Anzahl von Tagen, für die
//Daten gespeichert wurden wird zurückgegeben.
int Laender::FillTab(QDate uiDatum, bool linear, QString geoID)
{
    int n = 0;
    qreal k; //qreal ist der für die Graphen unterstützten Typ.

    int gibNicht = 0;

    qDebug()<< "geoID = " << geoID << " und uiDatum = " << uiDatum ;

    QString pruefTag;

    QString Monat = QString::number(uiDatum.month());
        if (Monat.size()==1)
       {
            Monat.insert(0, "0");      //Aus Monat im Format "m" wird Monat im Format "mm" ("06" statt "6")
       }

        qDebug()<< "Monat = " << Monat ;

    for (int i =0; i<uiDatum.daysInMonth(); i++) //Es wird jetzt gezählt, für wie viele Tage, es keine Einträge in der Datenbank gibt
    {
        pruefTag = QString::number(uiDatum.daysInMonth()-i);

        if (pruefTag.size()==1){pruefTag.insert(0, "0");}

        if (DbLandDaten.gibInfiierte(DbLandDaten.gibDatum(pruefTag, Monat), geoID) == -999) //prüft ob es Einträge in der Datenbank für den
                                                                                           //Prueftag gibt. (die Methode gibInfizierte gibt -999
                                                                                          // zurück, wenn dies nicht der Fall ist
        {
           gibNicht += 1;
        }

    }

    qDebug() << "Es fehlen " <<gibNicht<< "Tage";

    for (int i =0; i<(uiDatum.daysInMonth()-gibNicht); i++) //Es werden jetzt Daten für die Anzahl an in der Datenbank vorhanden Tagen
                                                           //des Monats  des ausgewählten Datum aus der Datenbank gesammelt und
                                                          // in Attributen der Klasser Laender gespeichert
    {
        k = 1 + i; // Weil Monate nicht mit dem 0.  anfangen


        if (k>0) // weil für k<=0, kann kein Datum gewonnen werden.
        {
            tblInfi[0][i] = k;
            tblTode[0][i] = k;

            qDebug()<< "tblInfi[0]["<<i<<"]  (k) = " << k ;

            QString Tag = QString::number(k);
            if (Tag.size()==1){Tag.insert(0, "0");}

            qDebug()<< "Tag = " << Tag ;

            QString tblDatum = DbLandDaten.gibDatum(Tag, Monat); //Die Methode gibDatum gehört der Klasse databank und gibt
                                                                // aus einem Tag und Monat das Datum zurück, falls dieses Datum
                                                               // in der Datenbank vorhanden ist.

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

        else
        {
            qDebug()<< "k ist kleiner gleich null für i = " << i;

            tblInfi[0][i] = -999; //  füllt die Matrix mit ungültige Daten, zur Signaliesirung des Problems
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
    QString Monat = QString::number(uiDatum.month());
        if (Monat.size()==1)
       {
            Monat.insert(0, "0");      //Aus Monat im Format "m" wird Monat im Format "mm" ("06" statt "6")
       }

    QString Tag = QString::number(uiDatum.day());
        if (Tag.size()==1)
        {
            Tag.insert(0, "0");
        }

    QString Datum = DbLandDaten.gibDatum(Tag, Monat); //Die Methode gibDatum, gib das
                                                     // Datum in dem von der Datenbank benutzten Format

    Infi = QString::number(DbLandDaten.gibInfiierte(Datum, geoID)); //Es werden Daten aus der Datenbank gewonnen für das Datum "Datum"
                                                                    //und Land identifiziert mit "geoID"
    Tode = QString::number(DbLandDaten.gibTode(Datum, geoID));
}
