#include "belgien.h"
#include "ui_belgien.h"
#include <QtCharts>

Belgien::Belgien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Belgien)
{
    ui->setupUi(this);
    QBarSet *set0 = new QBarSet("Inf");
    QBarSet *set1 = new QBarSet("Tode");

    *set0 << 0 << 1 << 11898 << 35960 << 9596 << 57455;
    *set1 << 0 << 0 << 513 << 6988 << 1833 << 57455;


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
    axisY->setRange(0,60000);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout_2->addWidget(chartView);
}

Belgien::~Belgien()
{
    delete ui;
}
