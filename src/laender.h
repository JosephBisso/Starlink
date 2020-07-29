#ifndef LAENDER_H
#define LAENDER_H
#include "databank.h"

#include <QObject>

class Laender : public QObject
{
    Q_OBJECT
public:
    explicit Laender(QObject *parent = nullptr);    

    databank DbLandDaten;

    void gibLandDaten(QString Tag, QString Monat, QString geoID);

    double* InfiMonat (QString geoID); //Rechnet und speichert
                              //Gesamtinfiziierte für alle Monate in einem Feld und gibt uns einen
                                   //Zeiger zurück, der auf dieses Feld zeigt.

    double* TodeMonat (QString geoID); //Rechnet und speichert
    //GesamtTode für alle Monate in einem Feld und gibt uns einen
         //Zeiger zurück, der auf dieses Feld zeigt.



signals:

};

#endif // LAENDER_H
