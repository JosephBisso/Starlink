#include "oesterreich.h"
#include "ui_oesterreich.h"
#include "laender.h"
#include "databank.h"
#include <QtCharts>

Oesterreich::Oesterreich(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Oesterreich)
{
    ui->setupUi(this);

    //SEHR WICHTIG!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //Liste von geoID von jedem EU-Land in den Ressource Datei / lib
    QString geoID = "AT";

    // Für Klemmens: Ab hier Copy/Paste
    Laender Land; //ein Element der Klasse Laender erstellen.

    double InfiMonat[12],
           TodeMonat[12];

    for (int i=0; i<13; i++)
    {
        InfiMonat[i] = Land.InfiMonat(geoID)[i];
        TodeMonat[i] = Land.TodeMonat(geoID)[i];
    }

    QBarSet *set0 = new QBarSet("Infizierte");
    QBarSet *set1 = new QBarSet("Tode");// Einstellung der Legende in Inf(Infizierte) und Tode


    *set0 << InfiMonat[0] << InfiMonat[1] << InfiMonat[2] << InfiMonat[3]
            << InfiMonat[4] << InfiMonat[5] << InfiMonat[6] << InfiMonat[7]
            << InfiMonat[8] << InfiMonat[9] << InfiMonat[10] << InfiMonat[11] ;

    *set1 << TodeMonat[0] << TodeMonat[1] << TodeMonat[2] << TodeMonat[3]
            << TodeMonat[4] << TodeMonat[5] << TodeMonat[6] << TodeMonat[7]
            << TodeMonat[8] << TodeMonat[9] << TodeMonat[10] << TodeMonat[11] ;

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

Oesterreich::~Oesterreich()
{
    delete ui;
}

void Oesterreich::on_buttonBox_clicked(QAbstractButton *button)
{
    button->isChecked();

    qDebug ("ApplyChange Starts...");

    QString geoID = "AT";
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
