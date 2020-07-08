#ifndef ANDORRA_H
#define ANDORRA_H

#include <QDialog>

namespace Ui {
class Andorra;
}

class Andorra : public QDialog
{
    Q_OBJECT

public:
    explicit Andorra(QWidget *parent = nullptr);
    ~Andorra();

private:
    Ui::Andorra *ui;
};

#endif // ANDORRA_H
