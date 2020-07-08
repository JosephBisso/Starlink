#ifndef ITALIEN_H
#define ITALIEN_H

#include <QDialog>

namespace Ui {
class Italien;
}

class Italien : public QDialog
{
    Q_OBJECT

public:
    explicit Italien(QWidget *parent = nullptr);
    ~Italien();

private:
    Ui::Italien *ui;
};

#endif // ITALIEN_H
