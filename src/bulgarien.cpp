#include "bulgarien.h"
#include "ui_bulgarien.h"

Bulgarien::Bulgarien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bulgarien)
{
    ui->setupUi(this);
}

Bulgarien::~Bulgarien()
{
    delete ui;
}
