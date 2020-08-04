#ifndef DAENEMARK_H
#define DAENEMARK_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Daenemark;
}

class Daenemark : public QDialog
{
    Q_OBJECT

public:
    explicit Daenemark(QWidget *parent = nullptr);
    ~Daenemark();

private slots:

void on_buttonBox_clicked(QAbstractButton *button);
void on_skalaLiear_clicked();

void on_skalaLogarithm_clicked();

private:

    Laender Land;

    QString geoID = "DK";

private:
    Ui::Daenemark *ui;
};

#endif // DAENEMARK_H
