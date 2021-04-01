#ifndef LAND_H
#define LAND_H

#include <QDialog>

namespace Ui {
class Land;
}

class Land : public QDialog
{
    Q_OBJECT

public:
    explicit Land(QWidget *parent = nullptr);
    ~Land();

private:
    Ui::Land *ui;
};

#endif // LAND_H
