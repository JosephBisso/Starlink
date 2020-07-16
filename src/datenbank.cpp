#include "datenbank.h"
#include "ui_datenbank.h"
#include "dbvorschau.h"

Datenbank::Datenbank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Datenbank)
{
    ui->setupUi(this);
}

Datenbank::~Datenbank()
{
    delete ui;
}

//Gibt den absoluten Pfad 'PfadFilfe' für eine Datei 'File' im Ordner "dir"
QString Datenbank::PfadGeber(QString dir, QString file)
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
void Datenbank::jsDbShort()
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
QJsonDocument Datenbank::jsDbConnect()
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
int  Datenbank::gibInfiierte(QString Datum, QString geoID)
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

       Datenbank::Infiziierte = jsCases.toInt();

       return Datenbank::Infiziierte;

       }
   }

    }

   return -999;
}

//Setzt und gibt Gesamztanzahl von Infizierten im "Monat" für ein Land mit Kennzeichnung "geoID".
//Gib "-999", wenn etwas schief gelaufen ist.
int  Datenbank::gibGesamtInfizierte (QString Monat, QString geoID)
{
    Datenbank::Gesamt_Infi = 0;

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

       Datenbank::Gesamt_Infi += jsCases.toInt();

       }
   }

   return Datenbank::Gesamt_Infi;

    }

   return -999;
}

//Setzt und Gibt Anzahl von Toden am "Datum" für ein Land mit Kennzeichnung "geoID". Gib "-999", wenn etwas
//schief gelaufen ist.
int  Datenbank::gibTode(QString Datum, QString geoID)
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

        Datenbank::Tode = jsDeaths.toInt();

        return Datenbank::Tode;

        }
    }

}
    return -999;
}


//Setzt und Gibt Gesamztanzahl von Toden im "Monat" für ein Land mit Kennzeichnung "geoID". Gib "-999", wenn etwas
//schief gelaufen ist.
int  Datenbank::gibGesamtTode (QString Monat, QString geoID)
{
    Datenbank::Gesamt_Tode = 0;

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

       Datenbank::Gesamt_Tode += jsDeath.toInt();

       }
   }

   return Datenbank::Gesamt_Tode;

    }

   return -999;
}

//Setzt und Gibt Datum aus "Tag" und "Monat". Jahr meisteins 2020. Für 2019, wird das auch
//korrekt angegeben, weil Corona-Daten für keine Monate schon 2 Mal gesammelt wurden
QString Datenbank::gibDatum(QString Tag, QString Monat)
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
        Datenbank::Datum = jsDate.toString();
        Datenbank::Tag = jsDay.toString();
        Datenbank::Monat = jsMonth.toString();

        return Datenbank::Datum;

        }
    }
}

    return "-999";
}

//Setzt und Gibt den englische Name aus Landkennzeichung "geoID". Auf Englisch weil
//die Namen in der JSON Datei auf Englisch geschireben sind.
QString Datenbank::gibLand(QString geoID)
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

        Datenbank::Land = jsCountrie.toString();
        Datenbank::geoID = jsGeoId.toString();

        return Datenbank::Land;

        }
    }

}
    return "-999";
}

//eine Verbindung zur Datenbank "covidShort.json" wird aufgebaut. Man bekommt danach eine Benachrichtigung
void Datenbank::on_dbConnect_clicked()
{
    jsDbConnect();

    if (jsDbConnect().isEmpty())
    {
        QMessageBox::information(this, "Verbindung", "Verbindung zur Datenbank könnte nicht aufgebaut werden."
                                                     "Versuchen Sie die Datenbank erstmal zu aktualiesiren");

    }

    else {

        QMessageBox::information(this, "Verdindung","Verbindung zur Datenbank gelungen"  );
    }
}

//einen Auszug aus der Datenbank wird tabellarisch dargestellt
void Datenbank::on_dbShow_clicked()
{
    dbVorschau* Vorschau = new dbVorschau(this);
    Vorschau->exec();
}


void Datenbank::on_dbUpdate_clicked()
{
    jsDbShort();

    QMessageBox::information(this, "Aktualisierung", "Daten erfolgreich aktualisiert");
}


void Datenbank::on_dbOK_accepted()
{
    this->close();
}
