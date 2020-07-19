#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mydialog.h"
#include <QObject>
#include <QNetworkAccessManager>
#include <QUrl>

#include "datenbank.h"
#include "frankreich.h"
#include "deutschland.h"
#include "spanien.h"
#include "portugal.h"
#include "andorra.h"
#include "belgien.h"
#include "niederlande.h"
#include "schweiz.h"
#include "oesterreich.h"
#include "grossbritannien.h"
#include "irland.h"
#include "island.h"
#include "polen.h"
#include "tschechien.h"
#include "slowakei.h"
#include "ungarn.h"
#include "italien.h"
#include "slowenien.h"
#include "kroatien.h"
#include "montenegro.h"
#include "kosovo.h"
#include "serbien.h"
#include "rumanien.h"
#include "albanien.h"
#include "mazedonien.h"
#include "bulgarien.h"
#include "griechenland.h"
#include "moldawien.h"
#include "ukraine.h"
#include "weissrussland.h"
#include "daenemark.h"
#include "norwegen.h"
#include "schweden.h"
#include "finnland.h"
#include "estland.h"
#include "lettland.h"
#include "litauen.h"


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
    databank dbMain;

    Ui::MainWindow *ui;
    MyDialog *mDialog;

signals:
    void refreshButton_clicked();

private slots:
    void on_actionDatenbank_triggered();

    void on_actionNew_Windows_triggered();

    void on_Frankreich_clicked();

    void on_Deutschland_clicked();

    void on_Spanien_clicked();

    void on_Portugal_clicked();

    void on_Andorra_clicked();

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

private:

};
#endif // MAINWINDOW_H
