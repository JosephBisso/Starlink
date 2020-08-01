#ifndef LITAUEN_H
#define LITAUEN_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Litauen;
}

class Litauen : public QDialog
{
    Q_OBJECT

public:
    explicit Litauen(QWidget *parent = nullptr);
    ~Litauen();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Litauen *ui;
};

#endif // LITAUEN_H
