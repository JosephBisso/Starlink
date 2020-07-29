#include "grossbritannien.h"
#include "ui_grossbritannien.h"
#include "laender.h"
#include "databank.h"
#include <QtCharts>

Grossbritannien::Grossbritannien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Grossbritannien)
{
    ui->setupUi(this);

    //SEHR WICHTIG!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //Liste von geoID von jedem EU-Land in den Ressource Datei / lib
    QString geoID = "UK";

    // Für Klemmens: Ab hier Copy/Paste
    Laender Land; //ein Element der Klasse Laender erstellen.

    double InfiMonat[12],
           TodeMonat[12];

    Land.InfiTodeMonat(geoID);

    for (int i=0; i<12; i++)
    {
        InfiMonat[i] = Land.infMonat [i]; //Jeder Element des Feld Attribut vom Land wird in dem
                                          //entsprechenden Element der variablen Feldes gespeichert
        TodeMonat[i] = Land.todMonat [i];
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

Grossbritannien::~Grossbritannien()
{
    delete ui;
}

void Grossbritannien::on_buttonBox_clicked(QAbstractButton *button)
{
    button->isChecked();

    qDebug ("ApplyChange Starts...");

    QString geoID = "UK";
    Laender Land; // Ein Element der Klasse Land wird erstellt. Dies erlaubt uns die Methode der Klasse Databank
                  // (gibDatum, gibInfiziierte, gitTode ) durch das Attribut DbLandDaten
                  // vom Typ Databank der Klasse Laender.

    QDate uiDatum = ui->dateEdit->date(); //Das aktuelles Datum auf dem UI wird gelesen und in einen Variable gespeichert

    if (uiDatum>QDate::currentDate()) //Prüft ob das Datum sich nich in der Zukunft befindet
    {
        QMessageBox::information(this, "ungültiges Datum", "Daten werden nur darstellt und nicht vorausgesagt.");

        ui->lineEdit_4->setText(""); //Zeilen werden leer gemacht
        ui->lineEdit_6->setText("");

    }


    else
    {
    qDebug() << "uiDatum = " << uiDatum;

    QString Monat = QString::number(uiDatum.month()); //Der Monat wird aus dem gelesenen Datum auf dem UI gewonnen
    if (Monat.size()==1)
    {
        Monat.insert(0, "0");      //Aus Monat im Format "m" wird Monat im Format "mm" ("06" statt "6")
    }

    qDebug() << "Monat = " << Monat;


    QString Tag = QString::number(uiDatum.day()); //Der Tag wird aus dem gelesenen Datum auf dem UI gewonnen
    if (Tag.size()==1)
    {
        Tag.insert(0, "0"); //Aus Tag im Format "d" wird Tag im Format "dd" ("1" statt "01")
    }

    qDebug() << "Tag = " << Tag;

    QString Datum = Land.DbLandDaten.gibDatum(Tag, Monat); //Die Methode gibDatum, gib das
                                                        // Datum in dem von der Datenbank benutzten Format

    qDebug() << "Datum = " << Datum;

    QString Infi = QString::number(Land.DbLandDaten.gibInfiierte(Datum, geoID)); //Es werden Daten aus der Datenbank gewonnen
    QString Tode = QString::number(Land.DbLandDaten.gibTode(Datum, geoID));//Es werden Daten aus der Datenbank gewonnen

    qDebug() << "Infi = " << Infi << ", Tode = " << Tode ;

        if (Infi == "-999" || Tode == "-999") //-999 wird von der Methode gibInfiziierte und gibTode zurückgegeben,
                                              //wenn keine Daten zu dem Datum gefunden wurden
        {
            QMessageBox::information(this, "ungültiges Datum", "Daten für dieses Datum in der Datenbank"
                                                               " nicht gefunden. Versuchen "
                                                               "Sie die Datenbank zu aktualisieren");

            ui->lineEdit_4->setText(""); //Zeilen leer gemacht
            ui->lineEdit_6->setText("");
        }

        else
        {


        ui->lineEdit_4->setText(Infi); //Wenn alle Bedingungen gut klappen, dann werden die Daten dargestellt.
        ui->lineEdit_6->setText(Tode);

        }

    }


}
