#include "belgien.h"
#include "ui_belgien.h"

Belgien::Belgien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Belgien)
{
    ui->setupUi(this);
}

Belgien::~Belgien()
{
    delete ui;
}
