#ifndef LETTLAND_H
#define LETTLAND_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Lettland;
}

class Lettland : public QDialog
{
    Q_OBJECT

public:
    explicit Lettland(QWidget *parent = nullptr);
    ~Lettland();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Lettland *ui;
};

#endif // LETTLAND_H
