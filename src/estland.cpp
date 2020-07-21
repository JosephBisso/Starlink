#include "estland.h"
#include "ui_estland.h"
#include <QtCharts>

Estland::Estland(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Estland)
{
    ui->setupUi(this);
    QBarSet *set0 = new QBarSet("Inf");
    QBarSet *set1 = new QBarSet("Tode");

    *set0 << 0 << 1 << 714 << 951 << 168 << 1834;
    *set1 << 0 << 0 << 3 << 47 << 15 << 65;


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
    axisY->setRange(0,2000);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout_2->addWidget(chartView);

}

Estland::~Estland()
{
    delete ui;
}
