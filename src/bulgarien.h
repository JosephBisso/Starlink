#ifndef BULGARIEN_H
#define BULGARIEN_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Bulgarien;
}

class Bulgarien : public QDialog
{
    Q_OBJECT

public:
    explicit Bulgarien(QWidget *parent = nullptr);
    ~Bulgarien();

private slots:

    void on_buttonBox_clicked(QAbstractButton *button);
    void on_skalaLiear_clicked();

    void on_skalaLogarithm_clicked();

private:

    Laender Land;

    QString geoID = "BG";

private:
    Ui::Bulgarien *ui;
};

#endif // BULGARIEN_H
