#ifndef PORTUGAL_H
#define PORTUGAL_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Portugal;
}

class Portugal : public QDialog
{
    Q_OBJECT

public:
    explicit Portugal(QWidget *parent = nullptr);
    ~Portugal();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
private:

    Laender Land;

    QString geoID = "PT";

private:
    Ui::Portugal *ui;
};

#endif // PORTUGAL_H
