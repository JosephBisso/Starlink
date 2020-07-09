#ifndef PORTUGAL_H
#define PORTUGAL_H

#include <QDialog>

namespace Ui {
class Portugal;
}

class Portugal : public QDialog
{
    Q_OBJECT

public:
    explicit Portugal(QWidget *parent = nullptr);
    ~Portugal();

private:
    Ui::Portugal *ui;
};

#endif // PORTUGAL_H
