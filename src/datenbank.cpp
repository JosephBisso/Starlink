#include "datenbank.h"
#include "ui_datenbank.h"
#include "dbvorschau.h"
#include "databank.h"


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


//eine Verbindung zur Datenbank "covidShort.json" wird aufgebaut. Man bekommt danach eine Benachrichtigung
//die Methode "jsDbConnect" wird ausgeführt. Je nach Ausgang des Ausführen wird das Attribut
//QJsonDocument entweder leer sein oder mit Dateien gefüllt, und so nicht leer sein .
//Das wird hier im if Satz genutzt
void Datenbank::on_dbConnect_clicked()
{
    ui->progressBar->setValue(80); //ProgressBar in der UI.


    if (datenbank.jsDbConnect().isEmpty())
    {
        ui->progressBar->setValue(100);

        QMessageBox::information(this, "Verbindung", "Verbindung zur Datenbank könnte nicht aufgebaut werden. "
                                                     "Versuchen Sie die Daten (im MainWindow) erstmal zu aktualiesiren.  "
                                                      "Eine unaktualisierte Backup-Datenbank wird stattdessen benutzt.");

    }

    else {

        QMessageBox::information(this, "Verdindung","Verbindung zur Datenbank gelungen"  );
    }

    ui->progressBar->setValue(0);
}

//einen Auszug aus der Datenbank wird tabellarisch dargestellt
void Datenbank::on_dbShow_clicked()
{
    ui->progressBar->setValue(45); //ProgressBar in der UI.

    dbVorschau* Vorschau = new dbVorschau(this);

    ui->progressBar->setValue(100);

    Vorschau->exec();

    ui->progressBar->setValue(0);
}


//die Methode "jsDbShort" wird ausgeführt. Je nach Ausgang des Ausführen wird das Attribut
//done auf true or false gesetzt. Das wird hier im if Satz genutzt.

void Datenbank::on_dbUpdate_clicked()
{
    ui->progressBar->setValue(15); //ProgressBar in der UI.

    datenbank.jsDbShort();

    ui->progressBar->setValue(90);

    if(datenbank.done)
    {

        ui->progressBar->setValue(100);

    QMessageBox::information(this, "Aktualisierung", "Daten erfolgreich aktualisiert. Letzter Stand im 'Vorschau' nachprüfen");
    }
    else
    {
     QMessageBox::information(this, "Aktualisierung", "Daten könnten nicht aktualisiert werden. Letzter Stand im 'Vorschau' nachprüfen");
    }

    ui->progressBar->setValue(0);
}


void Datenbank::on_dbOK_accepted()
{
    this->close();
}
