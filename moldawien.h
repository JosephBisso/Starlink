#ifndef MOLDAWIEN_H
#define MOLDAWIEN_H

#include <QDialog>

namespace Ui {
class Moldawien;
}

class Moldawien : public QDialog
{
    Q_OBJECT

public:
    explicit Moldawien(QWidget *parent = nullptr);
    ~Moldawien();

private:
    Ui::Moldawien *ui;
};

#endif // MOLDAWIEN_H
