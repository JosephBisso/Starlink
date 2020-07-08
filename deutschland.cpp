#include "deutschland.h"
#include "ui_deutschland.h"

Deutschland::Deutschland(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Deutschland)
{
    ui->setupUi(this);
}

Deutschland::~Deutschland()
{
    delete ui;
}
