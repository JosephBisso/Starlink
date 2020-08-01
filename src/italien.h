#ifndef ITALIEN_H
#define ITALIEN_H

#include <QDialog>

#include <QAbstractButton>

namespace Ui {
class Italien;
}

class Italien : public QDialog
{
    Q_OBJECT

public:
    explicit Italien(QWidget *parent = nullptr);
    ~Italien();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Italien *ui;
};

#endif // ITALIEN_H
