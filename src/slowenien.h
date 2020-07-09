#ifndef SLOWENIEN_H
#define SLOWENIEN_H

#include <QDialog>

namespace Ui {
class Slowenien;
}

class Slowenien : public QDialog
{
    Q_OBJECT

public:
    explicit Slowenien(QWidget *parent = nullptr);
    ~Slowenien();

private:
    Ui::Slowenien *ui;
};

#endif // SLOWENIEN_H
