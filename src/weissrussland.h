#ifndef WEISSRUSSLAND_H
#define WEISSRUSSLAND_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Weissrussland;
}

class Weissrussland : public QDialog
{
    Q_OBJECT

public:
    explicit Weissrussland(QWidget *parent = nullptr);
    ~Weissrussland();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Weissrussland *ui;
};

#endif // WEISSRUSSLAND_H
