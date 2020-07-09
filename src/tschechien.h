#ifndef TSCHECHIEN_H
#define TSCHECHIEN_H

#include <QDialog>

namespace Ui {
class Tschechien;
}

class Tschechien : public QDialog
{
    Q_OBJECT

public:
    explicit Tschechien(QWidget *parent = nullptr);
    ~Tschechien();

private:
    Ui::Tschechien *ui;
};

#endif // TSCHECHIEN_H
