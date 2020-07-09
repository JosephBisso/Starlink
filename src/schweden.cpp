#include "schweden.h"
#include "ui_schweden.h"

Schweden::Schweden(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Schweden)
{
    ui->setupUi(this);
}

Schweden::~Schweden()
{
    delete ui;
}
