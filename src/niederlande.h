#ifndef NIEDERLANDE_H
#define NIEDERLANDE_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Niederlande;
}

class Niederlande : public QDialog
{
    Q_OBJECT

public:
    explicit Niederlande(QWidget *parent = nullptr);
    ~Niederlande();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
private:

    Laender Land;

    QString geoID = "NL";

private:
    Ui::Niederlande *ui;
};

#endif // NIEDERLANDE_H
