#ifndef SCHWEIZ_H
#define SCHWEIZ_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Schweiz;
}

class Schweiz : public QDialog
{
    Q_OBJECT

public:
    explicit Schweiz(QWidget *parent = nullptr);
    ~Schweiz();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_skalaLiear_clicked();

    void on_skalaLogarithm_clicked();

private:

    Laender Land;

    QString geoID = "CH";

private:
    Ui::Schweiz *ui;
};

#endif // SCHWEIZ_H
