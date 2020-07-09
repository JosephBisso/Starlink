#include "tschechien.h"
#include "ui_tschechien.h"

Tschechien::Tschechien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tschechien)
{
    ui->setupUi(this);
}

Tschechien::~Tschechien()
{
    delete ui;
}
