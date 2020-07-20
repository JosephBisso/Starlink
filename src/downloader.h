#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QWidget>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QStringList>
#include <QDir>
#include <QtDebug>


class Downloader : public QWidget
{
    Q_OBJECT
public:
    explicit Downloader(QWidget *parent = 0);
    virtual ~Downloader();
    void changeURL(QUrl *newURL);
    void updateRawData();

private:
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QFile* file;
    const QString fileName = "covidRaw.json";
    QUrl defaultURL = QUrl("https://data.europa.eu/euodp/en/data/dataset/covid-19-coronavirus-data/resource/ce379c1d-066a-4de8-a195-1d5e8338142a");
    QUrl* fileURL = nullptr;
    QUrl* userURL = nullptr;
    void getFile(QUrl* fileURL, const QString fileName);

    QString debugTestString;

signals:
    void updateSuccessful();
    void updateFailed();

private slots:
    void onDownloadProgress(qint64,qint64);
    void onFinished(QNetworkReply*);
    void onReadyRead();
    void onReplyFinished();
};

#endif // DOWNLOADER_H
