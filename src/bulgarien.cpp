#include "bulgarien.h"
#include "ui_bulgarien.h"
#include <QtCharts>

Bulgarien::Bulgarien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bulgarien)
{
    ui->setupUi(this);
    QBarSet *set0 = new QBarSet("Inf");
    QBarSet *set1 = new QBarSet("Tode");

    *set0 << 0 << 0 << 359 << 1088 << 1013 << 2460;
    *set1 << 0 << 0 << 8 << 56 << 69 << 133;


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
    axisY->setRange(0,1100);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout_2->addWidget(chartView);
}

Bulgarien::~Bulgarien()
{
    delete ui;
}
