#ifndef SLOWAKEI_H
#define SLOWAKEI_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Slowakei;
}

class Slowakei : public QDialog
{
    Q_OBJECT

public:
    explicit Slowakei(QWidget *parent = nullptr);
    ~Slowakei();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Slowakei *ui;
};

#endif // SLOWAKEI_H
