﻿#include "downloader.h"

//Die Downloader-Klasse übernimmt die Aktualisierung der Rohdaten, indem sie von einem Webserver eine JSON-Datei
//herunterlädt und in das Programmverzeichnis speichert. Die Ausführung erfolgt über den Slot
//"updateRawData". Außerdem kann die URL über die Methode "changeURL" angepasst werden.
Downloader::Downloader(QWidget *parent) :
    QWidget(parent)
{
    manager = new QNetworkAccessManager;
}

Downloader::~Downloader()
{
    manager->deleteLater();
}

//Ändern der URL (Datenquelle). Methode übernimmt neue URL als Zeiger.
void Downloader::changeURL(QUrl *newURL)
{
    fileURL = newURL;
}

//Public Slot / Funktion zum Initialisieren des Downloads.
// - definiert die URL, mit der Request durchgeführt werden soll
// - definiert den Dateinamen bzw. die Speicheradresse der Datei
void Downloader::updateRawData()
{
    if(!fileURL){               //Schleife prüft, ob der User die URL geändert hat.
        fileURL = &defaultURL;  // ansonsten wird der Default verwendet.
    }

    getFile(fileURL,fileName);
}

//Methode übernimmt den Zeiger für die URL und den Dateipfad/Dateinamen und startet den eigentlichen Get-Request, indem
//ein QNetworkRequest-Objekt und ein Reply-Objekt initialisiert werden.
//Zusätzlich wird File-Objekt erzeugt, über das die Reply als Datei gespeichert werden kann.
void Downloader::getFile(QUrl* fileURL, QString fileName)
{
    QNetworkRequest request;
    request.setUrl(*fileURL);
    request.setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);
    reply = manager->get(request);

    file = new QFile;
    file->setFileName(fileName);


    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(onDownloadProgress(qint64,qint64)));
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(onFinished(QNetworkReply*)));
    connect(reply,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    connect(reply,SIGNAL(finished()),this,SLOT(onReplyFinished()));
}

//Methode zum Debugging, die den Download-Fortschritt ausgibt.
void Downloader::onDownloadProgress(qint64 bytesRead,qint64 bytesTotal)
{
    qDebug() << bytesRead << " - " << bytesTotal;
}

//Methode zum Debugging, die bei auf das finish-Signal des Managers den Status/Fehler der Reply ausgibt.
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
            QMessageBox msgBox;
            msgBox.setText("Fehler beim Herunterladen der Daten");
            msgBox.setInformativeText(reply->errorString());
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.exec();
        };
    }
}
//Dieser Slot wird aufgerufen sobald, neue Daten zum Schreiben vorhanden sind, was durch das NetworkReply-Objekt über
//das Signal "ready read" angezeigt wird. Die Methode überschreibt alle verfügbaren Daten in das QFile-Objekt
void Downloader::onReadyRead()
{
    qDebug() << "Ready";

    if (!file->isOpen()) {
        file->open(QIODevice::WriteOnly);
    }
    file->write(reply->readAll());


}

//Wenn das Finished-Signal vom Reply-Objekt ausgegeben wird, schließt diese Methode die zum Schreiben geöffnete Datei.
//Damit ist der Download erfolgreich abgeschlossen und das Signal "updateSuccessful" wird emittiert.
void Downloader::onReplyFinished()
{
    if(file->error()>0){
        QMessageBox msgBox;
        msgBox.setText("Fehler beim Speichern der Daten");
        msgBox.setInformativeText(file->errorString());
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
    }

    if (!reply->error() && !file->error()){
        emit updateSuccessful();
    }

    if(file->isOpen()){
        file->close();
        file->deleteLater();
    }
}
