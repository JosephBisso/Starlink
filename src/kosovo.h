#ifndef KOSOVO_H
#define KOSOVO_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Kosovo;
}

class Kosovo : public QDialog
{
    Q_OBJECT

public:
    explicit Kosovo(QWidget *parent = nullptr);
    ~Kosovo();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_skalaLiear_clicked();

    void on_skalaLogarithm_clicked();

private:

    Laender Land;

    QString geoID = "XK";

private:
    Ui::Kosovo *ui;
};

#endif // KOSOVO_H
