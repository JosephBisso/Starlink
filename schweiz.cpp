#include "schweiz.h"
#include "ui_schweiz.h"

Schweiz::Schweiz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Schweiz)
{
    ui->setupUi(this);
}

Schweiz::~Schweiz()
{
    delete ui;
}
