#ifndef ITALIEN_H
#define ITALIEN_H

#include <QDialog>

#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Italien;
}

class Italien : public QDialog
{
    Q_OBJECT

public:
    explicit Italien(QWidget *parent = nullptr);
    ~Italien();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_skalaLiear_clicked();

    void on_skalaLogarithm_clicked();

private:

    Laender Land;

    QString geoID = "IT";

private:
    Ui::Italien *ui;
};

#endif // ITALIEN_H
