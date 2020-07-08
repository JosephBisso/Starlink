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

    QString defaultFileName = "C:/Users/david/Desktop/TU Braunschweig/Anwendungsorientierte Programmierung für Ingos/downloaded/index.html";
    QUrl userUrl = QUrl("https://www.google.com/");

    manager = new QNetworkAccessManager();

    startRequest(userUrl);

    QObject::connect(manager, &QNetworkAccessManager::finished,
        this, [=](QNetworkReply *reply) {
            if (reply->error()) {
                qDebug() << reply->errorString();
                return;
            }

            QString answer;
            answer = reply->readAll();
            qDebug() << &answer;

            QString *ptranswer = NULL;
            saveFile(ptranswer);
        }
    );
}

void MainWindow::startRequest(QUrl requestedUrl)
{
    request.setUrl(requestedUrl);
    manager->get(request);
    return;
}

void MainWindow::saveFile(QString* answer)
{
    QString fileName = userUrl.fileName();
    if (fileName.isEmpty())
        fileName = defaultFileName;

    QFile file(fileName);
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream(&file);
        stream << *answer;
    }

    return;
}


MainWindow::~MainWindow()
{
    delete ui;
}

