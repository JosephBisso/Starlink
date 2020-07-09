#ifndef LITAUEN_H
#define LITAUEN_H

#include <QDialog>

namespace Ui {
class Litauen;
}

class Litauen : public QDialog
{
    Q_OBJECT

public:
    explicit Litauen(QWidget *parent = nullptr);
    ~Litauen();

private:
    Ui::Litauen *ui;
};

#endif // LITAUEN_H
