#include "databank.h"

#include <QMessageBox>
#include <Qt>

#include "downloader.h"
#include "laender.h"

databank::databank(QObject *parent) : QObject(parent)
{

}


//Reduziert Daten in Datenbank auf die nötigen (EU-Länder)

/*Das Attribut (bool) done, zum Sicherstellen, ob der Vorgang erfolgreich war oder nicht .
 * Die Daten covidRaw.json mit den Covid Zahlen wird geöffnet un in einem QJsonDocument gespeichert
 *Die Zeilen zum Lesen von Json Datei wurden aus der Vorlesung geguckt und angepast.
 * Die JSON Datei wird durchgelesen und alle Objekte, die als Kontinent Europa
 * haben (in der JsonDatei: "continentExp" : "Europe") werden in einem neuen
 * QJsonArray hinzugefügt. Die Zeilen zum Schreiben einer Json Datei kommen wieder
 * aus der Vorlesung. Da die eben geschriebene Datei nur ein Auszug aus der Hauptdatei ist,
 * wird sie nur als ZwischenSpeicher gespeichert (im Build Ordner). Wenn alles wie geplant funktionniert wird done = true zurückgegeben.
 */
void databank::jsDbShort()
{
    done = true;

    QJsonArray reArrayShort;

    QJsonDocument jsonDoc;

    QFile file ("covidRaw.json");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
       file.setFileName(":/lib/covidRaw.json"); done = false;
    } else {
        file.close();
    }


    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        jsonDoc = QJsonDocument::fromJson(file.readAll());
        file.close();


        QJsonObject jsonObject = jsonDoc.object();
        QJsonArray recordsArray = jsonDoc["records"].toArray();

        for (int i=0; i < recordsArray.size(); i++)
        {
            QJsonObject recordsObject = recordsArray[i].toObject();
            QJsonValue jsKontinent = recordsObject["continentExp"];
            QString Kontinent = jsKontinent.toString();

            if (Kontinent == "Europe" )
            {
                reArrayShort.append(recordsArray[i]); //Nur Länder aus der EU werden gespeichert.
            }


        }


        QJsonObject reObjectShort;
        reObjectShort["records"] = reArrayShort;

        QJsonDocument jsDbShort(reObjectShort);

        QFile file2("covidShort.json");

        if(file2.open(QIODevice::WriteOnly))
        {
           file2.write(jsDbShort.toJson());
           file2.close();

        }



    }

    file.setFileName("covidRaw_2021.json");
    QJsonArray reArrayShort2;

    //if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){ file.setFileName(":/lib/covidRaw.json"); done = false;}
    // file.close();

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        jsonDoc = QJsonDocument::fromJson(file.readAll());
        file.close();


        QJsonArray jsonArray = jsonDoc.array();

        for (int i=0; i < jsonArray.size(); i++)
        {
            QJsonObject recordsObject = jsonArray[i].toObject();
            QJsonValue jsKontinent = recordsObject["continent"];
            QString Kontinent = jsKontinent.toString();

            if (Kontinent == "Europe" )
            {
                reArrayShort2.append(jsonArray[i]); //Nur Länder aus der EU werden gespeichert.
            }


        }


        QJsonObject reObjectShort2;
        reObjectShort2["records"] = reArrayShort2;

        QJsonDocument jsDbShort2(reObjectShort2);

        QFile file2("covidShort_2021.json");

        if(file2.open(QIODevice::WriteOnly))
        {
           file2.write(jsDbShort2.toJson());
           file2.close();

        }



    }



}
//Verbindet die JSON Datenbank und gint ihn zurück

/*Die zuvor geschriebene Json Datei "covidShort.json" mit nur Europaländer drin wird geöffnet
 * und in einem QJsonDocument gespeichert
 */
QJsonDocument* databank::jsDbConnect()
{
    QFile file ("covidRaw.json");

    QJsonDocument jsonDoc[2];

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        jsonDoc[0] = QJsonDocument::fromJson(file.readAll());
        file.close();
    }

    file.setFileName("covidRaw_2021.json");

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        jsonDoc[1] = QJsonDocument::fromJson(file.readAll());
        file.close();
    }

    QJsonDocument* jsonRETURN = jsonDoc;

    return jsonRETURN;
}


//Liest die Anzahl von Infizierten am "Datum" für ein Land mit Kennzeichnung "geoID"
// aus der Json Datein "covidShort.json" (in der Json Datei:"dateRep", "geoId", "Cases"), gibt
//sie uns zurück und speichert sie im Attribut "Infiziierte" der Klasse databank. Gib "-999",
//wenn die Datei nicht gelesen werden konnte
int  databank::gibInfiierte(QString Datum, QString geoID)
{
    if (Datum.contains('-')) {
        QFile file ("covidShort_2021.json");

        Laender* laender = new Laender;
        QJsonDocument jsonDoc;

        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {

            jsonDoc = QJsonDocument::fromJson(file.readAll());
            file.close();

            QJsonObject jsonObject =jsonDoc.object();
            QJsonArray recordsArray = jsonDoc["records"].toArray();


            for (int i=0; i < recordsArray.size(); i++)
            {
                QJsonObject recordsObject = recordsArray[i].toObject();
                QJsonValue jsIndicator = recordsObject["indicator"];
                QJsonValue jsYearWeek = recordsObject["year_week"];
                QJsonValue jsCountry_code = recordsObject["country_code"];
                QJsonValue jsWeekly_count = recordsObject["weekly_count"];

                if (jsCountry_code.toString() == laender->convertToCountryCode(geoID)  && jsIndicator.toString() == "cases" && jsYearWeek.toString() ==  Datum)
                {

                    databank::Infiziierte = jsWeekly_count.toInt();

                    return databank::Infiziierte;

                }
            }

        }

    }

    QFile file ("covidShort.json");

    QJsonDocument jsonDoc;

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        jsonDoc = QJsonDocument::fromJson(file.readAll());
        file.close();

        QJsonObject jsonObject =jsonDoc.object();
        QJsonArray recordsArray = jsonDoc["records"].toArray();


   for (int i=0; i < recordsArray.size(); i++)
   {
       QJsonObject recordsObject = recordsArray[i].toObject();

       QJsonValue jsCases = recordsObject["cases"];
       QJsonValue jsDate = recordsObject["dateRep"];
       QJsonValue jsGeoId = recordsObject["geoId"];

       if (jsGeoId.toString() == geoID  && jsDate.toString() ==  Datum)
       {

       databank::Infiziierte = jsCases.toInt();

       return databank::Infiziierte;

       }
   }

    }

   return -999;
}

//Liest die Anzahl von Infizierten in einem Monat im Format "mm" für ein Land mit Kennzeichnung "geoID"
// aus der Json Datein "covidShort.json" und additionniert sie (in der Json Datei:"month", "geoId", "Cases")
//Das Ergebnis wird uns zurückgeben und im Attribut "Gesamt_Infi" der Klasse databank gespeichert. Gib "-999",
//wenn die Datei nicht gelesen werden konnte
int  databank::gibGesamtInfizierte (QString Monat, QString Jahr, QString geoID)
{
    if ((Jahr.toInt() != 2020) || (Jahr.toInt() == 2020 && Monat.toInt() == 12)) {

        databank::Gesamt_Infi = 0;

        QFile file ("covidShort_2021.json");
        Laender* laender = new Laender;

        QJsonDocument jsonDoc;

        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {

            jsonDoc = QJsonDocument::fromJson(file.readAll());
            file.close();

            QJsonObject jsonObject =jsonDoc.object();
            QJsonArray recordsArray = jsonDoc["records"].toArray();


            for (int i=0; i < recordsArray.size(); i++)
            {
                QJsonObject recordsObject = recordsArray[i].toObject();

                QJsonValue jsWeekly_count = recordsObject["weekly_count"];
                QJsonValue jsYear_week = recordsObject["year_week"];
                QJsonValue jsCountry_code = recordsObject["country_code"];
                QJsonValue jsIndicator = recordsObject["indicator"];

                if (jsCountry_code.toString() == laender->convertToCountryCode(geoID) && jsIndicator.toString() ==  "cases")
                {
                    int anzahlWochen = Monat.toInt() * (52 / 12);

                    for (int i = 0; i < 4; i++) {
                        if (jsYear_week == (Jahr + "-" + QString::number(anzahlWochen - i))) {
                            databank::Gesamt_Infi += jsWeekly_count.toInt();
                        }
                    }

                }
           }

            return databank::Gesamt_Infi;

        }
    }

    databank::Gesamt_Infi = 0;

    QFile file ("covidShort.json");

    QJsonDocument jsonDoc;

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        jsonDoc = QJsonDocument::fromJson(file.readAll());
        file.close();

        QJsonObject jsonObject =jsonDoc.object();
        QJsonArray recordsArray = jsonDoc["records"].toArray();


   for (int i=0; i < recordsArray.size(); i++)
   {
       QJsonObject recordsObject = recordsArray[i].toObject();

       QJsonValue jsCases = recordsObject["cases"];
       QJsonValue jsMonth = recordsObject["month"];
       QJsonValue jsYear = recordsObject["year"];
       QJsonValue jsGeoId = recordsObject["geoId"];

       if (jsGeoId.toString() == geoID  && jsMonth.toString() == Monat && jsYear.toString() == Jahr)
       {

       databank::Gesamt_Infi += jsCases.toInt();

       }
   }

   return databank::Gesamt_Infi;

    }

   return -999;
}

//Analog zur obigen Methode gibIfiziierte
//Setzt und Gibt Anzahl von Toden am "Datum" für ein Land mit Kennzeichnung "geoID". Gib "-999", wenn etwas
//schief gelaufen ist.
int  databank::gibTode(QString Datum, QString geoID)
{
    if (Datum.contains('-')) {
        QFile file ("covidShort_2021.json");

        Laender* laender = new Laender;
        QJsonDocument jsonDoc;

        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {

            jsonDoc = QJsonDocument::fromJson(file.readAll());
            file.close();

            QJsonObject jsonObject =jsonDoc.object();
            QJsonArray recordsArray = jsonDoc["records"].toArray();


            for (int i=0; i < recordsArray.size(); i++)
            {
                QJsonObject recordsObject = recordsArray[i].toObject();
                QJsonValue jsIndicator = recordsObject["indicator"];
                QJsonValue jsYearWeek = recordsObject["year_week"];
                QJsonValue jsCountry_code = recordsObject["country_code"];
                QJsonValue jsWeekly_count = recordsObject["weekly_count"];

                if (jsCountry_code.toString() == laender->convertToCountryCode(geoID)  && jsIndicator.toString() ==  "deaths" && jsYearWeek.toString() ==  Datum)
                {

                    databank::Tode = jsWeekly_count.toInt();

                    return databank::Tode;

                }
            }

        }

    }

    QFile file ("covidShort.json");

    QJsonDocument jsonDoc;

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        jsonDoc = QJsonDocument::fromJson(file.readAll());
        file.close();

        QJsonObject jsonObject =jsonDoc.object();
        QJsonArray recordsArray = jsonDoc["records"].toArray();

    for (int i=0; i < recordsArray.size(); i++)
    {
        QJsonObject recordsObject = recordsArray[i].toObject();

        QJsonValue jsDeaths = recordsObject["deaths"];
        QJsonValue jsDate = recordsObject["dateRep"];
        QJsonValue jsGeoId = recordsObject["geoId"];

        if (jsGeoId.toString() == geoID  && jsDate.toString() ==  Datum)
        {

        databank::Tode = jsDeaths.toInt();

        return databank::Tode;

        }
    }

}
    return -999;
}


//Analog zur obigen Methode gibGesamtInfiziierte
//Setzt und Gibt Gesamztanzahl von Toden im "Monat" für ein Land mit Kennzeichnung "geoID". Gib "-999", wenn etwas
//schief gelaufen ist.
int  databank::gibGesamtTode (QString Monat, QString Jahr, QString geoID)
{
    if ((Jahr.toInt() != 2020) || (Jahr.toInt() == 2020 && Monat.toInt() == 12)) {

        databank::Gesamt_Tode = 0;

        QFile file ("covidShort_2021.json");
        Laender* laender = new Laender;

        QJsonDocument jsonDoc;

        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {

            jsonDoc = QJsonDocument::fromJson(file.readAll());
            file.close();

            QJsonObject jsonObject =jsonDoc.object();
            QJsonArray recordsArray = jsonDoc["records"].toArray();


            for (int i=0; i < recordsArray.size(); i++)
            {
                QJsonObject recordsObject = recordsArray[i].toObject();

                QJsonValue jsWeekly_count = recordsObject["weekly_count"];
                QJsonValue jsYear_week = recordsObject["year_week"];
                QJsonValue jsCountry_code = recordsObject["country_code"];
                QJsonValue jsIndicator = recordsObject["indicator"];

                if (jsCountry_code.toString() == laender->convertToCountryCode(geoID) && jsIndicator.toString() ==  "deaths")
                {
                    int anzahlWochen = Monat.toInt() * (52 / 12);
                    QString AnzahlWochen;

                    for (int i = 0; i < 4; i++) {
                        if (anzahlWochen < 10) {

                        }
                        if (anzahlWochen >= 4 && jsYear_week == (Jahr + "-" + QString::number(anzahlWochen - i))) {
                            databank::Gesamt_Tode += jsWeekly_count.toInt();
                        } else if (jsYear_week == (Jahr + "-" + QString::number(anzahlWochen - i))) {

                        }
                    }

                }
           }

            return databank::Gesamt_Tode;

        }
    }

    databank::Gesamt_Tode = 0;

    QFile file ("covidShort.json");

    QJsonDocument jsonDoc;

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        jsonDoc = QJsonDocument::fromJson(file.readAll());
        file.close();

        QJsonObject jsonObject =jsonDoc.object();
        QJsonArray recordsArray = jsonDoc["records"].toArray();


   for (int i=0; i < recordsArray.size(); i++)
   {
       QJsonObject recordsObject = recordsArray[i].toObject();

       QJsonValue jsDeath = recordsObject["deaths"];
       QJsonValue jsMonth = recordsObject["month"];
       QJsonValue jsYear = recordsObject["year"];
       QJsonValue jsGeoId = recordsObject["geoId"];

       if (jsGeoId.toString() == geoID  && jsMonth.toString() == Monat && jsYear.toString() == Jahr)
       {

       databank::Gesamt_Tode += jsDeath.toInt();

       }
   }

   return databank::Gesamt_Tode;

    }

   return -999;
}

//Setzt und Gibt Datum aus "Tag" und "Monat". Jahr meisteins 2020. Für 2019, wird das auch
//korrekt angegeben, weil Corona-Daten für keine Monate schon 2 Mal gesammelt wurden

/*Liest das "Datum" für ein Tag im Format "dd" und Monat "mm "aus der Json Datein
 * "covidShort.json" (in der Json Datei:"dateRep", "day", "month"), gibt
 *es uns zurück und speichert sie im Attribut "Datum" der Klasse databank. Gib "-999",
 *wenn die Datei nicht gelesen werden konnte
 */
QString databank::gibDatum(QString Tag, QString Monat, QString Jahr)
{   
    QDate datum = QDate(Jahr.toInt(), Monat.toInt(), Tag.toInt());

    if (Jahr != "2020") {
        QDate erster_Januar_vom_Jahr = QDate(Jahr.toInt(), 1, 1);

        int diffTage = 0;
        while(!(datum == erster_Januar_vom_Jahr)) {
            datum = datum.addDays(-1);
            diffTage++;
        }

        int Wochenzahl = diffTage/7;
        QString StringWochenzahl = QString::number(Wochenzahl);

        if (Wochenzahl < 1) {

            return Jahr + "-" + "01";
        }

        if (QString::number(Wochenzahl).length() == 1) {
            StringWochenzahl = "0" + QString::number(Wochenzahl);
        }

        return Jahr + "-" + StringWochenzahl;

    }

    if (datum > QDate(2020, 12, 14)) {
        QDate erster_Januar_2020 = QDate(2020, 1, 1);

        int diffTage = 0;
        while(!(datum == erster_Januar_2020)) {
            datum = datum.addDays(-1);
            diffTage++;
        }

        int Wochenzahl = diffTage/7;
        QString StringWochenzahl = QString::number(Wochenzahl);

        if (QString::number(Wochenzahl).length() == 1) {
            StringWochenzahl = "0" + QString::number(Wochenzahl);
        }

        return "2020-" + StringWochenzahl;

    }

    QFile file ("covidShort.json");

    QJsonDocument jsonDoc;

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        jsonDoc = QJsonDocument::fromJson(file.readAll());
        file.close();

        QJsonObject jsonObject =jsonDoc.object();
        QJsonArray recordsArray = jsonDoc["records"].toArray();

        for (int i=0; i <recordsArray.size(); i++)
        {
            QJsonObject recordsObject = recordsArray[i].toObject();

            QJsonValue jsDate = recordsObject["dateRep"];
            QJsonValue jsMonth = recordsObject["month"];
            QJsonValue jsYear = recordsObject["year"];
            QJsonValue jsDay = recordsObject["day"];

            if (jsDay.toString() == Tag  && jsMonth.toString() == Monat && jsYear.toString() == Jahr)
            {
                databank::Datum = jsDate.toString();
                databank::Tag = jsDay.toString();
                databank::Monat = jsMonth.toString();
                databank::Jahr = jsYear.toString();

                return databank::Datum;

            }
        }
    }

    return "-999";
}

//Gib das Datum der letzten Aktualierung

/* Liest aus dem Eintrag mit Index 0 (der letzte hinzugefügte Eintrag) der Array "records"
   das Datum (in der Json Datei:"dateRep")
*/
QString databank::gibUpdateDatum()
{
    QFile file ("covidRaw_2021.json");

    QJsonDocument jsonDoc;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){file.setFileName(":/lib/covidRaw.json");} /*Wenn die Datei nicht geöffnet werden kann
                                                                                                  wird stattdessen ein Backup File geöffnet
                                                                                                  */


     file.close();

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        jsonDoc = QJsonDocument::fromJson(file.readAll());
        file.close();

        QJsonArray recordsArray = jsonDoc.array();
        int max = 0;
        QStringList jahr_monat;
        for (int i = 0; i < recordsArray.size(); i++) {

            QJsonObject recordsObject = recordsArray[i].toObject();

            QJsonValue jsYear_week = recordsObject["year_week"];
            QJsonValue jsCountry = recordsObject["country"];
            QJsonValue jsIndicator = recordsObject["indicator"];

            if (jsCountry.toString() == "Afghanistan" && jsIndicator.toString() == "cases") {

                jahr_monat = (jsYear_week.toString()).split("-");

                if (jahr_monat[0].toInt() == QDate::currentDate().year() && jahr_monat[1].toInt() > max) {
                    max = jahr_monat[1].toInt();
                }
            } else if (jsCountry.toString() == "Afghanistan" && jsIndicator.toString() == "deaths") {
                break;
            }
        }

        QString AktuelleDatum = jahr_monat[0] + ", Kalenderwoche " + QString::number(max);
        return AktuelleDatum;


    }

    return "Error 'Pfad': Auf die Datenbank könnte nicht zugregriffen werden.";
}

//Gibt aus Monat im Format "mm" den Namen des Monats.
QString databank::gibMonat(QString Monat)
{
    QString nMonat;

    switch(Monat.toInt())
    {
    case(1):{nMonat = "Januar";break;}
    case(2):{nMonat = "Februar";break;}
    case(3):{nMonat = "März";break;}
    case(4):{nMonat = "April";break;}
    case(5):{nMonat = "Mai";break;}
    case(6):{nMonat = "Juni";break;}
    case(7):{nMonat = "Juli";break;}
    case(8):{nMonat = "August";break;}
    case(9):{nMonat = "September";break;}
    case(10):{nMonat = "Oktober";break;}
    case(11):{nMonat = "November";break;}
    case(12):{nMonat = "Dezember";break;}
    }

    return nMonat;
}

//Lies aus der Json Datein "covidShort.json" , speichert und Gibt den
//englischen Namen aus Landkennzeichung "geoID". Auf Englisch weil
//die Namen in der JSON Datei auf Englisch geschrieben sind.
QString databank::gibLand(QString geoID)
{
    QFile file ("covidShort_2021.json");
    Laender* laender = new Laender;

    QJsonDocument jsonDoc;

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        jsonDoc = QJsonDocument::fromJson(file.readAll());
        file.close();

        QJsonObject jsonObject =jsonDoc.object();
        QJsonArray recordsArray = jsonDoc["records"].toArray();

    for (int i=0; i < recordsArray.size(); i++)
    {
        QJsonObject recordsObject = recordsArray[i].toObject();

        QJsonValue jsCountrie = recordsObject["country"];
        QJsonValue jsCountry_code = recordsObject["country_code"];

        if (jsCountry_code.toString() == laender->convertToCountryCode(geoID))
        {

        databank::Land = jsCountrie.toString();
        this->geoID = geoID;

        return databank::Land;

        }
    }

}
    return "-999";
}
