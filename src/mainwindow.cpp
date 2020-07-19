#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "downloader.h"

#include <QNetworkAccessManager>
#include <QtNetwork>
#include <QUrl>
#include <QObject>
#include <QFile>
#include <QObject>
#include <QWidget>

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

