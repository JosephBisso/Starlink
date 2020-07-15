#include "daenemark.h"
#include "ui_daenemark.h"

Daenemark::Daenemark(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Daenemark)
{
    ui->setupUi(this);
}

Daenemark::~Daenemark()
{
    delete ui;
}
