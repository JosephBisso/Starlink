#ifndef KOSOVO_H
#define KOSOVO_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Kosovo;
}

class Kosovo : public QDialog
{
    Q_OBJECT

public:
    explicit Kosovo(QWidget *parent = nullptr);
    ~Kosovo();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Kosovo *ui;
};

#endif // KOSOVO_H
