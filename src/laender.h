#ifndef LAENDER_H
#define LAENDER_H
#include "databank.h"

#include <QObject>
#include <QLineSeries>
#include <QtCharts>

class Laender : public QObject
{
    Q_OBJECT
public:
    explicit Laender(QObject *parent = nullptr);    

    databank DbLandDaten;

    void gibLandDaten(QString Tag, QString Monat, QString geoID);

    void InfiTodeMonat (QString geoID); //Rechnet und speichert
                              //Gesamtinfiziierte und -Tode
                                //für alle Monate in 2 Felder.

    void FillTab (QLineSeries* series, QString Monat);


    double infMonat [12]; //Ein Feld mit Größe 12 wir erstellt.

    double todMonat [12];


signals:

};

#endif // LAENDER_H
