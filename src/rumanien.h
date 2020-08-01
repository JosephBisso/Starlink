#ifndef RUMANIEN_H
#define RUMANIEN_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Rumanien;
}

class Rumanien : public QDialog
{
    Q_OBJECT

public:
    explicit Rumanien(QWidget *parent = nullptr);
    ~Rumanien();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Rumanien *ui;
};

#endif // RUMANIEN_H
