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

}

Land::~Land()
{
    delete ui;
}

void Land::doDiagramm() {

    //Land und geoID sind Attribute dieser Klasse.

    double InfiMonat[12], //Vektoren mit 12 Elementen werden erstellt
           TodeMonat[12];

    QString Jahr = QString::number(ui->dateEdit->date().year());

    laender->InfiTodeMonat(Jahr); //Die Methode InfoTodeMonat der Klasser Laendeer rechnet alle infiziierte und
                              //Tode für alle Monate und speichert sie in 2 Felder (Attributen) der KLasse
                             //Laender infMonat[12] und toMonat[12]

    for (int i=0; i<12; i++)
    {
        InfiMonat[i] = laender->infMonat [i]; //Jeder Element des Feld Attribut vom Land wird in dem
                                          //entsprechenden Element der variablen Feldes gespeichert
        TodeMonat[i] = laender->todMonat [i];
    }

    QBarSet *set0 = new QBarSet("Infizierte"); // Eine neue Intanz von Typ QChart wird aufgerufen und ein Set wird für die Werte erstellt
    QBarSet *set1 = new QBarSet("Tode");


    *set0 << InfiMonat[0] << InfiMonat[1] << InfiMonat[2] << InfiMonat[3]
            << InfiMonat[4] << InfiMonat[5] << InfiMonat[6] << InfiMonat[7]
            << InfiMonat[8] << InfiMonat[9] << InfiMonat[10] << InfiMonat[11] ;

    *set1 << TodeMonat[0] << TodeMonat[1] << TodeMonat[2] << TodeMonat[3]
            << TodeMonat[4] << TodeMonat[5] << TodeMonat[6] << TodeMonat[7]
            << TodeMonat[8] << TodeMonat[9] << TodeMonat[10] << TodeMonat[11] ; // Den Sets werden die Werte von Infizierten und Toden über den Zeitraum von 12 Monaten zugewiesen

    QBarSeries *series = new QBarSeries(),
                *seriesTode = new QBarSeries(); // Neue Intanz von Typ QChart, es werden zwei Serien erstellt mit unterschiedlichen Namen als Zuweisung
    series->append(set0);
    seriesTode->append(set1); //Die Serien werden an die Sets angehängt

    QChart *chart = new QChart(),
            *chartTode = new QChart(); //Eine neue Instanz vom Typ QChart wird gerufen. Sie bekommen eine Legende, einen
                                      //Titel, den Series hinzugefügt und die Animation wird festgelegt
    chart->addSeries(series);
    chart->setTitle("Übersicht Infizierte" + Jahr);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chartTode->addSeries(seriesTode);
    chartTode->setTitle("Übersicht Tode " + Jahr);
    chartTode->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Jan." << "Feb." << "März" << "April" << "Mai" << "Juni" << "Juli" << "Aug." << "Sept." << "Okt." << "Nov." << "Dez."; // Es werden neue Kategorien für die X-Achse erstellt, welche jetzt aus den Namen der Einzelnen Monaten bestehen.
                                                                                                                                        // Neue Intanz von Typ QString hinzugefügt und erhält den Namen categories
    QBarCategoryAxis *axisX = new QBarCategoryAxis(),
                        *axisXTode = new QBarCategoryAxis(); //Die vorher erstellten neuen Kategorien werden jetzt durch eine neue Instanz von Typ QChart an die untere Seite der X-Achse gebunden.

    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    axisXTode->append(categories);
    chartTode->addAxis(axisXTode, Qt::AlignBottom);


    QValueAxis *axisY = new QValueAxis(),
                *axisYTode = new QValueAxis(); // Eine neue Instanz von QChart hinzugefügt, welche ein Minimum und Maximum sowie die Orientierung der Beschrieftung der Y-Achse feestlegt

    axisY->setMin(0);
    axisY->setMax(100000);
    axisYTode->setMin(0);
    axisYTode->setMax(6000);
    chart->addAxis(axisY, Qt::AlignLeft);
    chartTode->addAxis(axisYTode, Qt::AlignLeft);
    series->attachAxis(axisY);
    seriesTode->attachAxis(axisYTode);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chartTode->legend()->setVisible(true);
    chartTode->legend()->setAlignment(Qt::AlignBottom); // Legende wird angezeigt und orientiert sich an der unteren Seite

    QChartView *chartView = new QChartView(chart),
                *chartViewTode = new QChartView(chartTode);
       chartView->setRenderHint(QPainter::Antialiasing);
       chartViewTode->setRenderHint(QPainter::Antialiasing); // Dient zur Darstellung der Balkendiagramme


    ui->verticalLayout_4->addWidget(chartView);
    ui->verticalLayout_2->addWidget(chartViewTode); //Balkendiagramme werden in einem bestimmten Layout angezeigt
}

QString Land::setTitle() {

//Quelle: https://www.laenderdaten.info/Europa/Deutschland/index.php , Stand: 21.08.2020

    QString land_geoID = laender->getGeoID(),
            name_Land;
    if (land_geoID == "AL") {
        name_Land = "Albania";
        laender->setEinwohnerzahl(2854000);
    } else if (land_geoID == "AD") {
        name_Land = "Andorra"; ////////////////////
        laender->setEinwohnerzahl(2854000);
    } else if (land_geoID == "AM") {
        name_Land = "Armenia"; //////////////////
        laender->setEinwohnerzahl(2854000);
    } else if (land_geoID == "AT") {
        name_Land = "Austria";
        laender->setEinwohnerzahl(8877000);
    } else if (land_geoID == "AZ") {
        name_Land = "Azerbaijan"; ///////////////
        laender->setEinwohnerzahl(2854000);
    } else if (land_geoID == "BY") {
        name_Land = "Belarus";
        laender->setEinwohnerzahl(9467000);
    } else if (land_geoID == "BE") {
        name_Land = "Belgium";
        laender->setEinwohnerzahl(11484000);
    } else if (land_geoID == "BA") {
        name_Land = "Bosnia_and_Herzegovina";
        laender->setEinwohnerzahl(3301000);
    } else if (land_geoID == "BG") {
        name_Land = "Bulgaria";
        laender->setEinwohnerzahl(6976000);
    } else if (land_geoID == "HR") {
        name_Land = "Crotia";
        laender->setEinwohnerzahl(4068000);
    } else if (land_geoID == "CY") {
        name_Land = "Cyprus"; //////////////////
        laender->setEinwohnerzahl(2854000);
    } else if (land_geoID == "CZ") {
        name_Land = "Czechia";
        laender->setEinwohnerzahl(10670000);
    } else if (land_geoID == "DK") {
        name_Land = "Denmark";
        laender->setEinwohnerzahl(5819000);
    } else if (land_geoID == "EE") {
        name_Land = "Estonia";
        laender->setEinwohnerzahl(1327000);
    } else if (land_geoID == "FO") {
        name_Land = "Faroe_Islands"; //////////////
        laender->setEinwohnerzahl(2854000);
    } else if (land_geoID == "FI") {
        name_Land = "Finnland";
        laender->setEinwohnerzahl(5520000);
    } else if (land_geoID == "FR") {
        name_Land = "France";
        laender->setEinwohnerzahl(67060000);
    } else if (land_geoID == "GE") {
        name_Land = "Georgia";
        laender->setEinwohnerzahl(2854000);
    } else if (land_geoID == "DE") {
        name_Land = "Germany";
        laender->setEinwohnerzahl(83133000);
    } else if (land_geoID == "GI") {
        name_Land = "Gibraltar"; ////////////////////////
        laender->setEinwohnerzahl(2854000);
    } else if (land_geoID == "EL") {
        name_Land = "Greece";
        laender->setEinwohnerzahl(10716000);
    } else if (land_geoID == "GG") {
        name_Land = "Guernsey"; ////////////////////////////
        laender->setEinwohnerzahl(2854000);
    } else if (land_geoID == "VA") {
        name_Land = "Holy_See"; ////////////////////////////
        laender->setEinwohnerzahl(2854000);
    } else if (land_geoID == "HU") {
        name_Land = "Hungary";
        laender->setEinwohnerzahl(9770000);
    } else if (land_geoID == "IS") {
        name_Land = "Iceland";
        laender->setEinwohnerzahl(361313);
    } else if (land_geoID == "IE") {
        name_Land = "Ireland";
        laender->setEinwohnerzahl(4941000);
    } else if (land_geoID == "IM") {
        name_Land = "Isle_of_Man"; /////////////////////
        laender->setEinwohnerzahl(2854000);
    } else if (land_geoID == "IT") {
        name_Land = "Italy";
        laender->setEinwohnerzahl(60297000);
    } else if (land_geoID == "JE") {
        name_Land = "Jersey"; //////////////////////////
        laender->setEinwohnerzahl(2854000);
    } else if (land_geoID == "XK") {
        name_Land = "Kosovo";
        laender->setEinwohnerzahl(1794000);
    } else if (land_geoID == "LV") {
        name_Land = "Latvia";
        laender->setEinwohnerzahl(1913000);
    } else if (land_geoID == "LI") {
        name_Land = "Liechtenstein";//////////////////////////
        laender->setEinwohnerzahl(2854000);
    } else if (land_geoID == "LT") {
        name_Land = "Lithuania";
        laender->setEinwohnerzahl(2787000);
    } else if (land_geoID == "LU") {
        name_Land = "Luxembourg"; /////////////////////////////
        laender->setEinwohnerzahl(2854000);
    } else if (land_geoID == "MT") {
        name_Land = "Malta"; ////////////////////////////////
        laender->setEinwohnerzahl(2854000);
    } else if (land_geoID == "MD") {
        name_Land = "Moldova";
        laender->setEinwohnerzahl(2658000);
    } else if (land_geoID == "MC") {
        name_Land = "Monaco"; ///////////////////////////////
        laender->setEinwohnerzahl(2854000);
    } else if (land_geoID == "ME") {
        name_Land = "Montenegro";
        laender->setEinwohnerzahl(622137);
    } else if (land_geoID == "NL") {
        name_Land = "Netherlands";
        laender->setEinwohnerzahl(17333000);
    } else if (land_geoID == "MK") {
        name_Land = "North_Macedonia";
        laender->setEinwohnerzahl(2787000);
    } else if (land_geoID == "NO") {
        name_Land = "Norway";
        laender->setEinwohnerzahl(5348000);
    } else if (land_geoID == "PL") {
        name_Land = "Poland";
        laender->setEinwohnerzahl(2854000);
    } else if (land_geoID == "PT") {
        name_Land = "Portugal";
        laender->setEinwohnerzahl(10269000);
    } else if (land_geoID == "RO") {
        name_Land = "Romania";
        laender->setEinwohnerzahl(19357000);
    } else if (land_geoID == "RU") {
        name_Land = "Russia";////////////////////////////////
        laender->setEinwohnerzahl(2854000);
    } else if (land_geoID == "SM") {
        name_Land = "San_Marino";/////////////////////////////
        laender->setEinwohnerzahl(2854000);
    } else if (land_geoID == "RS") {
        name_Land = "Serbia";
        laender->setEinwohnerzahl(6945000);
    } else if (land_geoID == "SK") {
        name_Land = "Slovakia";
        laender->setEinwohnerzahl(5454000);
    } else if (land_geoID == "SI") {
        name_Land = "Slovania";
        laender->setEinwohnerzahl(2088000);
    } else if (land_geoID == "ES") {
        name_Land = "Spain";
        laender->setEinwohnerzahl(47077000);
    } else if (land_geoID == "SE") {
        name_Land = "Sweden";
        laender->setEinwohnerzahl(10285000);
    } else if (land_geoID == "CH") {
        name_Land = "Switzerland";
        laender->setEinwohnerzahl(8575000);
    } else if (land_geoID == "UA") {
        name_Land = "Ukraine";
        laender->setEinwohnerzahl(44385000);
    } else if (land_geoID == "UK") {
        name_Land = "United_Kingdom";
        laender->setEinwohnerzahl(66834000);
    } else {
        name_Land = "-999";
    }

    laender->setLandName(name_Land);
    return name_Land;
}

void Land::setGeoID(QString geoID) {
    laender->setGeoID(geoID);
}



void Land::on_buttonBox_clicked(QAbstractButton *button)
{
    button->setDisabled(true);

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
            doDiagramm();

            int Einwohnerzahl = laender->getEinwohnerzahl();
                                         // Initialisierung eines neuen Parameters. Die Einwohnerzahl des Landes wird festgelegt. Für jedes Land unterschiedliche Einwohnerzahl.

            ui->lineEdit_9->setText(laender->InfiproEinwohner(Einwohnerzahl, uiDatum)); //Endergebnis wird in einem lineEdit angezeigt

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

            QString DatumEnde = laender->DbLandDaten.gibDatum(TagEnde, laender->DbLandDaten.Monat,laender->DbLandDaten.Jahr); //Das letzte in der Datenbank existierende Datum für
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
    button->setDisabled(false);

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