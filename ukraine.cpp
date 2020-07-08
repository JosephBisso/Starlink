#include "ukraine.h"
#include "ui_ukraine.h"

Ukraine::Ukraine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ukraine)
{
    ui->setupUi(this);
}

Ukraine::~Ukraine()
{
    delete ui;
}
