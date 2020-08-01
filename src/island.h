#ifndef ISLAND_H
#define ISLAND_H

#include <QDialog>

#include <QAbstractButton>

namespace Ui {
class Island;
}

class Island : public QDialog
{
    Q_OBJECT

public:
    explicit Island(QWidget *parent = nullptr);
    ~Island();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Island *ui;
};

#endif // ISLAND_H
