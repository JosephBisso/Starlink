#ifndef DBVORSCHAU_H
#define DBVORSCHAU_H

#include <QDialog>

namespace Ui {
class dbVorschau;
}

class dbVorschau : public QDialog
{
    Q_OBJECT

public:
    explicit dbVorschau(QWidget *parent = nullptr);
    ~dbVorschau();

    void VorschauFillTable();

private:
    Ui::dbVorschau *ui;
};

#endif // DBVORSCHAU_H
