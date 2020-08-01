#ifndef SLOWENIEN_H
#define SLOWENIEN_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Slowenien;
}

class Slowenien : public QDialog
{
    Q_OBJECT

public:
    explicit Slowenien(QWidget *parent = nullptr);
    ~Slowenien();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Slowenien *ui;
};

#endif // SLOWENIEN_H
