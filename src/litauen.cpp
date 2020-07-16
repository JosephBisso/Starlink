#include "litauen.h"
#include "ui_litauen.h"

Litauen::Litauen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Litauen)
{
    ui->setupUi(this);
}

Litauen::~Litauen()
{
    delete ui;
}
