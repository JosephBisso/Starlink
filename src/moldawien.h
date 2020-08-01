#ifndef MOLDAWIEN_H
#define MOLDAWIEN_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Moldawien;
}

class Moldawien : public QDialog
{
    Q_OBJECT

public:
    explicit Moldawien(QWidget *parent = nullptr);
    ~Moldawien();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
private:

    Laender Land;

    QString geoID = "MD";

private:
    Ui::Moldawien *ui;
};

#endif // MOLDAWIEN_H
