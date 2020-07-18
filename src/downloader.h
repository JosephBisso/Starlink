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
    void getFile(QUrl fileURL, QString fileName);

private:
    QFile *openFileForWrite(const QString &fileName);

    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QFile *file;

//signals:
//    void updateSuccess();

//public slots:
//    void updateRawData();

private slots:
    void onDownloadProgress(qint64,qint64);
    void onFinished(QNetworkReply*);
    void onReadyRead();
    void onReplyFinished();
};

#endif // DOWNLOADER_H
