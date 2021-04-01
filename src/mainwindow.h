#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QNetworkAccessManager>
#include <QUrl>

#include "datenbank.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    databank dbMain;

    Ui::MainWindow *ui;

    QNetworkAccessManager myDownloader;
    QDateTime upDate;

signals:
    void refreshButton_clicked();

private slots:
    void on_actionDatenbank_triggered();

    void on_actionNew_Windows_triggered();

    void on_actionDatenquelle_aendern_triggered();

    void on_Frankreich_clicked();

    void on_Deutschland_clicked();

    void on_Spanien_clicked();

    void on_Portugal_clicked();

    void on_Belgien_clicked();

    void on_Niederlande_clicked();

    void on_Schweiz_clicked();

    void on_Oesterreich_clicked();

    void on_Grossbritannien_clicked();

    void on_Irland_clicked();

    void on_Island_clicked();

    void on_Polen_clicked();

    void on_Tschechien_clicked();

    void on_Slowakei_clicked();

    void on_Ungarn_clicked();

    void on_Italien_clicked();

    void on_Slowenien_clicked();

    void on_Kroatien_clicked();

    void on_Montenegro_clicked();

    void on_Kosovo_clicked();

    void on_Serbien_clicked();

    void on_Rumanien_clicked();

    void on_Albanien_clicked();

    void on_Mazedonien_clicked();

    void on_Bulgarien_clicked();

    void on_Griechenland_clicked();

    void on_Moldawien_clicked();

    void on_Ukraine_clicked();

    void on_Weissrussland_clicked();

    void on_Daenemark_clicked();

    void on_Norwegen_clicked();

    void on_Schweden_clicked();

    void on_Finnland_clicked();

    void on_Estland_clicked();

    void on_Lettland_clicked();

    void on_Litauen_clicked();

    void on_refreshButton_clicked();

    void on_Bosnien_clicked();

public slots:
    void dataUpdateConfirmed();

private:

};
#endif // MAINWINDOW_H
