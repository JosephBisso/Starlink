#ifndef UKRAINE_H
#define UKRAINE_H

#include <QDialog>

namespace Ui {
class Ukraine;
}

class Ukraine : public QDialog
{
    Q_OBJECT

public:
    explicit Ukraine(QWidget *parent = nullptr);
    ~Ukraine();

private:
    Ui::Ukraine *ui;
};

#endif // UKRAINE_H
