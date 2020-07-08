#ifndef FRANKREICH_H
#define FRANKREICH_H

#include <QDialog>

namespace Ui {
class Frankreich;
}

class Frankreich : public QDialog
{
    Q_OBJECT

public:
    explicit Frankreich(QWidget *parent = nullptr);
    ~Frankreich();

private:
    Ui::Frankreich *ui;
};

#endif // FRANKREICH_H
