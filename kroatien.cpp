#include "kroatien.h"
#include "ui_kroatien.h"

Kroatien::Kroatien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Kroatien)
{
    ui->setupUi(this);
}

Kroatien::~Kroatien()
{
    delete ui;
}
