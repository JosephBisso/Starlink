#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QNetworkAccessManager>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow :  public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void startRequest(const QUrl requestedUrl);
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QNetworkReply *reply = NULL;
    void saveFile(QString*);

    QString defaultFileName;
    QUrl userUrl;

signals:
    void refreshButtonClicked();
};
#endif // MAINWINDOW_H
