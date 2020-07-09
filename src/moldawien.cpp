#include "moldawien.h"
#include "ui_moldawien.h"

Moldawien::Moldawien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Moldawien)
{
    ui->setupUi(this);
}

Moldawien::~Moldawien()
{
    delete ui;
}
