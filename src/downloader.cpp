#include "downloader.h"

//Die Downloader-Klasse �bernimmt die Aktualisierung der Rohdaten, indem sie von einem Webserver eine JSON-Datei
//herunterl�dt und in das Programmverzeichnis speichert. Die Ausf�hrung erfolgt �ber den Slot
//"updateRawData". Au�erdem kann die URL �ber die Methode "changeURL" angepasst werden.
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

//�ndern der URL (Datenquelle). Methode �bernimmt neue URL als Zeiger.
void Downloader::changeURL(QUrl *newURL)
{
    fileURL = newURL;
    return;
}

//Public Slot / Funktion zum Initialisieren des Downloads.
// - definiert die URL, mit der Request durchgef�hrt werden soll
// - definiert den Dateinamen bzw. die Speicheradresse der Datei
void Downloader::updateRawData()
{
    QString fileName = "/covidRaw.json";
    fileName.prepend(QDir::currentPath());
            //= "C:/Users/david/Desktop/CovisualizerBuild/covidRaw.json"

    if(!fileURL){               //Schleife pr�ft, ob der User die URL ge�ndert hat.
        fileURL = &defaultURL;
    }

    getFile(fileURL,fileName);
}

//Methode �bernimmt den Zeiger f�r die URL und den Dateipfad/Dateinamen und startet den eigentlichen Get-Request, indem
//ein QNetworkRequest-Objekt und ein Reply-Objekt initialisiert werden.
//Zus�tzlich wird File-Objekt erzeugt, �ber das die Reply als Datei gespeichert werden kann.
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
        };
    }
}
//Dieser Slot wird aufgerufen sobald, neue Daten zum Schreiben vorhanden sind, was durch das NetworkReply-Objekt �ber
//das Signal "ready read" angezeigt wird. Die Methode �berschreibt alle verf�gbaren Daten in das QFile-Objekt
void Downloader::onReadyRead()
{
    qDebug() << "Ready";
    file->open(QIODevice::WriteOnly);
    file->write(reply->readAll());

}

//Wenn das Finished-Signal von Reply-Objekt ausgegeben wird, schlie�t diese Methode die zum Schreiben ge�ffnete Datei.
//Damit ist der Download erfolgreich abgeschlossen und das Signal "updateSuccessful" wird emittiert.
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
