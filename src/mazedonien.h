#ifndef MAZEDONIEN_H
#define MAZEDONIEN_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Mazedonien;
}

class Mazedonien : public QDialog
{
    Q_OBJECT

public:
    explicit Mazedonien(QWidget *parent = nullptr);
    ~Mazedonien();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Mazedonien *ui;
};

#endif // MAZEDONIEN_H
