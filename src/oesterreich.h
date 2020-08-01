#ifndef OESTERREICH_H
#define OESTERREICH_H

#include <QDialog>

#include <QAbstractButton> //Wichtig!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include "laender.h"

namespace Ui {
class Oesterreich;
}

class Oesterreich : public QDialog
{
    Q_OBJECT

public:
    explicit Oesterreich(QWidget *parent = nullptr);
    ~Oesterreich();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
private:

    Laender Land;

    QString geoID = "AT";

private:
    Ui::Oesterreich *ui;
};

#endif // OESTERREICH_H
