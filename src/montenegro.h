#ifndef MONTENEGRO_H
#define MONTENEGRO_H

#include <QDialog>

namespace Ui {
class Montenegro;
}

class Montenegro : public QDialog
{
    Q_OBJECT

public:
    explicit Montenegro(QWidget *parent = nullptr);
    ~Montenegro();

private:
    Ui::Montenegro *ui;
};

#endif // MONTENEGRO_H
