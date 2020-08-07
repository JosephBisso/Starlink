#include "weissrussland.h"
#include "ui_weissrussland.h"
#include "laender.h"
#include "databank.h"
#include <QtCharts>

Weissrussland::Weissrussland(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Weissrussland)
{
    ui->setupUi(this);



    ui->setupUi(this);


    double InfiMonat[12],
           TodeMonat[12];

    Land.InfiTodeMonat(geoID);

    for (int i=0; i<12; i++)
    {
        InfiMonat[i] = Land.infMonat [i];
        TodeMonat[i] = Land.todMonat [i];
    }

    QBarSet *set0 = new QBarSet("Infizierte");
    QBarSet *set1 = new QBarSet("Tode");


    *set0 << InfiMonat[0] << InfiMonat[1] << InfiMonat[2] << InfiMonat[3]
            << InfiMonat[4] << InfiMonat[5] << InfiMonat[6] << InfiMonat[7]
            << InfiMonat[8] << InfiMonat[9] << InfiMonat[10] << InfiMonat[11] ;

    *set1 << TodeMonat[0] << TodeMonat[1] << TodeMonat[2] << TodeMonat[3]
            << TodeMonat[4] << TodeMonat[5] << TodeMonat[6] << TodeMonat[7]
            << TodeMonat[8] << TodeMonat[9] << TodeMonat[10] << TodeMonat[11] ;

    QBarSeries *series = new QBarSeries(),
                *seriesTode = new QBarSeries();
    series->append(set0);
    seriesTode->append(set1);

    QChart *chart = new QChart(),
            *chartTode = new QChart();
    chart->addSeries(series);
    chart->setTitle("Covisualizer");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chartTode->addSeries(seriesTode);
    chartTode->setTitle("Covisualizer");
    chartTode->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Jan." << "Feb." << "März" << "April" << "Mai" << "Juni" << "Juli" << "Aug." << "Sept." << "Okt." << "Nov." << "Dez.";
    QBarCategoryAxis *axisX = new QBarCategoryAxis(),
                        *axisXTode = new QBarCategoryAxis();

    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    axisXTode->append(categories);
    chartTode->addAxis(axisXTode, Qt::AlignBottom);


    QValueAxis *axisY = new QValueAxis(),
                *axisYTode = new QValueAxis();

    axisY->setMin(0);
    axisYTode->setMin(0);
    chart->addAxis(axisY, Qt::AlignLeft);
    chartTode->addAxis(axisYTode, Qt::AlignLeft);
    series->attachAxis(axisY);
    seriesTode->attachAxis(axisYTode);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chartTode->legend()->setVisible(true);
    chartTode->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart),
                *chartViewTode = new QChartView(chartTode);
       chartView->setRenderHint(QPainter::Antialiasing);
       chartViewTode->setRenderHint(QPainter::Antialiasing);

    ui->verticalLayout_4->addWidget(chartView);
    ui->verticalLayout_2->addWidget(chartViewTode);
}

Weissrussland::~Weissrussland()
{
    delete ui;
}


void Weissrussland::on_buttonBox_clicked(QAbstractButton *button)
{
    button->isChecked();
    ui->progressBar->setValue(15);

    qDebug ("ApplyChange Starts...");


    QDate uiDatum = ui->dateEdit->date();

    if (uiDatum>QDate::currentDate())
    {
        ui->progressBar->setValue(100);
        QMessageBox::information(this, "ungültiges Datum", "Daten werden nur darstellt und nicht vorausgesagt.");

        ui->lineEdit_4->setText("");
        ui->lineEdit_6->setText("");

        ui->progressBar->setValue(0);
    }

    else
    {
        ui->progressBar->setValue(45);



        Land.FillLines(uiDatum, geoID);

        if (Land.Infi == "-999" || Land.Tode == "-999")
        {
            ui->progressBar->setValue(100);

            QMessageBox::information(this, "ungültiges Datum", "Daten für dieses Datum in der Datenbank"
                                                               " nicht gefunden. Versuchen "
                                                               "Sie die Datenbank zu aktualisieren");

            ui->lineEdit_4->setText("");
            ui->lineEdit_6->setText("");

            ui->progressBar->setValue(0);
        }

        else
        {
            ui->tab->layout()->~QLayout();

            ui->progressBar->setValue(75);


        ui->lineEdit_4->setText(Land.Infi);
        ui->lineEdit_6->setText(Land.Tode);



        QLineSeries *seriesInf = new QLineSeries(),
                   *seriesTode = new QLineSeries();
        seriesInf->setName("Infiziierte");
        seriesTode->setName("Tode");

        QString Titel = "Übersicht für xxx von 01 bis yyy"; //Der Titel der Graph
        QString tblMonat = Land.DbLandDaten.gibMonat(Land.DbLandDaten.Monat);
        Titel.replace("xxx", tblMonat);
        Titel.replace("yyy", Land.DbLandDaten.Datum);



        int n = Land.FillTab(uiDatum, Land.skalaLinear, geoID);

        for (int i=0; i<n;i++)
        {
            seriesInf->append( Land.tblInfi[0][n-1-i], Land.tblInfi[1][n-1-i]);

            qDebug()<< "Punkt Nummer i = "<<i<<" = "
                    << "("<<Land.tblInfi[0][n-1-i]<<","<<Land.tblInfi[1][n-1-i]<<")" ;

            seriesTode->append(Land.tblTode[0][n-1-i], Land.tblTode[1][n-1-i]);
        }

        ui->progressBar->setValue(87);

        QChart *chart = new QChart();
        chart->legend()->setVisible(true);
        chart->addSeries(seriesInf);
        chart->addSeries(seriesTode);
        chart->setTitle(Titel);

        QValueAxis *axisX = new QValueAxis();
        axisX->setTickCount(n);
        chart->addAxis(axisX, Qt::AlignBottom);
        seriesInf->attachAxis(axisX);

        QValueAxis *axisYInf = new QValueAxis();
        chart->addAxis(axisYInf, Qt::AlignLeft);
        seriesInf->attachAxis(axisYInf);
        seriesTode->attachAxis(axisYInf);
        axisYInf->setMin(0);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        ui->progressBar->setValue(92);

        QVBoxLayout* verticalLayout_3 = new QVBoxLayout(ui->tab);
        verticalLayout_3->addWidget(chartView);
        ui->tab->setLayout(verticalLayout_3);

        ui->progressBar->setValue(100);

        }

    }

    qDebug ("ApplyChange ends");
}

void Weissrussland::on_skalaLiear_clicked()
{
   Land.skalaLinear = true;

   ui->progressBar->setValue(0);
}

void Weissrussland::on_skalaLogarithm_clicked()
{
   Land.skalaLinear = false;

   ui->progressBar->setValue(0);
}
