#ifndef LAENDER_H
#define LAENDER_H
#include "databank.h"

#include <QObject>
#include <QLineSeries>
#include <QtCharts>
#include <QMessageBox>

#include <QtMath>

#include <QDebug>

class Laender : public QObject //Diese Klasse beinhaltet alle Methoden zur Gewinnung von Daten eines beliebigen Landes.
{
    Q_OBJECT
public:
    explicit Laender(QObject *parent = nullptr);

    void setGeoID(QString geoID);

    QString getGeoID();

    databank DbLandDaten; //Die Klasse databank erlaubt dank ihrer Methoden den Zugriff auf die Datenbank

    void gibLandDaten(QString Tag, QString Monat);

    void InfiTodeMonat (); //Rechnet und speichert
                              //Gesamtinfiziierte und -Tode
                                //für alle Monate in 2 Felder.

    int FillTab (QDate uiDatum, bool skalalinear);

    void FillLines (QDate uiDatum);

    QString Fill7TagDurchschnitt (QDate uiDatum);

    QString InfiproEinwohner (int Einwohnerzahl);


    double infMonat [12]; //Ein Feld mit Größe 12 wir erstellt.

    double todMonat [12];

    qreal tblInfi [2][31],
           tblTode[2][31];

    bool skalaLinear = true;


    QString Infi,
            Tode;


private:

    QString geoID = "-999";

signals:

};

#endif // LAENDER_H
