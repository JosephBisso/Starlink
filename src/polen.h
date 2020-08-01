#ifndef POLEN_H
#define POLEN_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Polen;
}

class Polen : public QDialog
{
    Q_OBJECT

public:
    explicit Polen(QWidget *parent = nullptr);
    ~Polen();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
private:

    Laender Land;

    QString geoID = "PL";

private:
    Ui::Polen *ui;
};

#endif // POLEN_H
