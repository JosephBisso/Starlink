#ifndef LAENDER_H
#define LAENDER_H
#include "databank.h"

#include <QObject>
#include <QLineSeries>
#include <QtCharts>
#include <QMessageBox>

#include <QtMath>

#include <QDebug>

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

    int FillTab (QDate uiDatum, bool skalalinear, QString geoID);

    void FillLines (QDate uiDatum, QString geoID);


    double infMonat [12]; //Ein Feld mit Größe 12 wir erstellt.

    double todMonat [12];

    qreal tblInfi [2][31],
           tblTode[2][31];

    bool skalaLinear = true;

    QString geoID;

    QString Infi,
            Tode;

private:

signals:

};

#endif // LAENDER_H
