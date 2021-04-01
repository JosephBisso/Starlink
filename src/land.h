#ifndef LAND_H
#define LAND_H

#include <QWidget>
#include "laender.h"
#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Land;
}

class Land : public QDialog
{
    Q_OBJECT

public:
    explicit Land(QWidget *parent = nullptr);
    ~Land();


    void setGeoID(QString geoID);

    QString setTitle();

private slots:

    void on_buttonBox_clicked(QAbstractButton *button);

    void on_skalaLogarithm_clicked();

    void on_skalaLiear_clicked();

private:

   void doDiagramm();

private:
    Ui::Land *ui;

    Laender* laender = new Laender(this);
};

#endif // LAND_H
