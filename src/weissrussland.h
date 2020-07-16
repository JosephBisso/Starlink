#ifndef WEISSRUSSLAND_H
#define WEISSRUSSLAND_H

#include <QDialog>

namespace Ui {
class Weissrussland;
}

class Weissrussland : public QDialog
{
    Q_OBJECT

public:
    explicit Weissrussland(QWidget *parent = nullptr);
    ~Weissrussland();

private:
    Ui::Weissrussland *ui;
};

#endif // WEISSRUSSLAND_H
