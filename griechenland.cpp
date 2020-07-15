#include "griechenland.h"
#include "ui_griechenland.h"

Griechenland::Griechenland(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Griechenland)
{
    ui->setupUi(this);
}

Griechenland::~Griechenland()
{
    delete ui;
}
