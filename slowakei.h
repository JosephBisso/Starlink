#ifndef SLOWAKEI_H
#define SLOWAKEI_H

#include <QDialog>

namespace Ui {
class Slowakei;
}

class Slowakei : public QDialog
{
    Q_OBJECT

public:
    explicit Slowakei(QWidget *parent = nullptr);
    ~Slowakei();

private:
    Ui::Slowakei *ui;
};

#endif // SLOWAKEI_H
