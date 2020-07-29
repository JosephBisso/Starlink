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

    double* InfiMonat (QString geoID);

    double* TodeMonat (QString geoID);


signals:

};

#endif // LAENDER_H
