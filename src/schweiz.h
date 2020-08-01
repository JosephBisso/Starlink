#ifndef SCHWEIZ_H
#define SCHWEIZ_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Schweiz;
}

class Schweiz : public QDialog
{
    Q_OBJECT

public:
    explicit Schweiz(QWidget *parent = nullptr);
    ~Schweiz();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Schweiz *ui;
};

#endif // SCHWEIZ_H
