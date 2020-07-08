#ifndef KROATIEN_H
#define KROATIEN_H

#include <QDialog>

namespace Ui {
class Kroatien;
}

class Kroatien : public QDialog
{
    Q_OBJECT

public:
    explicit Kroatien(QWidget *parent = nullptr);
    ~Kroatien();

private:
    Ui::Kroatien *ui;
};

#endif // KROATIEN_H
