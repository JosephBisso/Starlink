#ifndef UKRAINE_H
#define UKRAINE_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Ukraine;
}

class Ukraine : public QDialog
{
    Q_OBJECT

public:
    explicit Ukraine(QWidget *parent = nullptr);
    ~Ukraine();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Ukraine *ui;
};

#endif // UKRAINE_H
