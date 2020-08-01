#ifndef KROATIEN_H
#define KROATIEN_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Kroatien;
}

class Kroatien : public QDialog
{
    Q_OBJECT

public:
    explicit Kroatien(QWidget *parent = nullptr);
    ~Kroatien();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Kroatien *ui;
};

#endif // KROATIEN_H
