#ifndef SCHWEDEN_H
#define SCHWEDEN_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Schweden;
}

class Schweden : public QDialog
{
    Q_OBJECT

public:
    explicit Schweden(QWidget *parent = nullptr);
    ~Schweden();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
private:

    Laender Land;

    QString geoID = "SE";

private:
    Ui::Schweden *ui;
};

#endif // SCHWEDEN_H
