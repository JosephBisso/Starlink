#include "databank.h"

#include <QMessageBox>

databank::databank(QObject *parent) : QObject(parent)
{

}

//Gibt den absoluten Pfad 'PfadFilfe' für eine Datei 'File' im Ordner "dir"

/*Der Pfad der Datei "main.cpp", die sich beim Ausführen des Programms normalerweise im
 * einem Build Ordner befindet wird als QString gewonnen, die letzten Zeichen des Pfades
 * die normalerweise zu dem Build Ordner führen wird gelöscht und durch
 * den gewünschten Ordner "dir", \\, und die gewünschte Datein "file" ersetzt
 */
QString databank::PfadGeber(QString dir, QString file)
{
    QFileInfo ref("main.cpp");
    QString refString = ref.absoluteFilePath();
    int y = refString.lastIndexOf("build");
    int z = refString.lastIndexOf(".cpp");
    QString refLast = refString.remove(y, z-y+5);
    QString PfadFile = refLast + dir + "\\" + file;

    return PfadFile;
}

//Reduziert Daten in Datenbank auf die nötigen (EU-Länder)

/*Das Attribut (bool) done, zum Sicherstellen, ob der Vorgang erfolgreich war oder nicht .
 * Die Daten covidRaw.json mit den Covid Zahlen wird geöffnet un in einem QJsonDocument gespeichert
 *Die Zeilen zum Lesen von Json Datei wurden aus der Vorlesung geguckt und angepast.
 * Die JSON Datei wird durchgelesen und alle Objekte, die als Kontinent Europa
 * haben (in der JsonDatei: "continentExp" : "Europe") werden in einem neuen
 * QJsonArray hinzugefügt. Die Zeilen zum Schreiben einer Json Datei kommen wieder
 * aus der Vorlesung. Wenn alles wie geplant funktionniert wird done = true gesetzt.
 */
void databank::jsDbShort()
{
    this->done = false;

    QJsonArray reArrayShort;

    QFile file (":/covidRaw.json");

    QJsonDocument jsonDoc;

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll());
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

        QFile file2(PfadGeber("lib", "covidShort.json" ));

        if(file2.open(QIODevice::WriteOnly))
        {
           file2.write(jsDbShort.toJson());
           file2.close();

           this->done = true;
        }



    }



}
//Verbindet die JSON Datenbank und gint ihn zurück

/*Die zuvor geschriebene Json Datei "covidShort.json" mit nur Europaländer drin wird geöffnet
 * und in einem QJsonDocument gespeichert
 */
QJsonDocument databank::jsDbConnect()
{
    QFile file (PfadGeber("lib", "covidShort.json"));

    QJsonDocument jsonDoc;

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        jsonDoc = QJsonDocument::fromJson(file.readAll());
        file.close();

        return jsonDoc;
    }

    return jsonDoc;
}


//Liest die Anzahl von Infizierten am "Datum" für ein Land mit Kennzeichnung "geoID"
// aus der Json Datein "covidShort.json" (in der Json Datei:"dateRep", "geoId", "Cases"), gibt
//sie uns zurück und speichert sie im Attribut "Infiziierte" der Klasse databank. Gib "-999",
//wenn die Datei nicht gelesen werden konnte
int  databank::gibInfiierte(QString Datum, QString geoID)
{
    QFile file (PfadGeber("lib", "covidShort.json"));

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

       if (jsGeoId == geoID  && jsDate == Datum)
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
int  databank::gibGesamtInfizierte (QString Monat, QString geoID)
{
    databank::Gesamt_Infi = 0;

    QFile file (PfadGeber("lib", "covidShort.json"));

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
       QJsonValue jsGeoId = recordsObject["geoId"];

       if (jsGeoId == geoID  && jsMonth == Monat)
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

    QFile file (PfadGeber("lib", "covidShort.json"));

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

        if (jsGeoId == geoID  && jsDate == Datum)
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
int  databank::gibGesamtTode (QString Monat, QString geoID)
{
    databank::Gesamt_Tode = 0;

    QFile file (PfadGeber("lib", "covidShort.json"));

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
       QJsonValue jsGeoId = recordsObject["geoId"];

       if (jsGeoId == geoID  && jsMonth == Monat)
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
QString databank::gibDatum(QString Tag, QString Monat)
{
    QFile file (PfadGeber("lib", "covidShort.json"));

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
        QJsonValue jsDay = recordsObject["day"];

        if (jsDay == Tag  && jsMonth == Monat)
        {
        databank::Datum = jsDate.toString();
        databank::Tag = jsDay.toString();
        databank::Monat = jsMonth.toString();

        return databank::Datum;

        }
    }
}

    return "-999";
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
    QFile file (PfadGeber("lib", "covidShort.json"));

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

        QJsonValue jsCountrie = recordsObject["countriesAndTerritories"];
        QJsonValue jsGeoId = recordsObject["geoId"];

        if (jsGeoId == geoID)
        {

        databank::Land = jsCountrie.toString();
        databank::geoID = jsGeoId.toString();

        return databank::Land;

        }
    }

}
    return "-999";
}
