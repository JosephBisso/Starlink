#ifndef FINNLAND_H
#define FINNLAND_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Finnland;
}

class Finnland : public QDialog
{
    Q_OBJECT

public:
    explicit Finnland(QWidget *parent = nullptr);
    ~Finnland();

private slots:

void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Finnland *ui;
};

#endif // FINNLAND_H
