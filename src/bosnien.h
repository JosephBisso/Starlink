#ifndef BOSNIEN_H
#define BOSNIEN_H

#include <QDialog>

namespace Ui {
class Bosnien;
}

class Bosnien : public QDialog
{
    Q_OBJECT

public:
    explicit Bosnien(QWidget *parent = nullptr);
    ~Bosnien();

private:
    Ui::Bosnien *ui;
};

#endif // BOSNIEN_H
