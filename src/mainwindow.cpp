#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QNetworkAccessManager>
#include <QtNetwork>
#include <QUrl>
#include <QObject>
#include <QFile>

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

