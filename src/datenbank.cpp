#include "datenbank.h"
#include "ui_datenbank.h"

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
                reArrayShort.append(recordsArray[i]);
            }


        }


        QJsonObject reObjectShort;
        reObjectShort["records"] = reArrayShort;

        QJsonDocument jsDbShort(reObjectShort);

        QFile file2(PfadGeber("Starlink", "covidShort.json" ));
        file2.open(QIODevice::WriteOnly);
        file2.write(jsDbShort.toJson());
        file2.close();



    }


}
//Verbindet die JSON Datenbank
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

//Gibt Anzahl von Infizierten am "Datum" für ein Land mit Kennzeichnung "geoID". Gib "-999", wenn etwas
//schief gelaufen ist.
int  Datenbank::gibInfiierte(QString Datum, QString geoID)
{
    QFile file (PfadGeber("Starlink", "covidShort.json"));

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

//Gibt Gesamztanzahl von Infizierten im "Monat" für ein Land mit Kennzeichnung "geoID". Gib "-999", wenn etwas
//schief gelaufen ist.
int  Datenbank::gibGesamtInfizierte (QString Monat, QString geoID)
{
    Datenbank::Gesamt_Infi = 0;

    QFile file (PfadGeber("Starlink", "covidShort.json"));

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
    QSqlQueryModel *model = new QSqlQueryModel;
      model->setQuery("SELECT Datum, anzahlInfiziierte, anzahlTode, Gebiet  FROM covidraw WHERE Monat = '6' AND geoID = 'DE';");
      model->setHeaderData(0, Qt::Horizontal, tr("Datum"));
      model->setHeaderData(1, Qt::Horizontal, tr("anzahl von Infiziierte"));
      model->setHeaderData(2, Qt::Horizontal, tr("anzahl von Toden"));
      model->setHeaderData(4, Qt::Horizontal, tr("Land"));
      QTableView *view = new QTableView;
      view->setModel(model);
      view->show();
}

//beta
//...
void Datenbank::on_dbUpdate_clicked()
{
    QSqlQuery query;
    query.exec ("LOAD DATA INFILE 'C:\\Users\\M. AMOS\\Downloads\\Covid08072020.csv' INTO TABLE CovidRaw FIELDS TERMINATE BY ',' LINES TERMINATEDBY '\n' IGNORE 1 LINES");
    QMessageBox::information(this, "Aktualisierung", "Daten aktualisiert");
}

//beta
//...
void Datenbank::on_dbDelete_clicked()
{
    QSqlQuery query;
    query.exec("delete* ;");
    query.exec("CREATE TABLE 'CovidRaw'('Datum'	TEXT,'Tag'	INTEGER,'Monat'	INTEGER,'Year'	INTEGER,'AnzahlInfiziierte'	INTEGER,'AnzahlTode'	INTEGER,'Gebiet'	TEXT,'GeoID'   TEXT, 'countryterritorycode'	TEXT,'popdata2018'	INTEGER,'Kontinent'	TEXT,PRIMARY KEY('countryterritorycode','Datum'));");
    QMessageBox::information(this, "Aktualisierung", "Daten bereit zur Aktualisierung");
}

void Datenbank::on_dbOK_accepted()
{
    this->close();
}
