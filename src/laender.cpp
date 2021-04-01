#include "laender.h"
#include "databank.h"

Laender::Laender(QObject *parent) : QObject(parent)
{

}

void Laender::setGeoID(QString geoID) {
    this->geoID = geoID;
}

 // Für ein Tag "dd", und Monat "mm" und für ein Land mit geoID "geoID"
//wird erstmal die geoID gespeichert und dann die Daten aus der Datenbank "covidShort.Json"
//dank derMethonde aus der Klasse databank  gelesen und  im Attribut "DbLandDaten" vom Typ databank
// der Klasse Laender gespeichert.
void Laender::gibLandDaten(QString Tag, QString Monat)
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
void Laender::InfiTodeMonat()
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
int Laender::FillTab(QDate uiDatum, bool linear)
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
void Laender::FillLines (QDate uiDatum)
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

//Diese Methode ist dafür da, den 7 Tage Durchschnitt der Infzierten zu berechenen. Dabei wird der aktuelle ausgewählte Tag berücksichtigt und die 6 Tage zuvor.
QString Laender::Fill7TagDurchschnitt (QDate uiDatum)
{
    QDate QDDatum[7];

    QString Monat[7],
              Tag[7],
            Datum[7];

    double InfiSeven = 0.0, //Definieren einer Gleitkommazahl
           InfiDatum = 0.0;

    for (int i=0; i<7; i++) //7 Tage werden benötigt für den 7 Tage Durchschnitt
    {
        QDDatum[i] = uiDatum.addDays(-i);  //benutzt den aktuellen Tag und geht 6 weitere Tage zurück (-i)

        qDebug()<< QDDatum[i];

        Monat[i] = QString::number(QDDatum[i].month());
            if (Monat[i].size()==1)
           {
                Monat[i].insert(0, "0");      //Aus Monat im Format "m" wird Monat im Format "mm" ("06" statt "6")
           }


        Tag[i] = QString::number(QDDatum[i].day());
            if (Tag[i].size()==1)
            {
                Tag[i].insert(0, "0");
            }

        Datum[i] = DbLandDaten.gibDatum(Tag[i], Monat[i]); //Die Methode gibDatum, gib das
                                                          // Datum in dem von der Datenbank benutzten Format
        qDebug()<< " für Datum = " << Datum[i] ;

        InfiDatum = DbLandDaten.gibInfiierte(Datum[i], geoID);
        qDebug()<< "InfiDatum (i="<<i<<") ="<< InfiDatum;

        if (InfiDatum == -999)
        {
            return "";
        }

        InfiSeven += InfiDatum; //Es werden Daten aus der Datenbank gewonnen für das Datum "Datum"
                                                                        //und Land identifiziert mit "geoID"
        qDebug()<< "InfiSeven für i = "<<i<<" ="<< InfiSeven; //Berechnet die Gesamtanzahl der Infizierten der 7 Tage
    }

   qDebug()<< "Durchschitt InfiSeven = "<<InfiSeven/7; //Berechnet den Durschnitt der Infizierten indem die Gesamtzahl durch 7 geteilt wird

   return QString::number(InfiSeven/7); //gibt die Durchschnittlichen Infizierten pro Tag zurück
}

QString Laender::InfiproEinwohner (int Einwohnerzahl)
{
    double InfiproEinwohner = 0.0; //Definieren einer Gleitkommazahl
    Laender Land; //Klasse Laender für das Land ausgeben

    qDebug()<<"geoID"<<geoID;

    Laender::InfiTodeMonat();//Ausgabe der Infizierten der Länder durch geoID (Bsp. für Deutschland ist die geoID "DE")

    for (int i=0; i<12; i++)//Die Gleitkommazahl InfiproEinwohner wird mit den bekannten Infizierten aus allen Monaten gleichgesetzt aus dem entsprechendem Land
    {
        InfiproEinwohner += Land.infMonat[i];

        qDebug()<< "InfiproEinwohner für i ="<<i<<" gleich "<<InfiproEinwohner;
    }

    InfiproEinwohner/= Einwohnerzahl; //Die Gleitkommazahl InfiproEinwohner wird erst geteilt durch die Einwohnerzahl des jeweiligen Landes gerechnet und mit 100.000 multipliziert

    InfiproEinwohner*=100000;

    qDebug()<<"InfiproEinwohner Last"<< InfiproEinwohner;

    return QString::number(InfiproEinwohner);//Gibt das Ergebnis der Infizierten pro 100.000 Einwohner als QString aus, damit es in einem lineEdit angezeigt werden kann

}
