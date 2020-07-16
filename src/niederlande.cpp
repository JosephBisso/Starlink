#include "niederlande.h"
#include "ui_niederlande.h"

Niederlande::Niederlande(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Niederlande)
{
    ui->setupUi(this);
}

Niederlande::~Niederlande()
{
    delete ui;
}
