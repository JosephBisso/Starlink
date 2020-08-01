#ifndef ALBANIEN_H
#define ALBANIEN_H

#include <QDialog>
#include "laender.h"
#include <QAbstractButton> //Wichtig!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

namespace Ui {
class Albanien;
}

class Albanien : public QDialog
{
    Q_OBJECT

public:
    explicit Albanien(QWidget *parent = nullptr);
    ~Albanien();

private slots:

    void on_buttonBox_clicked(QAbstractButton *button);

private:

    Laender Land;

    QString geoID = "AL";

private:
    Ui::Albanien *ui;
};

#endif // ALBANIEN_H
