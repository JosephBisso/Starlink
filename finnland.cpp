#include "finnland.h"
#include "ui_finnland.h"

Finnland::Finnland(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Finnland)
{
    ui->setupUi(this);
}

Finnland::~Finnland()
{
    delete ui;
}
