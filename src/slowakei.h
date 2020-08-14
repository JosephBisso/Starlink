#ifndef SLOWAKEI_H
#define SLOWAKEI_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Slowakei;
}

class Slowakei : public QDialog
{
    Q_OBJECT

public:
    explicit Slowakei(QWidget *parent = nullptr);
    ~Slowakei();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_skalaLiear_clicked();

    void on_skalaLogarithm_clicked();

private:

    Laender Land;

    QString geoID = "SK";

private:
    Ui::Slowakei *ui;
};

#endif // SLOWAKEI_H
