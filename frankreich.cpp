#include "frankreich.h"
#include "ui_frankreich.h"

Frankreich::Frankreich(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Frankreich)
{
    ui->setupUi(this);
}

Frankreich::~Frankreich()
{
    delete ui;
}
