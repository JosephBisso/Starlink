#ifndef MONTENEGRO_H
#define MONTENEGRO_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Montenegro;
}

class Montenegro : public QDialog
{
    Q_OBJECT

public:
    explicit Montenegro(QWidget *parent = nullptr);
    ~Montenegro();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
private:

    Laender Land;

    QString geoID = "ME";

private:
    Ui::Montenegro *ui;
};

#endif // MONTENEGRO_H
