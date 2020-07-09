#include "mazedonien.h"
#include "ui_mazedonien.h"

Mazedonien::Mazedonien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mazedonien)
{
    ui->setupUi(this);
}

Mazedonien::~Mazedonien()
{
    delete ui;
}
