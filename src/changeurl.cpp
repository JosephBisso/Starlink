#include "changeurl.h"
#include "ui_changeurl.h"

changeurl::changeurl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changeurl)
{
    ui->setupUi(this);
}

changeurl::~changeurl()
{
    delete ui;
}
