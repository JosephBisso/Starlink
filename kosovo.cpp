#include "kosovo.h"
#include "ui_kosovo.h"

Kosovo::Kosovo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Kosovo)
{
    ui->setupUi(this);
}

Kosovo::~Kosovo()
{
    delete ui;
}
