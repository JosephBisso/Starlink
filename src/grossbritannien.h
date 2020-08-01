#ifndef GROSSBRITANNIEN_H
#define GROSSBRITANNIEN_H

#include <QDialog>

#include <QAbstractButton> //Wichtig!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include "laender.h"

namespace Ui {
class Grossbritannien;
}

class Grossbritannien : public QDialog
{
    Q_OBJECT

public:
    explicit Grossbritannien(QWidget *parent = nullptr);
    ~Grossbritannien();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
private:

    Laender Land;

    QString geoID = "UK";

private:
    Ui::Grossbritannien *ui;
};

#endif // GROSSBRITANNIEN_H
