#ifndef SCHWEIZ_H
#define SCHWEIZ_H

#include <QDialog>

namespace Ui {
class Schweiz;
}

class Schweiz : public QDialog
{
    Q_OBJECT

public:
    explicit Schweiz(QWidget *parent = nullptr);
    ~Schweiz();

private:
    Ui::Schweiz *ui;
};

#endif // SCHWEIZ_H
