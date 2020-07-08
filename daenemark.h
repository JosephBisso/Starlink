#ifndef DAENEMARK_H
#define DAENEMARK_H

#include <QDialog>

namespace Ui {
class Daenemark;
}

class Daenemark : public QDialog
{
    Q_OBJECT

public:
    explicit Daenemark(QWidget *parent = nullptr);
    ~Daenemark();

private:
    Ui::Daenemark *ui;
};

#endif // DAENEMARK_H
