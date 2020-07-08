#ifndef ALBANIEN_H
#define ALBANIEN_H

#include <QDialog>

namespace Ui {
class Albanien;
}

class Albanien : public QDialog
{
    Q_OBJECT

public:
    explicit Albanien(QWidget *parent = nullptr);
    ~Albanien();

private:
    Ui::Albanien *ui;
};

#endif // ALBANIEN_H
