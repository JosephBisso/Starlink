#ifndef DEUTSCHLAND_H
#define DEUTSCHLAND_H

#include <QDialog>

#include <QAbstractButton>

namespace Ui {
class Deutschland;
}

class Deutschland : public QDialog
{
    Q_OBJECT

public:
    explicit Deutschland(QWidget *parent = nullptr);
    ~Deutschland();

private slots:

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Deutschland *ui;
};

#endif // DEUTSCHLAND_H
