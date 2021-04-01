#include "land.h"
#include "ui_land.h"

Land::Land(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Land)
{
    ui->setupUi(this);
}

Land::~Land()
{
    delete ui;
}
