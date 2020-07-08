#include "portugal.h"
#include "ui_portugal.h"

Portugal::Portugal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Portugal)
{
    ui->setupUi(this);
}

Portugal::~Portugal()
{
    delete ui;
}
