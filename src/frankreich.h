#ifndef FRANKREICH_H
#define FRANKREICH_H

#include <QDialog>

#include <QAbstractButton> //Wichtig!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include "laender.h"

namespace Ui {
class Frankreich;
}

class Frankreich : public QDialog
{
    Q_OBJECT

public:
    explicit Frankreich(QWidget *parent = nullptr);
    ~Frankreich();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_skalaLiear_clicked();

    void on_skalaLogarithm_clicked();

private:

    Laender Land;

    QString geoID = "FR";

private:
    Ui::Frankreich *ui;
};

#endif // FRANKREICH_H
