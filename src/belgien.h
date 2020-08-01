#ifndef BELGIEN_H
#define BELGIEN_H

#include <QDialog>
#include <QAbstractButton>

#include "laender.h"

namespace Ui {
class Belgien;
}

class Belgien : public QDialog
{
    Q_OBJECT

public:
    explicit Belgien(QWidget *parent = nullptr);
    ~Belgien();

private:

    Laender Land;

    QString geoID = "BE";

private slots:

 void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Belgien *ui;
};

#endif // BELGIEN_H
