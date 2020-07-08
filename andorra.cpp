#include "andorra.h"
#include "ui_andorra.h"

Andorra::Andorra(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Andorra)
{
    ui->setupUi(this);
}

Andorra::~Andorra()
{
    delete ui;
}
