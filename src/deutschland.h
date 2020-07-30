#ifndef DEUTSCHLAND_H
#define DEUTSCHLAND_H

#include "laender.h"

#include <QDialog>

#include <QAbstractButton>

namespace Ui {
class Deutschland;
}

class Deutschland : public QDialog
{
    Q_OBJECT

public:
    explicit Deutschland(QWidget *parent = nullptr);
    ~Deutschland();


private slots:

    void on_buttonBox_clicked(QAbstractButton *button);

    void on_skalaLogarithm_clicked();

     void on_skalaLiear_clicked();

     //Nicht Vergessen!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
private:

    Laender Land; // Ein Element der Klasse Land wird erstellt. Dies erlaubt uns alle Methoden der Klasse Databank
                  // (gibDatum, gibInfiziierte, gitTode, gibMonat, etc ) durch das Attribut DbLandDaten
                  // vom Typ Databank der Klasse Laender zu benutzen.

    QString geoID = "DE";

private:
    Ui::Deutschland *ui;

};

#endif // DEUTSCHLAND_H
