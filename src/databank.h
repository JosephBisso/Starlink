#ifndef DATABANK_H
#define DATABANK_H

#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QFile>
#include <QObject>

class databank : public QObject
{
    Q_OBJECT
public:
    explicit databank(QObject *parent = nullptr);

    QString PfadGeber(QString dir, QString file); //Gibt den absoluten Pfad für eine Datei 'File' im Ordner "dir"

    int  gibInfiierte(QString Datum, QString geoID); //Setzt und Gibt Anzahl von Infizierten am "Datum" für ein Land
                                                     //mit Kennzeichnung "geoID"

    int  gibTode(QString Datum, QString geoID);   //Setzt und Gibt Anzahl von Todem am "Datum" für ein Land mit
                                                  //Kennzeichnung "geoID"

    QString gibDatum(QString Tag, QString Monat); //Setzt und Gibt Datum aus "Tag" und "Monat". Jahr meisteins 2020.

    QString gibMonat(QString Monat); //Gib den Namen des Monats

    QString gibLand(QString geoID); //Setzt und Gibt den englische Name aus Landkennzeichung "geoID"

    int  gibGesamtInfizierte (QString Monat, QString geoID); //Setzt und Gibt Gesamtanzahl von Infizierten im "Monat"
                                                             //für ein Land mit Kennzeichnung "geoID"

    int  gibGesamtTode (QString Monat, QString geoID); //Setzt und Gibt Gesamtanzahl von Toden im "Monat"
                                                       //für ein Land mit Kennzeichnung "geoID"

    QJsonDocument jsDbConnect(); //Verbindet die JSON Datenbank

    void jsDbShort(); //Reduziert Daten in Datenbank auf die nötigen (EU-Länder)

public:

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

signals:

};

#endif // DATABANK_H
