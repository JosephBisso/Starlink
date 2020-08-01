#ifndef TSCHECHIEN_H
#define TSCHECHIEN_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Tschechien;
}

class Tschechien : public QDialog
{
    Q_OBJECT

public:
    explicit Tschechien(QWidget *parent = nullptr);
    ~Tschechien();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
private:

    Laender Land;

    QString geoID = "CZ";

private:
    Ui::Tschechien *ui;
};

#endif // TSCHECHIEN_H
