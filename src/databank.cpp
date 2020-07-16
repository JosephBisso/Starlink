#include "databank.h"

databank::databank(QObject *parent) : QObject(parent)
{

}

//Gibt den absoluten Pfad 'PfadFilfe' für eine Datei 'File' im Ordner "dir"
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
void databank::jsDbShort()
{
    QJsonArray reArrayShort;

    QFile file (PfadGeber("lib", "covid13072020.json" ));

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

            QJsonValue jsDate = recordsObject["dateRep"];
            QJsonValue jsMonth = recordsObject["month"];
            QJsonValue jsYear = recordsObject["year"];
            QJsonValue jsDay = recordsObject["day"];
            QJsonValue jsCases = recordsObject["cases"];
            QJsonValue jsDeaths = recordsObject["deaths"];
            QJsonValue jsCountrie = recordsObject["countriesAndTerritories"];
            QJsonValue jsGeoId = recordsObject["geoId"];
            QJsonValue jsA = recordsObject["countryterritoryCode"];
            QJsonValue jsB = recordsObject["popData2019"];
            QJsonValue jsC = recordsObject["Cumulative_number_for_14_days_of_COVID-19_cases_per_100000"];

            if (Kontinent == "Europe" )
            {
                reArrayShort.append(recordsArray[i]); //Nur Länder aus der EU werden gespeichert.
            }


        }


        QJsonObject reObjectShort;
        reObjectShort["records"] = reArrayShort;

        QJsonDocument jsDbShort(reObjectShort);

        QFile file2(PfadGeber("src", "covidShort.json" ));
        file2.open(QIODevice::WriteOnly);
        file2.write(jsDbShort.toJson());
        file2.close();



    }


}
//Verbindet die JSON Datenbank und gint ihn zurück
QJsonDocument databank::jsDbConnect()
{
    QFile file (PfadGeber("src", "covidShort.json"));

    QJsonDocument jsonDoc;

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        jsonDoc = QJsonDocument::fromJson(file.readAll());
        file.close();

        return jsonDoc;
    }

    return jsonDoc;
}

//Setzt und Gibt Anzahl von Infizierten am "Datum" für ein Land mit Kennzeichnung "geoID". Gib "-999", wenn etwas
//schief gelaufen ist.
int  databank::gibInfiierte(QString Datum, QString geoID)
{
    QFile file (PfadGeber("src", "covidShort.json"));

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

//Setzt und gibt Gesamztanzahl von Infizierten im "Monat" für ein Land mit Kennzeichnung "geoID".
//Gib "-999", wenn etwas schief gelaufen ist.
int  databank::gibGesamtInfizierte (QString Monat, QString geoID)
{
    databank::Gesamt_Infi = 0;

    QFile file (PfadGeber("src", "covidShort.json"));

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

//Setzt und Gibt Anzahl von Toden am "Datum" für ein Land mit Kennzeichnung "geoID". Gib "-999", wenn etwas
//schief gelaufen ist.
int  databank::gibTode(QString Datum, QString geoID)
{

    QFile file (PfadGeber("src", "covidShort.json"));

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


//Setzt und Gibt Gesamztanzahl von Toden im "Monat" für ein Land mit Kennzeichnung "geoID". Gib "-999", wenn etwas
//schief gelaufen ist.
int  databank::gibGesamtTode (QString Monat, QString geoID)
{
    databank::Gesamt_Tode = 0;

    QFile file (PfadGeber("src", "covidShort.json"));

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
QString databank::gibDatum(QString Tag, QString Monat)
{
    QFile file (PfadGeber("src", "covidShort.json"));

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
    gibDatum("01", Monat);

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

//Setzt und Gibt den englische Name aus Landkennzeichung "geoID". Auf Englisch weil
//die Namen in der JSON Datei auf Englisch geschireben sind.
QString databank::gibLand(QString geoID)
{
    QFile file (PfadGeber("src", "covidShort.json"));

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
