#ifndef OESTERREICH_H
#define OESTERREICH_H

#include <QDialog>

namespace Ui {
class Oesterreich;
}

class Oesterreich : public QDialog
{
    Q_OBJECT

public:
    explicit Oesterreich(QWidget *parent = nullptr);
    ~Oesterreich();

private:
    Ui::Oesterreich *ui;
};

#endif // OESTERREICH_H
