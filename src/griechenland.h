#ifndef GRIECHENLAND_H
#define GRIECHENLAND_H

#include <QDialog>

namespace Ui {
class Griechenland;
}

class Griechenland : public QDialog
{
    Q_OBJECT

public:
    explicit Griechenland(QWidget *parent = nullptr);
    ~Griechenland();

private:
    Ui::Griechenland *ui;
};

#endif // GRIECHENLAND_H
