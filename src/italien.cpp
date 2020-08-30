#include "italien.h"
#include "ui_italien.h"
#include "laender.h"
#include "databank.h"
#include <QtCharts>

Italien::Italien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Italien)
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
    chart->setTitle("Übersicht Infizierte 2020");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chartTode->addSeries(seriesTode);
    chartTode->setTitle("Übersicht Tode 2020");
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
    axisY->setMax(101000);
    axisYTode->setMin(0);
    axisYTode->setMax(20000);
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

Italien::~Italien()
{
    delete ui;
}
void Italien::on_buttonBox_clicked(QAbstractButton *button)
{
    button->isChecked(); //Dies erfüllt keinen Zweck und dient nur dazu die Fehlermeldung wegen des
                         //unbenutzten  button zu schweigen.

    ui->progressBar->setValue(15); //Schaut dem Nutzer den Stand der Operation

    qDebug ("ApplyChange Starts..."); // qDebug dient mir nur dazu mich über den Verlauf zu informieren


    QDate uiDatum = ui->dateEdit->date(); //Das aktuelles Datum auf dem UI wird gelesen und in einen Variable gespeichert

    if (uiDatum>QDate::currentDate()) //Prüft ob das Datum sich nich in der Zukunft befindet
    {
        ui->progressBar->setValue(100);
        QMessageBox::information(this, "ungültiges Datum", "Daten werden nur darstellt und nicht vorausgesagt.");

        ui->lineEdit_4->setText(""); //Zeilen werden leer gemacht
        ui->lineEdit_6->setText("");

        ui->progressBar->setValue(0);
    }

    else //Wenn das Datum das aktuelles oder en vergangenes ist:
    {
        ui->progressBar->setValue(45);

        //Land und geoID sind Attribute dieser Klasse.

        Land.FillLines(uiDatum, geoID); //Die Methode aus der Klasser Laender FillLines wird gerufen
                                       // es werden die Anzahl von Infiziierten und Toden an dem
                                      //vom User ausgewählten Datum dargestellt. Die Daten werden anschließend
                                     //in dem Attribut Infi und Tode vom Objekt Land

        QString SiebenTage = Land.Fill7TagDurchschnitt(uiDatum, geoID);

        if (Land.Infi == "-999" || Land.Tode == "-999" || SiebenTage == "")

        {
            ui->progressBar->setValue(100);

            QMessageBox::information(this, "ungültiges Datum", "Daten für dieses Datum in der Datenbank"
                                                               " nicht gefunden. Versuchen "
                                                               "Sie die Datenbank zu aktualisieren");

            ui->lineEdit_4->setText("");
            ui->lineEdit_6->setText("");
            ui->lineEdit_7->setText("");

            ui->progressBar->setValue(0);
        }

        else
        {
           int Einwohnerzahl = 60297000; //Quelle: https://www.laenderdaten.info/Europa/Italien/index.php , Stand: 21.08.2020

           ui->lineEdit_9->setText(Land.InfiproEinwohner(geoID,Einwohnerzahl));

            ui->tab->layout()->~QLayout();
            ui->tab_5->layout()->~QLayout();

            ui->progressBar->setValue(75);


        ui->lineEdit_4->setText(Land.Infi);

        ui->lineEdit_6->setText(Land.Tode);

        ui->lineEdit_7->setText(SiebenTage);




        QLineSeries *seriesInf = new QLineSeries(), //Es werden neue Serien geschaffen, dank dessen eine Graph
                                                   //die Serie bekommen nachher Koordinate hinzugefügt
                   *seriesTode = new QLineSeries();
        seriesInf->setName("Infiziierte");//Die Serien bekommen einen Namen. Ist für die Legende wichtig
        seriesTode->setName("Tode");

        QString Titel = "Übersicht Infiziierte für xxx"; //Der Titel der Graph
        QString tblMonat = Land.DbLandDaten.gibMonat(Land.DbLandDaten.Monat); //Die Mehtode gib aus den Monat im Format
                                                                             //"mm" der im Hintergrund durch die
                                                                            //Methode FillLines im Attribut Monat vom
                                                                           //Attribut DbLandDaten vom Objet Land
                                                                          //gespeichert. Lange Kette zwar, aber
                                                                         //effektiv.
        Titel.replace("xxx", tblMonat);
        QString TitelTode = Titel;
        TitelTode.replace("Infiziierte", "Tode");



        int n = Land.FillTab(uiDatum, Land.skalaLinear, geoID); //Die Methode FillTab wird gerufen. Es werden Daten
                                                               // von allen Tagen im Monat vom ersten Tag bis zum
                                                              //vom User ausgewählten Tag gerufen und in 2 Matrixen,
                                                             //die Attribute der Klasse Laender sind, gespeichert.
                                                            //SkalaLinear bestimmt, ob die Daten liniar oder logarith-
                                                           //misch gespeichert werden soll.
                                                          //Die Methode gib die Anzahl von Tagen zurück, für die
                                                         //Daten gerufen wurden

        if (n<uiDatum.daysInMonth()) //Prüft, ob die Anzahl von Einträge (n) kleiner ist als die Anzahl an Tagen in des ausgewählten Monats
        {
            QMessageBox::information(this, "Datenbank", "Es fehlen anscheinend Daten für einen Teil dises Monats");

            QString TagEnde = QString::number(n);
            if (TagEnde.size()==1){TagEnde.insert(0, "0");}

            QString DatumEnde = Land.DbLandDaten.gibDatum(TagEnde, Land.DbLandDaten.Monat); //Das letzte in der Datenbank existierende Datum für
                                                                                           // Monat wir gerufen und gespeichert...

            Titel.append(" bis "); Titel.append(DatumEnde); //... Und wird dem Titel hinzugefügt
            TitelTode.append(" bis "); TitelTode.append(DatumEnde);
        }

        for (int i=0; i<n;i++)
        {
            seriesInf->append( Land.tblInfi[0][i], Land.tblInfi[1][i]); //In der erste Spalte der Matrix tblInfi
                                                                               //werden die Nummer von den Tagen und
                                                                              //in der 2. Spalte die Daten gespeichert.
                                                                             //Sie werden der Serie als Koordinate
                                                                            //hinzugefügt. Die Schleife geht durch die
                                                                           //Matrixen rückwärts von n-1 bis 1.

            qDebug()<< "Punkt Nummer i = "<<i<<" = "
                    << "("<<Land.tblInfi[0][i]<<","<<Land.tblInfi[1][i]<<")" ;

            seriesTode->append(Land.tblTode[0][i], Land.tblTode[1][i]);
        }

        ui->progressBar->setValue(87);

        QChart *chart = new QChart(), //Eine neue Instanz vom Typ QChart wird gerufen. Sie bekommen eine Legende, einen
                                     //Titel und den Series hinzugefügt
               *chartTode = new QChart();
        chart->legend()->setVisible(true);
        chart->addSeries(seriesInf);
        chart->setTitle(Titel);
        chartTode->legend()->setVisible(true);
        chartTode->addSeries(seriesTode);
        chartTode->setTitle(TitelTode);
        chartTode->setTheme(QChart::ChartThemeDark);

        QValueAxis *axisX = new QValueAxis(), //Axe x
                *axisXTode = new QValueAxis();
        axisX->setTickCount(n);
        axisX->setLabelFormat("%.0f");
        chart->addAxis(axisX, Qt::AlignBottom);
        seriesInf->attachAxis(axisX); // Die Serie wird mit der Achse verbunden
        axisXTode->setTickCount(n);
        axisXTode->setLabelFormat("%.0f"); //Damit es keine Gleitkommazahlen gibt
        chartTode->addAxis(axisXTode, Qt::AlignBottom);
        seriesTode->attachAxis(axisXTode);

        qDebug() << "Label Format für Axis X "<<axisXTode->labelFormat();

        QValueAxis *axisYInf = new QValueAxis(),
                *axisYTode = new QValueAxis();
        chart->addAxis(axisYInf, Qt::AlignLeft);
        seriesInf->attachAxis(axisYInf);
        axisYInf->setMin(0); //Es wird ein Minimun gesetzt.
        chartTode->addAxis(axisYTode, Qt::AlignLeft);
        seriesTode->attachAxis(axisYTode);
        axisYTode->setMin(0);

        QChartView *chartView = new QChartView(chart),// Zur Darstellung der Graphen
                *chartViewTode = new QChartView(chartTode);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartViewTode->setRenderHint(QPainter::Antialiasing);

        ui->progressBar->setValue(92);

        QVBoxLayout* verticalLayout_3 = new QVBoxLayout(ui->tab), //Ein neues Layout wird erstellt und an ui->Tab
                                                                 //gegeben. Das Layout bekommt dann den Chart
                                                                //hinzugefügt
                *verticalLayout_3Tode = new QVBoxLayout(ui->tab_5);

        verticalLayout_3->addWidget(chartView);
        verticalLayout_3Tode->addWidget(chartViewTode);
        ui->tab->setLayout(verticalLayout_3);
        ui->tab_5->setLayout(verticalLayout_3Tode);

        ui->progressBar->setValue(100);

        }

    }

    qDebug ("ApplyChange ends");
}

void Italien::on_skalaLiear_clicked()
{
   Land.skalaLinear = true;

   ui->progressBar->setValue(0);
}

void Italien::on_skalaLogarithm_clicked()
{
   Land.skalaLinear = false;

   ui->progressBar->setValue(0);
}
