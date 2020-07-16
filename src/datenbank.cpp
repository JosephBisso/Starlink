#include "datenbank.h"
#include "ui_datenbank.h"
#include "dbvorschau.h"
#include "databank.h"

Datenbank::Datenbank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Datenbank)
{
    ui->setupUi(this);

    databank Datenbank;
}

Datenbank::~Datenbank()
{
    delete ui;
}


//eine Verbindung zur Datenbank "covidShort.json" wird aufgebaut. Man bekommt danach eine Benachrichtigung
void Datenbank::on_dbConnect_clicked()
{

    if (datenbank.jsDbConnect().isEmpty())
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
    datenbank.jsDbShort();

    QMessageBox::information(this, "Aktualisierung", "Daten erfolgreich aktualisiert");
}


void Datenbank::on_dbOK_accepted()
{
    this->close();
}
