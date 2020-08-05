#ifndef SERBIEN_H
#define SERBIEN_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Serbien;
}

class Serbien : public QDialog
{
    Q_OBJECT

public:
    explicit Serbien(QWidget *parent = nullptr);
    ~Serbien();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_skalaLiear_clicked();

    void on_skalaLogarithm_clicked();

private:

    Laender Land;

    QString geoID = "RS";

private:
    Ui::Serbien *ui;
};

#endif // SERBIEN_H
