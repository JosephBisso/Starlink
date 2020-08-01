#ifndef SERBIEN_H
#define SERBIEN_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Serbien;
}

class Serbien : public QDialog
{
    Q_OBJECT

public:
    explicit Serbien(QWidget *parent = nullptr);
    ~Serbien();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Serbien *ui;
};

#endif // SERBIEN_H
