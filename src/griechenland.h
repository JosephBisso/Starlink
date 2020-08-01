#ifndef GRIECHENLAND_H
#define GRIECHENLAND_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Griechenland;
}

class Griechenland : public QDialog
{
    Q_OBJECT

public:
    explicit Griechenland(QWidget *parent = nullptr);
    ~Griechenland();

private slots:

void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Griechenland *ui;
};

#endif // GRIECHENLAND_H
