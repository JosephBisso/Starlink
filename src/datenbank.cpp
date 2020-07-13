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

//eine Verbindung zur Datenbank "Datenbank.sqlite" wird aufgebaut. Man bekommt danach eine Benachrichtigung
void Datenbank::on_dbConnect_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");


       db.setDatabaseName(PfadGeber("src", "Datenbank.sqlite"));

       bool ok = db.open();

       if (ok == true) {
           QMessageBox::information(this, "Verbindung", "Verbindung zur Datenbank erfolgreich aufgebaut");}

       else {
           QMessageBox::information(this, "Verbindung", "Keine Verbindung zur Datenbank möglich");
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
