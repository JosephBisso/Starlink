#ifndef SPANIEN_H
#define SPANIEN_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Spanien;
}

class Spanien : public QDialog
{
    Q_OBJECT

public:
    explicit Spanien(QWidget *parent = nullptr);
    ~Spanien();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_skalaLiear_clicked();

    void on_skalaLogarithm_clicked();

private:

    Laender Land;

    QString geoID = "ES";

private:
    Ui::Spanien *ui;
};

#endif // SPANIEN_H
