#include "irland.h"
#include "ui_irland.h"

Irland::Irland(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Irland)
{
    ui->setupUi(this);
}

Irland::~Irland()
{
    delete ui;
}
