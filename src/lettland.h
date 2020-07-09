#ifndef LETTLAND_H
#define LETTLAND_H

#include <QDialog>

namespace Ui {
class Lettland;
}

class Lettland : public QDialog
{
    Q_OBJECT

public:
    explicit Lettland(QWidget *parent = nullptr);
    ~Lettland();

private:
    Ui::Lettland *ui;
};

#endif // LETTLAND_H
