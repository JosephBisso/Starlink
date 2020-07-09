#include "weissrussland.h"
#include "ui_weissrussland.h"

Weissrussland::Weissrussland(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Weissrussland)
{
    ui->setupUi(this);
}

Weissrussland::~Weissrussland()
{
    delete ui;
}
