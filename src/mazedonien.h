#ifndef MAZEDONIEN_H
#define MAZEDONIEN_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Mazedonien;
}

class Mazedonien : public QDialog
{
    Q_OBJECT

public:
    explicit Mazedonien(QWidget *parent = nullptr);
    ~Mazedonien();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_skalaLiear_clicked();

    void on_skalaLogarithm_clicked();

private:

    Laender Land;

    QString geoID = "MK";

private:
    Ui::Mazedonien *ui;
};

#endif // MAZEDONIEN_H
