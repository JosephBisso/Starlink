#include "serbien.h"
#include "ui_serbien.h"

Serbien::Serbien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Serbien)
{
    ui->setupUi(this);
}

Serbien::~Serbien()
{
    delete ui;
}
