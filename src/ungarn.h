#ifndef UNGARN_H
#define UNGARN_H

#include <QDialog>

namespace Ui {
class Ungarn;
}

class Ungarn : public QDialog
{
    Q_OBJECT

public:
    explicit Ungarn(QWidget *parent = nullptr);
    ~Ungarn();

private:
    Ui::Ungarn *ui;
};

#endif // UNGARN_H