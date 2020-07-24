#include "deutschland.h"
#include "ui_deutschland.h"

#include <QDialog>
#include <QMessageBox>  //Dienst nur der Darstellung, damit du verstehst.

//Muss included sein!!!!!!!!!!!!!!1
#include "laender.h"
#include "databank.h" // aufpassen: datAbank und nicht datENbank
#include <QtCharts>

Deutschland::Deutschland(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Deutschland)
{
    ui->setupUi(this);

    /*
     * Beispiel Datenzugriff für Toni: Ich zeige dir, wie du auf die Daten zugreifst
     * (1) Erstmal ein Element aus der Klasse "Laender" erstellen
     * (2) Die Methode "gibLandDaten für den gewünschten "Tag" und "Monat" für ein land mit geoID "geoID"
            Liste von geoID in den Ressource Datei / lib
     * (3) Dann dich für eine der beiden unten beschrieben Vorgehensweisen entscheiden
     */

   //(1)
    Laender Land;

   //(2)
    Land.gibLandDaten("01", "04", "DE"); //Oder Land.gibLandDaten (ui->Day, ui->Month, "DE")


   //(3)

       // (3.1)     entweder direkt so "Land.DbLandDaten.Datum", "Land.DbLandDaten.Infiziierte"
                                          //fürs Datum              für Anzahl Infiziierte an dem Datum
    QMessageBox::information(this, Land.DbLandDaten.Datum , QString::number(Land.DbLandDaten.Infiziierte));

       //(3.2)
    QString Datum = Land.DbLandDaten.Datum;
    int Tode = Land.DbLandDaten.Tode;


                    //oder so; mit Datum = Land.DbLandDaten.Datum, Tode = Land.DbLandDaten.Tode;
                                            //fürs Datum                  für Anzahl von Tode an dem Datum
    QMessageBox::information(this, Datum , QString::number(Tode));

    //QMessageBox dient hier lediglich zur Darstellung, damit du verstehst was abgehst
    //(Du kannst das Programm ausführen)

    //Klemmens. Analog für die Gesammtzahlen:
   // hier beachten: Gesamst Zahlen für den Monat "Monat" im Land mit geoID "geoID"

    Land.DbLandDaten.gibGesamtInfizierte("04", "DE");

    Land.DbLandDaten.gibGesamtTode("04", "DE");

    QString geoID = "DE";

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

Deutschland::~Deutschland()
{
    delete ui;
}
