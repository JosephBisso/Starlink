#include "albanien.h"
#include "ui_albanien.h"

Albanien::Albanien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Albanien)
{
    ui->setupUi(this);
}

Albanien::~Albanien()
{
    delete ui;
}
