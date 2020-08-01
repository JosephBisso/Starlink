#ifndef BULGARIEN_H
#define BULGARIEN_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Bulgarien;
}

class Bulgarien : public QDialog
{
    Q_OBJECT

public:
    explicit Bulgarien(QWidget *parent = nullptr);
    ~Bulgarien();

private slots:

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Bulgarien *ui;
};

#endif // BULGARIEN_H
