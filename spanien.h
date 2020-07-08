#ifndef SPANIEN_H
#define SPANIEN_H

#include <QDialog>

namespace Ui {
class Spanien;
}

class Spanien : public QDialog
{
    Q_OBJECT

public:
    explicit Spanien(QWidget *parent = nullptr);
    ~Spanien();

private:
    Ui::Spanien *ui;
};

#endif // SPANIEN_H
