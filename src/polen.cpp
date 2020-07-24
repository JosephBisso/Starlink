#include "polen.h"
#include "ui_polen.h"
#include "laender.h"
#include "databank.h"
#include <QtCharts>

Polen::Polen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Polen)
{
    ui->setupUi(this);

    //SEHR WICHTIG!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //Liste von geoID von jedem EU-Land in den Ressource Datei / lib
    QString geoID = "PL";

    // Für Klemmens: Ab hier Copy/Paste
    Laender Land; //ein Element der Klasse Laender erstellen.

    /*Es werden nacheinander ein Attribut vom Typ databank der Klasse Laender "DbLandDaten" und eine Methode
      von der Klasse databank "gibGesamtInfizierte (Monat, geoID)" mit RückgabeTyp int gerufen
    */

    double InfJa = Land.DbLandDaten.gibGesamtInfizierte("01", geoID); // Gesamt Infiziierte für Januar ("01")
    double InfFe = Land.DbLandDaten.gibGesamtInfizierte("02", geoID); // Gesamt Infiziierte für ...
    double InfMa = Land.DbLandDaten.gibGesamtInfizierte("03", geoID); // Gesamt ...
    double InfAp = Land.DbLandDaten.gibGesamtInfizierte("04", geoID); // ...
    double InfMai = Land.DbLandDaten.gibGesamtInfizierte("05", geoID); //
    double InfJun = Land.DbLandDaten.gibGesamtInfizierte("06", geoID);
    double InfJuli = Land.DbLandDaten.gibGesamtInfizierte("07", geoID);
    double InfAug = Land.DbLandDaten.gibGesamtInfizierte("08", geoID);
    double InfSep = Land.DbLandDaten.gibGesamtInfizierte("09", geoID);
    double InfOkt = Land.DbLandDaten.gibGesamtInfizierte("10", geoID);
    double InfNov = Land.DbLandDaten.gibGesamtInfizierte("11", geoID);
    double InfDez = Land.DbLandDaten.gibGesamtInfizierte("12", geoID);

    double TodeJa = Land.DbLandDaten.gibGesamtTode("01", geoID); //...
    double TodeFe = Land.DbLandDaten.gibGesamtTode("02", geoID);
    double TodeMa = Land.DbLandDaten.gibGesamtTode("03", geoID);
    double TodeAp = Land.DbLandDaten.gibGesamtTode("04", geoID);
    double TodeMai = Land.DbLandDaten.gibGesamtTode("05", geoID);
    double TodeJun = Land.DbLandDaten.gibGesamtTode("06", geoID);
    double TodeJuli = Land.DbLandDaten.gibGesamtTode("07", geoID);
    double TodeAug = Land.DbLandDaten.gibGesamtTode("08", geoID);
    double TodeSep = Land.DbLandDaten.gibGesamtTode("09", geoID);
    double TodeOkt = Land.DbLandDaten.gibGesamtTode("10", geoID);
    double TodeNov = Land.DbLandDaten.gibGesamtTode("11", geoID);
    double TodeDez = Land.DbLandDaten.gibGesamtTode("12", geoID);



    QBarSet *set0 = new QBarSet("Infizierte");
    QBarSet *set1 = new QBarSet("Tode");// Einstellung der Legende in Inf(Infizierte) und Tode

                                                               //Variabel werden addiert
    *set0 << InfJa << InfFe << InfMa << InfAp << InfMai << InfJun << InfJuli << InfAug << InfSep << InfOkt << InfNov << InfDez ;
    *set1 << TodeJa << TodeFe << TodeMa << TodeAp << TodeMai << TodeJun << TodeJuli << TodeAug << TodeSep << TodeOkt << TodeNov << TodeDez;

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Covisualizer");
    chart->setAnimationOptions(QChart::SeriesAnimations);// Namensgebung sowie Animationseinstellung

    QStringList categories;
    categories << "Jan." << "Feb." << "März" << "April" << "Mai" << "Juni" << "Juli" << "Aug." << "Sept." << "Okt." << "Nov." << "Dez.";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX); // Umbennenung der X-Achse

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout_2->addWidget(chartView); // Initalisierung der BarChart
}

Polen::~Polen()
{
    delete ui;
}
