#include "oesterreich.h"
#include "ui_oesterreich.h"

Oesterreich::Oesterreich(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Oesterreich)
{
    ui->setupUi(this);
}

Oesterreich::~Oesterreich()
{
    delete ui;
}
