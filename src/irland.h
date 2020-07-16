#ifndef IRLAND_H
#define IRLAND_H

#include <QDialog>

namespace Ui {
class Irland;
}

class Irland : public QDialog
{
    Q_OBJECT

public:
    explicit Irland(QWidget *parent = nullptr);
    ~Irland();

private:
    Ui::Irland *ui;
};

#endif // IRLAND_H
