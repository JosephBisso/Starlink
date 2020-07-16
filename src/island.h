#ifndef ISLAND_H
#define ISLAND_H

#include <QDialog>

namespace Ui {
class Island;
}

class Island : public QDialog
{
    Q_OBJECT

public:
    explicit Island(QWidget *parent = nullptr);
    ~Island();

private:
    Ui::Island *ui;
};

#endif // ISLAND_H
