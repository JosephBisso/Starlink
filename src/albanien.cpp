#include "albanien.h"
#include "ui_albanien.h"
#include <QtCharts>
#include "laender.h"
#include "databank.h"
#include <QDialog>
#include <QMessageBox>


Albanien::Albanien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Albanien)
{
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

    *set0 << InfiMonat[0] << InfiMonat[1] << InfiMonat[2] << InfiMonat[3]
            << InfiMonat[4] << InfiMonat[5] << InfiMonat[6] << InfiMonat[7]
            << InfiMonat[8] << InfiMonat[9] << InfiMonat[10] << InfiMonat[11] ;



    QBarSeries *series_1 = new QBarSeries();
    series_1->append(set0);


    QChart *chart_1 = new QChart();
    chart_1->addSeries(series_1);
    chart_1->setTitle("Covisualizer");
    chart_1->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories_1;
    categories_1 << "Jan." << "Feb." << "März" << "April" << "Mai" << "Juni" << "Juli" << "Aug." << "Sept." << "Okt." << "Nov." << "Dez.";
    QBarCategoryAxis *axisX_1 = new QBarCategoryAxis();
    axisX_1->append(categories_1);
    chart_1->addAxis(axisX_1, Qt::AlignBottom);
    series_1->attachAxis(axisX_1);

    QValueAxis *axisY_1 = new QValueAxis();
    axisY_1->setMin(0);
    axisY_1->setMax(3000);
    chart_1->addAxis(axisY_1, Qt::AlignLeft);
    series_1->attachAxis(axisY_1);

    chart_1->legend()->setVisible(true);
    chart_1->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView_1 = new QChartView(chart_1);
       chartView_1->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout_4->addWidget(chartView_1);

    QBarSet *set1 = new QBarSet("Tote");

    *set1 << TodeMonat[0] << TodeMonat[1] << TodeMonat[2] << TodeMonat[3]
            << TodeMonat[4] << TodeMonat[5] << TodeMonat[6] << TodeMonat[7]
            << TodeMonat[8] << TodeMonat[9] << TodeMonat[10] << TodeMonat[11] ;

    QBarSeries *series_2 = new QBarSeries();
    series_2->append(set1);

    QChart *chart_2 = new QChart();
    chart_2->addSeries(series_2);
    chart_2->setTitle("Covisualizer");
    chart_2->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories_2;
    categories_2 << "Jan." << "Feb." << "März" << "April" << "Mai" << "Juni" << "Juli" << "Aug." << "Sept." << "Okt." << "Nov." << "Dez.";

    QBarCategoryAxis *axisX_2 = new QBarCategoryAxis();
    axisX_2->append(categories_2);
    chart_2->addAxis(axisX_2, Qt::AlignBottom);
    series_2->attachAxis(axisX_2);

    chart_2->legend()->setVisible(true);
    chart_2->legend()->setAlignment(Qt::AlignBottom);

    QValueAxis *axisY_2 = new QValueAxis();
    axisY_2->setMin(0);
    axisY_2->setMax(100);
    chart_2->addAxis(axisY_2, Qt::AlignLeft);
    series_2->attachAxis(axisY_2);

    chart_1->legend()->setVisible(true);
    chart_1->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView_2 = new QChartView(chart_2);
    chartView_2->setRenderHint(QPainter::Antialiasing);

    ui->verticalLayout_2->addWidget(chartView_2);

}

Albanien::~Albanien()
{
    delete ui;
}


void Albanien::on_buttonBox_clicked(QAbstractButton *button)
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

void Albanien::on_skalaLiear_clicked()
{
   Land.skalaLinear = true;

   ui->progressBar->setValue(0);
}


void Albanien::on_skalaLogarithm_clicked()
{
   Land.skalaLinear = false;

   ui->progressBar->setValue(0);
}
