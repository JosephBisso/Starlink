#ifndef POLEN_H
#define POLEN_H

#include <QDialog>

namespace Ui {
class Polen;
}

class Polen : public QDialog
{
    Q_OBJECT

public:
    explicit Polen(QWidget *parent = nullptr);
    ~Polen();

private:
    Ui::Polen *ui;
};

#endif // POLEN_H
