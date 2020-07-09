#ifndef RUMANIEN_H
#define RUMANIEN_H

#include <QDialog>

namespace Ui {
class Rumanien;
}

class Rumanien : public QDialog
{
    Q_OBJECT

public:
    explicit Rumanien(QWidget *parent = nullptr);
    ~Rumanien();

private:
    Ui::Rumanien *ui;
};

#endif // RUMANIEN_H
