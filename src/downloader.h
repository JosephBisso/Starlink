#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QWidget>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QDir>
#include <QtDebug>
#include <QMessageBox>


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
    QUrl defaultURL = QUrl("https://opendata.ecdc.europa.eu/covid19/casedistribution/json");
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
