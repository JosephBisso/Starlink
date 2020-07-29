#include "deutschland.h"
#include "ui_deutschland.h"

#include <QDialog>
#include <QMessageBox>  //Dienst nur der Darstellung, damit du verstehst.

//Muss included sein!!!!!!!!!!!!!!1
#include "laender.h"
#include "databank.h" // aufpassen: datAbank und nicht datENbank
#include <QtCharts>

#include <QDebug>

Deutschland::Deutschland(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Deutschland)

{
    ui->setupUi(this);


    Laender Land;

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


void Deutschland::on_buttonBox_clicked(QAbstractButton *button)
{
    QAbstractButton* Nutzlos = button;
    Nutzlos = NULL; //Nutzlos

    qDebug ("ApplyChange Starts...");

    QString geoID = "DE";
    Laender Land;

    QDate uiDatum = ui->dateEdit->date();

    if (uiDatum>QDate::currentDate())
    {
        QMessageBox::information(this, "ungültiges Datum", "Die Daten für dieses Datum wurden nicht in der Datenbank gefunden");

    }


    qDebug() << "uiDatum = " << uiDatum;

    QString Monat = QString::number(uiDatum.month());
    if (Monat.size()==1)
    {
        Monat.insert(0, "0");      //Aus Monat im Format "m" wird Monat im Format "mm" ("06" statt "6")
    }

    qDebug() << "Monat = " << Monat;


    QString Tag = QString::number(uiDatum.day());
    if (Tag.size()==1)
    {
        Tag.insert(0, "0"); //Aus Tag im Format "d" wird Tag im Format "dd" ("1" statt "01")
    }

    qDebug() << "Tag = " << Tag;

    QString Datum = Land.DbLandDaten.gibDatum(Tag, Monat);

    qDebug() << "Datum = " << Datum;

    QString Infi = QString::number(Land.DbLandDaten.gibInfiierte(Datum, geoID));
    QString Tode = QString::number(Land.DbLandDaten.gibTode(Datum, geoID));

    qDebug() << "Infi = " << Infi << ", Tode = " << Tode ;

    ui->lineEdit_4->setText(Infi);
    ui->lineEdit_6->setText(Tode);


}
