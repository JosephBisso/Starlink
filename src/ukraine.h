#ifndef UKRAINE_H
#define UKRAINE_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Ukraine;
}

class Ukraine : public QDialog
{
    Q_OBJECT

public:
    explicit Ukraine(QWidget *parent = nullptr);
    ~Ukraine();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_skalaLiear_clicked();

    void on_skalaLogarithm_clicked();

private:

    Laender Land;

    QString geoID = "UA";

private:
    Ui::Ukraine *ui;
};

#endif // UKRAINE_H
