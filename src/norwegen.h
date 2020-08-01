#ifndef NORWEGEN_H
#define NORWEGEN_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Norwegen;
}

class Norwegen : public QDialog
{
    Q_OBJECT

public:
    explicit Norwegen(QWidget *parent = nullptr);
    ~Norwegen();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Norwegen *ui;
};

#endif // NORWEGEN_H
