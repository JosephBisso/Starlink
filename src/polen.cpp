#include "polen.h"
#include "ui_polen.h"

Polen::Polen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Polen)
{
    ui->setupUi(this);
}

Polen::~Polen()
{
    delete ui;
}
