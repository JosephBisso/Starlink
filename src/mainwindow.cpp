#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "datenbank.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//...
void MainWindow::on_actionDatenbank_triggered()
{
    Datenbank* datenbank = new Datenbank(this);
            datenbank->show();
}
