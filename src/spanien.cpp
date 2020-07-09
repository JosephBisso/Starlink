#include "spanien.h"
#include "ui_spanien.h"

Spanien::Spanien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Spanien)
{
    ui->setupUi(this);
}

Spanien::~Spanien()
{
    delete ui;
}
