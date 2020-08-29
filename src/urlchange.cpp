#include "urlchange.h"
#include "ui_urlchange.h"

urlchange::urlchange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::urlchange)
{
    ui->setupUi(this);
}

urlchange::~urlchange()
{
    delete ui;
}
