#ifndef KOSOVO_H
#define KOSOVO_H

#include <QDialog>

namespace Ui {
class Kosovo;
}

class Kosovo : public QDialog
{
    Q_OBJECT

public:
    explicit Kosovo(QWidget *parent = nullptr);
    ~Kosovo();

private:
    Ui::Kosovo *ui;
};

#endif // KOSOVO_H
