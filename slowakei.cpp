#include "slowakei.h"
#include "ui_slowakei.h"

Slowakei::Slowakei(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Slowakei)
{
    ui->setupUi(this);
}

Slowakei::~Slowakei()
{
    delete ui;
}
