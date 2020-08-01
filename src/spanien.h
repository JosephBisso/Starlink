#ifndef SPANIEN_H
#define SPANIEN_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Spanien;
}

class Spanien : public QDialog
{
    Q_OBJECT

public:
    explicit Spanien(QWidget *parent = nullptr);
    ~Spanien();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Spanien *ui;
};

#endif // SPANIEN_H
