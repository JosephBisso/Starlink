#ifndef FINNLAND_H
#define FINNLAND_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Finnland;
}

class Finnland : public QDialog
{
    Q_OBJECT

public:
    explicit Finnland(QWidget *parent = nullptr);
    ~Finnland();

private slots:

void on_buttonBox_clicked(QAbstractButton *button);
void on_skalaLiear_clicked();

void on_skalaLogarithm_clicked();

private:

    Laender Land;

    QString geoID = "FI";

private:
    Ui::Finnland *ui;
};

#endif // FINNLAND_H
