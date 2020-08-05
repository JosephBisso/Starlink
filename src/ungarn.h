#ifndef UNGARN_H
#define UNGARN_H

#include <QDialog>
#include <QAbstractButton>
#include "laender.h"

namespace Ui {
class Ungarn;
}

class Ungarn : public QDialog
{
    Q_OBJECT

public:
    explicit Ungarn(QWidget *parent = nullptr);
    ~Ungarn();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_skalaLiear_clicked();

    void on_skalaLogarithm_clicked();

private:

    Laender Land;

    QString geoID = "HU";

private:
    Ui::Ungarn *ui;
};

#endif // UNGARN_H
