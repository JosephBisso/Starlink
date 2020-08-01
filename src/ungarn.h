#ifndef UNGARN_H
#define UNGARN_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Ungarn;
}

class Ungarn : public QDialog
{
    Q_OBJECT

public:
    explicit Ungarn(QWidget *parent = nullptr);
    ~Ungarn();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Ungarn *ui;
};

#endif // UNGARN_H
