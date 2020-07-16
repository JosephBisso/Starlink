#include "dbvorschau.h"
#include "ui_dbvorschau.h"

dbVorschau::dbVorschau(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dbVorschau)
{
    ui->setupUi(this);

    VorschauFillTable();
}

dbVorschau::~dbVorschau()
{
    delete ui;
}
