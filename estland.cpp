#include "estland.h"
#include "ui_estland.h"

Estland::Estland(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Estland)
{
    ui->setupUi(this);
}

Estland::~Estland()
{
    delete ui;
}
