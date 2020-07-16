#ifndef SCHWEDEN_H
#define SCHWEDEN_H

#include <QDialog>

namespace Ui {
class Schweden;
}

class Schweden : public QDialog
{
    Q_OBJECT

public:
    explicit Schweden(QWidget *parent = nullptr);
    ~Schweden();

private:
    Ui::Schweden *ui;
};

#endif // SCHWEDEN_H
