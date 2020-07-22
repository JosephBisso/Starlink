#include "daenemark.h"
#include "ui_daenemark.h"
#include <QtCharts>

#include "laender.h" // nicht vergessen!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include "databank.h" //nicht vergessen !!!!!!!!!!!!!!!!


Daenemark::Daenemark(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Daenemark)
{
    ui->setupUi(this);

    //SEHR WICHTIG!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //Liste von geoID von jedem EU-Land in den Ressource Datei / lib
    QString geoID = "DK";


    // Für Klemmens: Ab hier Copy/Paste
    Laender Land; //ein Element der Klasse Laender erstellen.


    /*Es werden nacheinander ein Attribut vom Typ databank der Klasse Laender "DbLandDaten" und eine Methode
      von der Klasse databank "gibGesamtInfizierte (Monat, geoID)" mit RückgabeTyp int gerufen
    */

    double InfiJa = Land.DbLandDaten.gibGesamtInfizierte("01", geoID); // Gesamt Infiziierte für Januar ("01")
    double InfiFe = Land.DbLandDaten.gibGesamtInfizierte("02", geoID); // Gesamt Infiziierte für ...
    double InfiMa = Land.DbLandDaten.gibGesamtInfizierte("03", geoID); // Gesamt ...
    double InfiAp = Land.DbLandDaten.gibGesamtInfizierte("04", geoID); // ...
    double InfMai = Land.DbLandDaten.gibGesamtInfizierte("05", geoID); //

    double TodeJa = Land.DbLandDaten.gibGesamtTode("01", geoID); //...
    double TodeFe = Land.DbLandDaten.gibGesamtTode("02", geoID);
    double TodeMa = Land.DbLandDaten.gibGesamtTode("03", geoID);
    double TodeAp = Land.DbLandDaten.gibGesamtTode("04", geoID);
    double TodeMai = Land.DbLandDaten.gibGesamtTode("05", geoID);



    QBarSet *set0 = new QBarSet("Inf"); // Einstellung der Legende
    QBarSet *set1 = new QBarSet("Tode");

                                                               //Variabel werden addiert
    *set0 << InfiJa << InfiFe << InfiMa << InfiAp << InfMai << InfiJa + InfiFe + InfiMa + InfiAp + InfiMa ;
    *set1 << TodeJa << TodeFe << TodeMa << TodeAp << TodeMai << TodeJa + TodeFe + TodeMa + TodeAp + TodeMa;



    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Covisualizer");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Gesamt";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,12000);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout_2->addWidget(chartView);
}

Daenemark::~Daenemark()
{
    delete ui;
}
