#include "ungarn.h"
#include "ui_ungarn.h"

Ungarn::Ungarn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ungarn)
{
    ui->setupUi(this);
}

Ungarn::~Ungarn()
{
    delete ui;
}
