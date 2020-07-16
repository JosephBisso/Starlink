#include "laender.h"
#include "databank.h"

Laender::Laender(QObject *parent) : QObject(parent)
{
   //(gibLandDaten(ui->,ui->, ui->));
   //int ok = DbLandDaten.Infiziierte;

}

void Laender::gibLandDaten(QString Tag, QString Monat, QString geoID)
{
    DbLandDaten.geoID = geoID;

    QString Datum = DbLandDaten.gibDatum(Tag, Monat);

    DbLandDaten.gibInfiierte(Datum, geoID);

    DbLandDaten.gibTode(Datum, geoID );

    DbLandDaten.gibLand(geoID);

    DbLandDaten.gibGesamtInfizierte(Datum, geoID);

    DbLandDaten.gibGesamtTode(Datum, geoID);

}


