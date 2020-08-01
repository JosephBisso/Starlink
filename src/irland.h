#ifndef IRLAND_H
#define IRLAND_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Irland;
}

class Irland : public QDialog
{
    Q_OBJECT

public:
    explicit Irland(QWidget *parent = nullptr);
    ~Irland();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
private:

    Laender Land;

    QString geoID = "IE";

private:
    Ui::Irland *ui;
};

#endif // IRLAND_H
