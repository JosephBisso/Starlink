#include "daenemark.h"
#include "ui_daenemark.h"
#include <QtCharts>

Daenemark::Daenemark(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Daenemark)
{
    ui->setupUi(this);
    QBarSet *set0 = new QBarSet("Inf");
    QBarSet *set1 = new QBarSet("Tode");

    *set0 << 0 << 2 << 2575 << 6431 << 2420 << 11428;
    *set1 << 0 << 0 << 77 << 366 << 120 << 563;


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
