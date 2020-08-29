#ifndef CHANGEURL_H
#define CHANGEURL_H

#include <QDialog>

namespace Ui {
class changeurl;
}

class changeurl : public QDialog
{
    Q_OBJECT

public:
    explicit changeurl(QWidget *parent = nullptr);
    ~changeurl();

private:
    Ui::changeurl *ui;
};

#endif // CHANGEURL_H
