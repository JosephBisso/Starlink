#ifndef SERBIEN_H
#define SERBIEN_H

#include <QDialog>

namespace Ui {
class Serbien;
}

class Serbien : public QDialog
{
    Q_OBJECT

public:
    explicit Serbien(QWidget *parent = nullptr);
    ~Serbien();

private:
    Ui::Serbien *ui;
};

#endif // SERBIEN_H
