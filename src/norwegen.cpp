#include "norwegen.h"
#include "ui_norwegen.h"

Norwegen::Norwegen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Norwegen)
{
    ui->setupUi(this);
}

Norwegen::~Norwegen()
{
    delete ui;
}
