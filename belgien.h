#ifndef BELGIEN_H
#define BELGIEN_H

#include <QDialog>

namespace Ui {
class Belgien;
}

class Belgien : public QDialog
{
    Q_OBJECT

public:
    explicit Belgien(QWidget *parent = nullptr);
    ~Belgien();

private:
    Ui::Belgien *ui;
};

#endif // BELGIEN_H
