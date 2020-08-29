#ifndef URLCHANGE_H
#define URLCHANGE_H

#include <QDialog>

namespace Ui {
class urlchange;
}

class urlchange : public QDialog
{
    Q_OBJECT

public:
    explicit urlchange(QWidget *parent = nullptr);
    ~urlchange();

private:
    Ui::urlchange *ui;
};

#endif // URLCHANGE_H
