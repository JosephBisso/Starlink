#ifndef BOSNIEN_H
#define BOSNIEN_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Bosnien;
}

class Bosnien : public QDialog
{
    Q_OBJECT

public:
    explicit Bosnien(QWidget *parent = nullptr);
    ~Bosnien();

private slots:

void on_buttonBox_clicked(QAbstractButton *button);
private:

    Laender Land;

    QString geoID = "BA";

private:
    Ui::Bosnien *ui;
};

#endif // BOSNIEN_H
