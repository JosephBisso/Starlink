#ifndef SLOWENIEN_H
#define SLOWENIEN_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Slowenien;
}

class Slowenien : public QDialog
{
    Q_OBJECT

public:
    explicit Slowenien(QWidget *parent = nullptr);
    ~Slowenien();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_skalaLiear_clicked();

    void on_skalaLogarithm_clicked();

private:

    Laender Land;

    QString geoID = "SI";

private:
    Ui::Slowenien *ui;
};

#endif // SLOWENIEN_H
