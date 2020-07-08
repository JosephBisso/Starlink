#ifndef FINNLAND_H
#define FINNLAND_H

#include <QDialog>

namespace Ui {
class Finnland;
}

class Finnland : public QDialog
{
    Q_OBJECT

public:
    explicit Finnland(QWidget *parent = nullptr);
    ~Finnland();

private:
    Ui::Finnland *ui;
};

#endif // FINNLAND_H
