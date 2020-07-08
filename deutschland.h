#ifndef DEUTSCHLAND_H
#define DEUTSCHLAND_H

#include <QDialog>

namespace Ui {
class Deutschland;
}

class Deutschland : public QDialog
{
    Q_OBJECT

public:
    explicit Deutschland(QWidget *parent = nullptr);
    ~Deutschland();

private:
    Ui::Deutschland *ui;
};

#endif // DEUTSCHLAND_H
