#include "italien.h"
#include "ui_italien.h"

Italien::Italien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Italien)
{
    ui->setupUi(this);
}

Italien::~Italien()
{
    delete ui;
}
