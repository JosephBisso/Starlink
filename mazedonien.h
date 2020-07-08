#ifndef MAZEDONIEN_H
#define MAZEDONIEN_H

#include <QDialog>

namespace Ui {
class Mazedonien;
}

class Mazedonien : public QDialog
{
    Q_OBJECT

public:
    explicit Mazedonien(QWidget *parent = nullptr);
    ~Mazedonien();

private:
    Ui::Mazedonien *ui;
};

#endif // MAZEDONIEN_H
