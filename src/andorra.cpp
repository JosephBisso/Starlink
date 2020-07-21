#include "andorra.h"
#include "ui_andorra.h"
#include <QtCharts>
#include <laender.h>
#include <databank.h>

Andorra::Andorra(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Andorra)
{
    ui->setupUi(this);
    QBarSet *set0 = new QBarSet("Inf");
    QBarSet *set1 = new QBarSet("Tode");

    *set0 << 0 << 0 << 370 << 373 << 20 << 763;
    *set1 << 0 << 0 << 8 << 34 << 9 << 51;


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
    axisY->setRange(0,800);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);
   ui->verticalLayout_2->addWidget(chartView);
}

Andorra::~Andorra()
{
    delete ui;
}
