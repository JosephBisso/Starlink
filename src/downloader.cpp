#include "downloader.h"

Downloader::Downloader(QWidget *parent) :
    QWidget(parent)
{

    manager = new QNetworkAccessManager;

    QUrl defaultURL = QUrl("https://data.europa.eu/euodp/en/data/dataset/covid-19-coronavirus-data/resource/ce379c1d-066a-4de8-a195-1d5e8338142a");

}

Downloader::~Downloader()
{
    manager->deleteLater();
}

void Downloader::changeURL(QUrl *newURL)
{
    fileURL = newURL;
    return;
}

void Downloader::updateRawData()
{
    QString fileName = "/covidRaw.json";
    fileName.prepend(QDir::currentPath());
            //= "C:/Users/david/Desktop/CovisualizerBuild/covidRaw.json";

    if(!fileURL){
        fileURL = &defaultURL;
    }

    getFile(fileURL,fileName);
}

void Downloader::getFile(QUrl *fileURL, QString fileName)
{
    QNetworkRequest request;
    request.setUrl(*fileURL);
    reply = manager->get(request);

    file = new QFile;
    file->setFileName(fileName);

    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(onDownloadProgress(qint64,qint64)));
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(onFinished(QNetworkReply*)));
    connect(reply,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    connect(reply,SIGNAL(finished()),this,SLOT(onReplyFinished()));
}

void Downloader::onDownloadProgress(qint64 bytesRead,qint64 bytesTotal)
{
    qDebug() << bytesRead << " - " << bytesTotal;
}

void Downloader::onFinished(QNetworkReply *reply)
{
    switch(reply->error())
    {
        case QNetworkReply::NoError:
        {
            qDebug("file is downloaded successfully.");
        }break;
        default:{
            qDebug() << reply->errorString();
        };
    }

    if(file->isOpen()){      // Redundant, weil in onReplyFinished vorhanden
        file->close();
        file->deleteLater();
    }
}

void Downloader::onReadyRead()
{
    qDebug() << "Ready";
    file->open(QIODevice::WriteOnly);
    file->write(reply->readAll());

}

void Downloader::onReplyFinished()
{
    if(file->isOpen()){
        file->close();
        file->deleteLater();
    }

    if (!reply->error()){
        emit updateSuccessful();
    }
}
