#include "grossbritannien.h"
#include "ui_grossbritannien.h"

Grossbritannien::Grossbritannien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Grossbritannien)
{
    ui->setupUi(this);
}

Grossbritannien::~Grossbritannien()
{
    delete ui;
}
