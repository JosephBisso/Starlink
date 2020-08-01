#ifndef ESTLAND_H
#define ESTLAND_H

#include <QDialog>
#include "laender.h"
#include <QAbstractButton>

namespace Ui {
class Estland;
}

class Estland : public QDialog
{
    Q_OBJECT

public:
    explicit Estland(QWidget *parent = nullptr);
    ~Estland();

private slots:

void on_buttonBox_clicked(QAbstractButton *button);
private:

    Laender Land;

    QString geoID = "EE";

private:
    Ui::Estland *ui;
};

#endif // ESTLAND_H
