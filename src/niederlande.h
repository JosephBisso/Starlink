#ifndef NIEDERLANDE_H
#define NIEDERLANDE_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Niederlande;
}

class Niederlande : public QDialog
{
    Q_OBJECT

public:
    explicit Niederlande(QWidget *parent = nullptr);
    ~Niederlande();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Niederlande *ui;
};

#endif // NIEDERLANDE_H
