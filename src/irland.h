#ifndef IRLAND_H
#define IRLAND_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Irland;
}

class Irland : public QDialog
{
    Q_OBJECT

public:
    explicit Irland(QWidget *parent = nullptr);
    ~Irland();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Irland *ui;
};

#endif // IRLAND_H
