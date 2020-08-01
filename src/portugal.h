#ifndef PORTUGAL_H
#define PORTUGAL_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Portugal;
}

class Portugal : public QDialog
{
    Q_OBJECT

public:
    explicit Portugal(QWidget *parent = nullptr);
    ~Portugal();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Portugal *ui;
};

#endif // PORTUGAL_H
