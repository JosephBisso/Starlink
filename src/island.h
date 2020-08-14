#ifndef ISLAND_H
#define ISLAND_H

#include <QDialog>

#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Island;
}

class Island : public QDialog
{
    Q_OBJECT

public:
    explicit Island(QWidget *parent = nullptr);
    ~Island();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_skalaLiear_clicked();

    void on_skalaLogarithm_clicked();

private:

    Laender Land;

    QString geoID = "IS";

private:
    Ui::Island *ui;
};

#endif // ISLAND_H
