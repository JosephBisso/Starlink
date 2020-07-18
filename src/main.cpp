#include "mainwindow.h"
#include <QApplication>
#include <downloader.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QString fileName = "C:/Users/david/Desktop/CovisualizerBuild/covidRaw.json";
    QUrl fileURL = QUrl("https://data.europa.eu/euodp/en/data/dataset/covid-19-coronavirus-data/resource/ce379c1d-066a-4de8-a195-1d5e8338142a");

    Downloader myDownloader;
    myDownloader.getFile(fileURL, fileName);


    return a.exec();
}
