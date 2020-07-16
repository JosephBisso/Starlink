#ifndef NIEDERLANDE_H
#define NIEDERLANDE_H

#include <QDialog>

namespace Ui {
class Niederlande;
}

class Niederlande : public QDialog
{
    Q_OBJECT

public:
    explicit Niederlande(QWidget *parent = nullptr);
    ~Niederlande();

private:
    Ui::Niederlande *ui;
};

#endif // NIEDERLANDE_H
