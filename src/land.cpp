#include "land.h"
#include "ui_land.h"

#include <QDialog>
#include <QMessageBox>
#include "laender.h"
#include "databank.h"
#include <QtCharts>

Land::Land(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Land)
{
    ui->setupUi(this);
    setWindowTitle(setTitle());
}

Land::~Land()
{
    delete ui;
}

void Land::doDiagramm() {

}

QString Land::setTitle() {

    QString land_geoID = laender->getGeoID(),
            name_Land;
    if (land_geoID == "AL") {
        name_Land = "Albania";
    } else if (land_geoID == "AD") {
        name_Land = "Andorra";
    } else if (land_geoID == "AM") {
        name_Land = "Armenia";
    } else if (land_geoID == "AT") {
        name_Land = "Austria";
    } else if (land_geoID == "AZ") {
        name_Land = "Azerbaijan";
    } else if (land_geoID == "BY") {
        name_Land = "Belarus";
    } else if (land_geoID == "BE") {
        name_Land = "Belgium";
    } else if (land_geoID == "BA") {
        name_Land = "Bosnia_and_Herzegovina";
    } else if (land_geoID == "BG") {
        name_Land = "Bulgaria";
    } else if (land_geoID == "HR") {
        name_Land = "Crotia";
    } else if (land_geoID == "CY") {
        name_Land = "Cyprus";
    } else if (land_geoID == "CZ") {
        name_Land = "Czechia";
    } else if (land_geoID == "DK") {
        name_Land = "Denmark";
    } else if (land_geoID == "EE") {
        name_Land = "Estonia";
    } else if (land_geoID == "FO") {
        name_Land = "Faroe_Islands";
    } else if (land_geoID == "FI") {
        name_Land = "Finnland";
    } else if (land_geoID == "FR") {
        name_Land = "France";
    } else if (land_geoID == "GE") {
        name_Land = "Georgia";
    } else if (land_geoID == "DE") {
        name_Land = "Germany";
    } else if (land_geoID == "GI") {
        name_Land = "Gibraltar";
    } else if (land_geoID == "EL") {
        name_Land = "Greece";
    } else if (land_geoID == "GG") {
        name_Land = "Guernsey";
    } else if (land_geoID == "VA") {
        name_Land = "Holy_See";
    } else if (land_geoID == "HU") {
        name_Land = "Hungary";
    } else if (land_geoID == "IS") {
        name_Land = "Iceland";
    } else if (land_geoID == "IE") {
        name_Land = "Ireland";
    } else if (land_geoID == "IM") {
        name_Land = "Isle_of_Man";
    } else if (land_geoID == "IT") {
        name_Land = "Italy";
    } else if (land_geoID == "JE") {
        name_Land = "Jersey";
    } else if (land_geoID == "XK") {
        name_Land = "Kosovo";
    } else if (land_geoID == "LV") {
        name_Land = "Latvia";
    } else if (land_geoID == "LI") {
        name_Land = "Liechtenstein";
    } else if (land_geoID == "LT") {
        name_Land = "Lithuania";
    } else if (land_geoID == "LU") {
        name_Land = "Luxembourg";
    } else if (land_geoID == "MT") {
        name_Land = "Malta";
    } else if (land_geoID == "MD") {
        name_Land = "Moldova";
    } else if (land_geoID == "MC") {
        name_Land = "Monaco";
    } else if (land_geoID == "ME") {
        name_Land = "Montenegro";
    } else if (land_geoID == "NL") {
        name_Land = "Netherlands";
    } else if (land_geoID == "MK") {
        name_Land = "North_Macedonia";
    } else if (land_geoID == "NO") {
        name_Land = "Norway";
    } else if (land_geoID == "PL") {
        name_Land = "Poland";
    } else if (land_geoID == "PT") {
        name_Land = "Portugal";
    } else if (land_geoID == "RO") {
        name_Land = "Romania";
    } else if (land_geoID == "RU") {
        name_Land = "Russia";
    } else if (land_geoID == "SM") {
        name_Land = "San_Marino";
    } else if (land_geoID == "RS") {
        name_Land = "Serbia";
    } else if (land_geoID == "SK") {
        name_Land = "Slovakia";
    } else if (land_geoID == "SI") {
        name_Land = "Slovania";
    } else if (land_geoID == "ES") {
        name_Land = "Spain";
    } else if (land_geoID == "SE") {
        name_Land = "Sweden";
    } else if (land_geoID == "CH") {
        name_Land = "Switzerland";
    } else if (land_geoID == "UA") {
        name_Land = "Ukraine";
    } else if (land_geoID == "UK") {
        name_Land = "United_Kingdom";
    } else {
        name_Land = "-999";
    }

    return name_Land;
}

void Land::setGeoID(QString geoID) {
    laender->setGeoID(geoID);
}



void Land::on_buttonBox_clicked(QAbstractButton *button)
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

        laender->FillLines(uiDatum); //Die Methode aus der Klasser Laender FillLines wird gerufen
                                       // es werden die Anzahl von Infiziierten und Toden an dem
                                      //vom User ausgewählten Datum dargestellt. Die Daten werden anschließend
                                     //in dem Attribut Infi und Tode vom Objekt Land

        QString SiebenTage = laender->Fill7TagDurchschnitt(uiDatum);

        if (laender->Infi == "-999" || laender->Tode == "-999" || SiebenTage == "") //(-999 wird von der Methode FillLines zurückgegeben,
                                              //wenn keine Daten zu dem Datum gefunden wurden)
        {
            ui->progressBar->setValue(100);

            QMessageBox::information(this, "ungültiges Datum", "Daten für dieses Datum in der Datenbank"
                                                               " nicht gefunden. Versuchen "
                                                               "Sie die Datenbank zu aktualisieren");

            ui->lineEdit_4->setText(""); //Zeilen leer gemacht
            ui->lineEdit_6->setText("");
            ui->lineEdit_7->setText("");

            ui->progressBar->setValue(0);
        }

        else //Wenn alle vorherigen Bedingungen gut klappen, dann werden die Daten dargestellt.
        {
            int Einwohnerzahl = 83133000; //Quelle: https://www.laenderdaten.info/Europa/Deutschland/index.php , Stand: 21.08.2020
                                         // Initialisierung eines neuen Parameters. Die Einwohnerzahl des Landes wird festgelegt. Für jedes Land unterschiedliche Einwohnerzahl.

            ui->lineEdit_9->setText(laender->InfiproEinwohner(Einwohnerzahl)); //Endergebnis wird in einem lineEdit angezeigt

            ui->tab->layout()->~QLayout(); //das aktuelles Layout im Tab wird gelöscht
            ui->tab_5->layout()->~QLayout();

            ui->progressBar->setValue(75);


        ui->lineEdit_4->setText(laender->Infi); //Das Ergebnis die durch der Methode im Attribut Infi vom
                                           // Objekt Land gespeichert wurde wird gerufen
        ui->lineEdit_6->setText(laender->Tode);

        ui->lineEdit_7->setText(SiebenTage);


        QLineSeries *seriesInf = new QLineSeries(), //Es werden neue Serien geschaffen, dank dessen eine Graph
                                                   //die Serie bekommen nachher Koordinate hinzugefügt
                   *seriesTode = new QLineSeries();
        seriesInf->setName("Infiziierte");//Die Serien bekommen einen Namen. Ist für die Legende wichtig
        seriesTode->setName("Tode");

        QString Titel = "Übersicht Infiziierte für xxx"; //Der Titel der Graph
        QString tblMonat = laender->DbLandDaten.gibMonat(laender->DbLandDaten.Monat); //Die Mehtode gib aus den Monat im Format
                                                                             //"mm" der im Hintergrund durch die
                                                                            //Methode FillLines im Attribut Monat vom
                                                                           //Attribut DbLandDaten vom Objet Land
                                                                          //gespeichert. Lange Kette zwar, aber
                                                                         //effektiv.
        Titel.replace("xxx", tblMonat);
        QString TitelTode = Titel;
        TitelTode.replace("Infiziierte", "Tode");



        int n = laender->FillTab(uiDatum, laender->skalaLinear); //Die Methode FillTab wird gerufen. Es werden Daten
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

            QString DatumEnde = laender->DbLandDaten.gibDatum(TagEnde, laender->DbLandDaten.Monat); //Das letzte in der Datenbank existierende Datum für
                                                                                           // Monat wir gerufen und gespeichert...

            Titel.append(" bis "); Titel.append(DatumEnde); //... Und wird dem Titel hinzugefügt
            TitelTode.append(" bis "); TitelTode.append(DatumEnde);
        }

        for (int i=0; i<n;i++)
        {
            seriesInf->append( laender->tblInfi[0][i], laender->tblInfi[1][i]); //In der erste Spalte der Matrix tblInfi
                                                                               //werden die Nummer von den Tagen und
                                                                              //in der 2. Spalte die Daten gespeichert.
                                                                             //Sie werden der Serie als Koordinate
                                                                            //hinzugefügt. Die Schleife geht durch die
                                                                           //Matrixen rückwärts von n-1 bis 1.

            qDebug()<< "Punkt Nummer i = "<<i<<" = "
                    << "("<<laender->tblInfi[0][i]<<","<<laender->tblInfi[1][i]<<")" ;

            seriesTode->append(laender->tblTode[0][i], laender->tblTode[1][i]);
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

void Land::on_skalaLogarithm_clicked()
{
   laender->skalaLinear = false; // Das Attribut skalaLiniar der Klasse Laender wird auf falsch gesetzt.

   ui->progressBar->setValue(0);
}

void Land::on_skalaLiear_clicked()
{
   laender->skalaLinear = true;

   ui->progressBar->setValue(0);
}
