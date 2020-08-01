#ifndef DAENEMARK_H
#define DAENEMARK_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Daenemark;
}

class Daenemark : public QDialog
{
    Q_OBJECT

public:
    explicit Daenemark(QWidget *parent = nullptr);
    ~Daenemark();

private slots:

void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Daenemark *ui;
};

#endif // DAENEMARK_H
