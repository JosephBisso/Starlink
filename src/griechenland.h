#ifndef GRIECHENLAND_H
#define GRIECHENLAND_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Griechenland;
}

class Griechenland : public QDialog
{
    Q_OBJECT

public:
    explicit Griechenland(QWidget *parent = nullptr);
    ~Griechenland();

private slots:

void on_buttonBox_clicked(QAbstractButton *button);
private:

    Laender Land;

    QString geoID = "EL";

private:
    Ui::Griechenland *ui;
};

#endif // GRIECHENLAND_H
