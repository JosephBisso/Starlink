#include "rumanien.h"
#include "ui_rumanien.h"

Rumanien::Rumanien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rumanien)
{
    ui->setupUi(this);
}

Rumanien::~Rumanien()
{
    delete ui;
}
