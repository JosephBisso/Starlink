#ifndef DATENBANK_H
#define DATENBANK_H

#include <QDialog>

//...
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <iostream>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QTableView>
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QFile>


namespace Ui {
class Datenbank;
}

class Datenbank : public QDialog
{
    Q_OBJECT

public:
    explicit Datenbank(QWidget *parent = nullptr);
    ~Datenbank();

private slots:
    void on_dbConnect_clicked();

    void on_dbShow_clicked();

    void on_dbUpdate_clicked();

    void on_dbOK_accepted();

public:

    QString PfadGeber(QString dir, QString file); //Gibt den absoluten Pfad für eine Datei 'File' im Ordner "dir"

    int  gibInfiierte(QString Datum, QString geoID); //Setzt und Gibt Anzahl von Infizierten am "Datum" für ein Land
                                                     //mit Kennzeichnung "geoID"

    int  gibTode(QString Datum, QString geoID);   //Setzt und Gibt Anzahl von Todem am "Datum" für ein Land mit
                                                  //Kennzeichnung "geoID"

    QString gibDatum(QString Tag, QString Monat); //Setzt und Gibt Datum aus "Tag" und "Monat". Jahr meisteins 2020.

    QString gibLand(QString geoID); //Setzt und Gibt den englische Name aus Landkennzeichung "geoID"

    int  gibGesamtInfizierte (QString Monat, QString geoID); //Setzt und Gibt Gesamtanzahl von Infizierten im "Monat"
                                                             //für ein Land mit Kennzeichnung "geoID"

    int  gibGesamtTode (QString Monat, QString geoID); //Setzt und Gibt Gesamtanzahl von Toden im "Monat"
                                                       //für ein Land mit Kennzeichnung "geoID"

    QJsonDocument jsDbConnect(); //Verbindet die JSON Datenbank

    void jsDbShort(); //Reduziert Daten in Datenbank auf die nötigen (EU-Länder)

private:
    Ui::Datenbank *ui;

    QString Datum;

    QString Tag ;

    QString Monat;

    QString Jahr;

    int     Infiziierte;

    int     Tode ;

    int     Gesamt_Infi ;

    int     Gesamt_Tode;

    QString Land;

    QString geoID; //Landkennzeichung

    QString Kontinent;
};

#endif // DATENBANK_H
