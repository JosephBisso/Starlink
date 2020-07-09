#include "slowenien.h"
#include "ui_slowenien.h"

Slowenien::Slowenien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Slowenien)
{
    ui->setupUi(this);
}

Slowenien::~Slowenien()
{
    delete ui;
}
