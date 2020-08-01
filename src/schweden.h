#ifndef SCHWEDEN_H
#define SCHWEDEN_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Schweden;
}

class Schweden : public QDialog
{
    Q_OBJECT

public:
    explicit Schweden(QWidget *parent = nullptr);
    ~Schweden();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Schweden *ui;
};

#endif // SCHWEDEN_H
