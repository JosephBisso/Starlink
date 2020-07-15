#include "island.h"
#include "ui_island.h"

Island::Island(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Island)
{
    ui->setupUi(this);
}

Island::~Island()
{
    delete ui;
}
