#include "albanien.h"
#include "ui_albanien.h"
#include <QtCharts>
#include "laender.h"
#include "databank.h"

Albanien::Albanien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Albanien)
{
    ui->setupUi(this);

    QBarSet *set0 = new QBarSet("Inf");
    QBarSet *set1 = new QBarSet("Tode"); // Einstellung der Legende

    *set0 << 0 << 0 << 223 << 543 << 263 << 1029;
    *set1 << 0 << 0 << 12 << 19 << 2 << 33;


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
    series->attachAxis(axisX); // Umbennenung der X-Achse

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,1100);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout->addWidget(chartView); // Initalisierung der BarChart

}

Albanien::~Albanien()
{
    delete ui;
}
