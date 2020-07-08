#ifndef BULGARIEN_H
#define BULGARIEN_H

#include <QDialog>

namespace Ui {
class Bulgarien;
}

class Bulgarien : public QDialog
{
    Q_OBJECT

public:
    explicit Bulgarien(QWidget *parent = nullptr);
    ~Bulgarien();

private:
    Ui::Bulgarien *ui;
};

#endif // BULGARIEN_H
