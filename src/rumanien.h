#ifndef RUMANIEN_H
#define RUMANIEN_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Rumanien;
}

class Rumanien : public QDialog
{
    Q_OBJECT

public:
    explicit Rumanien(QWidget *parent = nullptr);
    ~Rumanien();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_skalaLiear_clicked();

    void on_skalaLogarithm_clicked();

private:

    Laender Land;

    QString geoID = "RO";

private:
    Ui::Rumanien *ui;
};

#endif // RUMANIEN_H
