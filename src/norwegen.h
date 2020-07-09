#ifndef NORWEGEN_H
#define NORWEGEN_H

#include <QDialog>

namespace Ui {
class Norwegen;
}

class Norwegen : public QDialog
{
    Q_OBJECT

public:
    explicit Norwegen(QWidget *parent = nullptr);
    ~Norwegen();

private:
    Ui::Norwegen *ui;
};

#endif // NORWEGEN_H
