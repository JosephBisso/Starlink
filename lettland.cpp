#include "lettland.h"
#include "ui_lettland.h"

Lettland::Lettland(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lettland)
{
    ui->setupUi(this);
}

Lettland::~Lettland()
{
    delete ui;
}
