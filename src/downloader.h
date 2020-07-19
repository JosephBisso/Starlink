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

private:
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QFile *file;
    QString fileName;
    QUrl defaultURL;
    QUrl *fileURL = nullptr;
    QUrl *userURL = nullptr;
    void getFile(QUrl *fileURL, const QString fileName);

signals:
    void updateSuccessful();
    void updateFailed();

public slots:
    void updateRawData();

private slots:
    void onDownloadProgress(qint64,qint64);
    void onFinished(QNetworkReply*);
    void onReadyRead();
    void onReplyFinished();
};

#endif // DOWNLOADER_H
