#ifndef GROSSBRITANNIEN_H
#define GROSSBRITANNIEN_H

#include <QDialog>

namespace Ui {
class Grossbritannien;
}

class Grossbritannien : public QDialog
{
    Q_OBJECT

public:
    explicit Grossbritannien(QWidget *parent = nullptr);
    ~Grossbritannien();

private:
    Ui::Grossbritannien *ui;
};

#endif // GROSSBRITANNIEN_H
