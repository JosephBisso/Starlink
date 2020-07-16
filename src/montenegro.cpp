#include "montenegro.h"
#include "ui_montenegro.h"

Montenegro::Montenegro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Montenegro)
{
    ui->setupUi(this);
}

Montenegro::~Montenegro()
{
    delete ui;
}
