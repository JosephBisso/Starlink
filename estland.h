#ifndef ESTLAND_H
#define ESTLAND_H

#include <QDialog>

namespace Ui {
class Estland;
}

class Estland : public QDialog
{
    Q_OBJECT

public:
    explicit Estland(QWidget *parent = nullptr);
    ~Estland();

private:
    Ui::Estland *ui;
};

#endif // ESTLAND_H
