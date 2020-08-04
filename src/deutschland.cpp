#include "deutschland.h"
#include "ui_deutschland.h"

#include <QDialog>
#include <QMessageBox>  //Dient nur der Darstellung, damit du verstehst.

//Muss included sein!!!!!!!!!!!!!!1
#include "laender.h"
#include "databank.h" // aufpassen: datAbank und nicht datENbank
#include <QtCharts>



Deutschland::Deutschland(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Deutschland)

{
    ui->setupUi(this);    


    //Land und geoID sind Attribute dieser Klasse.

    double InfiMonat[12], //Vektoren mit 12 Elementen werden erstellt
           TodeMonat[12];

    Land.InfiTodeMonat(geoID); //Die Methode InfoTodeMonat der Klasser Laendeer rechnet alle infiziierte und
                              //Tode für alle Monate und speichert sie in 2 Felder (Attributen) der KLasse
                             //Laender infMonat[12] und toMonat[12]

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
    ui->verticalLayout_4->addWidget(chartView); // Initalisierung der BarChart


}

Deutschland::~Deutschland()
{
    delete ui;
}


void Deutschland::on_buttonBox_clicked(QAbstractButton *button)
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

        if (Land.Infi == "-999" || Land.Tode == "-999") //(-999 wird von der Methode FillLines zurückgegeben,
                                              //wenn keine Daten zu dem Datum gefunden wurden)
        {
            ui->progressBar->setValue(100);

            QMessageBox::information(this, "ungültiges Datum", "Daten für dieses Datum in der Datenbank"
                                                               " nicht gefunden. Versuchen "
                                                               "Sie die Datenbank zu aktualisieren");

            ui->lineEdit_4->setText(""); //Zeilen leer gemacht
            ui->lineEdit_6->setText("");

            ui->progressBar->setValue(0);
        }

        else //Wenn alle vorherigen Bedingungen gut klappen, dann werden die Daten dargestellt.
        {            
            ui->tab->layout()->~QLayout(); //das aktuelles Layout im Tab wird gelöscht

            ui->progressBar->setValue(75);


        ui->lineEdit_4->setText(Land.Infi); //Das Ergebnis die durch der Methode im Attribut Infi vom
                                           // Objekt Land gespeichert wurde wird gerufen
        ui->lineEdit_6->setText(Land.Tode);



        QLineSeries *seriesInf = new QLineSeries(), //Es werden neue Serien geschaffen, dank dessen eine Graph
                                                   //die Serie bekommen nachher Koordinate hinzugefügt
                   *seriesTode = new QLineSeries();
        seriesInf->setName("Infiziierte");//Die Serien bekommen einen Namen. Ist für die Legende wichtig
        seriesTode->setName("Tode");

        QString Titel = "Übersicht für xxx von 01 bis yyy"; //Der Titel der Graph
        QString tblMonat = Land.DbLandDaten.gibMonat(Land.DbLandDaten.Monat); //Die Mehtode gib aus den Monat im Format
                                                                             //"mm" der im Hintergrund durch die
                                                                            //Methode FillLines im Attribut Monat vom
                                                                           //Attribut DbLandDaten vom Objet Land
                                                                          //gespeichert. Lange Kette zwar, aber
                                                                         //effektiv.
        Titel.replace("xxx", tblMonat);
        Titel.replace("yyy", Land.DbLandDaten.Datum);



        int n = Land.FillTab(uiDatum, Land.skalaLinear, geoID); //Die Methode FillTab wird gerufen. Es werden Daten
                                                               // von allen Tagen im Monat vom ersten Tag bis zum
                                                              //vom User ausgewählten Tag gerufen und in 2 Matrixen,
                                                             //die Attribute der Klasse Laender sind, gespeichert.
                                                            //SkalaLinear bestimmt, ob die Daten liniar oder logarith-
                                                           //misch gespeichert werden soll.
                                                          //Die Methode gib die Anzahl von Tagen zurück, für die
                                                         //Daten gerufen wurden

        for (int i=0; i<n;i++)
        {
            seriesInf->append( Land.tblInfi[0][n-1-i], Land.tblInfi[1][n-1-i]); //In der erste Spalte der Matrix tblInfi
                                                                               //werden die Nummer von den Tagen und
                                                                              //in der 2. Spalte die Daten gespeichert.
                                                                             //Sie werden der Serie als Koordinate
                                                                            //hinzugefügt. Die Schleife geht durch die
                                                                           //Matrixen rückwärts von n-1 bis 1.

            qDebug()<< "Punkt Nummer i = "<<i<<" = "
                    << "("<<Land.tblInfi[0][n-1-i]<<","<<Land.tblInfi[1][n-1-i]<<")" ;

            seriesTode->append(Land.tblTode[0][n-1-i], Land.tblTode[1][n-1-i]);
        }

        ui->progressBar->setValue(87);

        QChart *chart = new QChart(); //Eine neue Instanz vom Typ QChart wird gerufen. Sie bekommen eine Legende, einen
                                     //Titel und den Series hinzugefügt
        chart->legend()->setVisible(true);
        chart->addSeries(seriesInf);
        chart->addSeries(seriesTode);
        chart->setTitle(Titel);

        QValueAxis *axisX = new QValueAxis(); //Axe x
        axisX->setTickCount(n);
        chart->addAxis(axisX, Qt::AlignBottom);
        seriesInf->attachAxis(axisX); // Die Serie wird mit der Achse verbunden

        QValueAxis *axisYInf = new QValueAxis();
        chart->addAxis(axisYInf, Qt::AlignLeft);
        seriesInf->attachAxis(axisYInf);
        seriesTode->attachAxis(axisYInf);
        axisYInf->setMin(0); //Es wird ein Minimun gesetzt.

        QChartView *chartView = new QChartView(chart);// Zur Darstellung der Graphen
        chartView->setRenderHint(QPainter::Antialiasing);

        ui->progressBar->setValue(92);  

        QVBoxLayout* verticalLayout_3 = new QVBoxLayout(ui->tab); //Ein neues Layout wird erstellt und an ui->Tab
                                                                 //gegeben. Das Layout bekommt dann den Chart
                                                                //hinzugefügt
        verticalLayout_3->addWidget(chartView);
        ui->tab->setLayout(verticalLayout_3);

        ui->progressBar->setValue(100);

        }

    }

    qDebug ("ApplyChange ends");
}

void Deutschland::on_skalaLogarithm_clicked()
{
   Land.skalaLinear = false; // Das Attribut skalaLiniar der Klasse Laender wird auf falsch gesetzt.

   ui->progressBar->setValue(0);
}

void Deutschland::on_skalaLiear_clicked()
{
   Land.skalaLinear = true;

   ui->progressBar->setValue(0);
}
