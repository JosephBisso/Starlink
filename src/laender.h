#ifndef LAENDER_H
#define LAENDER_H
#include "databank.h"

#include <QObject>
#include <QLineSeries>
#include <QtCharts>
#include <QMessageBox>

#include <QtMath>

#include <QDebug>

class Laender : public QObject //Diese Klasse beinhaltet alle Methoden zur Gewinnung von Daten eines beliebigen Landes.
{
    Q_OBJECT
public:
    explicit Laender(QObject *parent = nullptr);

    void setGeoID(QString geoID);

    QString getGeoID();

    QString* get_laenderName();

    QString* get_laenderGeoID();

    QString* get_laenderCode();

    int* get_laenderEinwohner();

    void setLand_arrayCounter(int i);

    int getLand_arrayCounter();

    QString convertToCountryCode(QString geoID);

    QPixmap* getFlag(QString geoID);

    databank DbLandDaten; //Die Klasse databank erlaubt dank ihrer Methoden den Zugriff auf die Datenbank

    void gibLandDaten(QString Tag, QString Monat, QString Jahr);

    void InfiTodeMonat (QString Jahr); //Rechnet und speichert
                              //Gesamtinfiziierte und -Tode
                                //für alle Monate in 2 Felder.

    int FillTab (QDate uiDatum, bool skalalinear);

    void FillLines (QDate uiDatum);

    QString Fill7TagDurchschnitt (QDate uiDatum);

    QString InfiproEinwohner (int Einwohnerzahl, QDate uiDatum);


    double infMonat [12]; //Ein Feld mit Größe 12 wir erstellt.

    double todMonat [12];

    qreal tblInfi [2][31],
           tblTode[2][31];

    bool skalaLinear = true;


    QString Infi,
            Tode;

    void setLandName(QString landName);

    QString getLandName();

    void setEinwohnerzahl(int einwohnerzahl);

    int getEinwohnerzahl();


private:

    QString geoID = "-999";

    QString landName;

    int land_arrayCounter;

    QString laenderName[215] = {"Afghanistan","Albania","Algeria","Andorra","Angola","Anguilla","Antigua_and_Barbuda","Argentina","Armenia","Aruba","Australia","Austria","Azerbaijan","Bahamas","Bahrain","Bangladesh","Barbados","Belarus","Belgium","Belize","Benin","Bermuda","Bhutan","Bolivia","Bonaire, Saint Eustatius  Saba","Bosnia_and_Herzegovina","Botswana","Brazil","British_Virgin_Islands","Brunei_Darussalam","Bulgaria","Burkina_Faso","Burundi","Cambodia","Cameroon","Canada","Cape_Verde","Cases_on_an_international_conveyance_Japan","Cayman_Islands","Central_African_Republic","Chad","Chile","China","Colombia","Comoros","Congo","Costa_Rica","Cote_dIvoire","Croatia","Cuba","CuraÃ§ao","Cyprus","Czechia","Democratic_Republic_of_the_Congo","Denmark","Djibouti","Dominica","Dominican_Republic","Ecuador","Egypt","El_Salvador","Equatorial_Guinea","Eritrea","Estonia","Eswatini","Ethiopia","Falkland_Islands_Malvinas","Faroe_Islands","Fiji","Finland","France","French_Polynesia","Gabon","Gambia","Georgia","Germany","Ghana","Gibraltar","Greece","Greenland","Grenada","Guam","Guatemala","Guernsey","Guinea","Guinea_Bissau","Guyana","Haiti","Holy_See","Honduras","Hungary","Iceland","India","Indonesia","Iran","Iraq","Ireland","Isle_of_Man","Israel","Italy","Jamaica","Japan","Jersey","Jordan","Kazakhstan","Kenya","Kosovo","Kuwait","Kyrgyzstan","Laos","Latvia","Lebanon","Lesotho","Liberia","Libya","Liechtenstein","Lithuania","Luxembourg","Madagascar","Malawi","Malaysia","Maldives","Mali","Malta","Marshall_Islands","Mauritania","Mauritius","Mexico","Moldova","Monaco","Mongolia","Montenegro","Montserrat","Morocco","Mozambique","Myanmar","Namibia","Nepal","Netherlands","New_Caledonia","New_Zealand","Nicaragua","Niger","Nigeria","North_Macedonia","Northern_Mariana_Islands","Norway","Oman","Pakistan","Palestine","Panama","Papua_New_Guinea","Paraguay","Peru","Philippines","Poland","Portugal","Puerto_Rico","Qatar","Romania","Russia","Rwanda","Saint_Kitts_and_Nevis","Saint_Lucia","Saint_Vincent_and_the_Grenadines","San_Marino","Sao_Tome_and_Principe","Saudi_Arabia","Senegal","Serbia","Seychelles","Sierra_Leone","Singapore","Sint_Maarten","Slovakia","Slovenia","Solomon_Islands","Somalia","South_Africa","South_Korea","South_Sudan","Spain","Sri_Lanka","Sudan","Suriname","Sweden","Switzerland","Syria","Taiwan","Tajikistan","Thailand","Timor_Leste","Togo","Trinidad_and_Tobago","Tunisia","Turkey","Turks_and_Caicos_islands","Uganda","Ukraine","United_Arab_Emirates","United_Kingdom","United_Republic_of_Tanzania","United_States_of_America","United_States_Virgin_Islands","Uruguay","Uzbekistan","Vanuatu","Venezuela","Vietnam","Wallis_and_Futuna","Western_Sahara","Yemen","Zambia","Zimbabwe"};
    QString laenderGeoID[215] = {"AF","AL","DZ","AD","AO","AI","AG","AR","AM","AW","AU","AT","AZ","BS","BH","BD","BB","BY","BE","BZ","BJ","BM","BT","BO","BQ","BA","BW","BR","VG","BN","BG","BF","BI","KH","CM","CA","CV","JPG11668","KY","CF","TD","CL","CN","CO","KM","CG","CR","CI","HR","CU","CW","CY","CZ","CD","DK","DJ","DM","DO","EC","EG","SV","GQ","ER","EE","SZ","ET","FK","FO","FJ","FI","FR","PF","GA","GM","GE","DE","GH","GI","EL","GL","GD","GU","GT","GG","GN","GW","GY","HT","VA","HN","HU","IS","IN","ID","IR","IQ","IE","IM","IL","IT","JM","JP","JE","JO","KZ","KE","XK","KW","KG","LA","LV","LB","LS","LR","LY","LI","LT","LU","MG","MW","MY","MV","ML","MT","MH","MR","MU","MX","MD","MC","MN","ME","MS","MA","MZ","MM","NA","NP","NL","NC","NZ","NI","NE","NG","MK","MP","NO","OM","PK","PS","PA","PG","PY","PE","PH","PL","PT","PR","QA","RO","RU","RW","KN","LC","VC","SM","ST","SA","SN","RS","SC","SL","SG","SX","SK","SI","SB","SO","ZA","KR","SS","ES","LK","SD","SR","SE","CH","SY","TW","TJ","TH","TL","TG","TT","TN","TR","TC","UG","UA","AE","UK","TZ","US","VI","UY","UZ","VU","VE","VN","WF","EH","YE","ZM","ZW"};
    QString laenderCode[215] = {"AFG","ALB","DZA","AND","AGO","AIA","ATG","ARG","ARM","ABW","AUS","AUT","AZE","BHS","BHR","BGD","BRB","BLR","BEL","BLZ","BEN","BMU","BTN","BOL","BES","BIH","BWA","BRA","VGB","BRN","BGR","BFA","BDI","KHM","CMR","CAN","CPV","Leer","CYM","CAF","TCD","CHL","CHN","COL","COM","COG","CRI","CIV","HRV","CUB","CUW","CYP","CZE","COD","DNK","DJI","DMA","DOM","ECU","EGY","SLV","GNQ","ERI","EST","SWZ","ETH","FLK","FRO","FJI","FIN","FRA","PYF","GAB","GMB","GEO","DEU","GHA","GIB","GRC","GRL","GRD","GUM","GTM","GGY","GIN","GNB","GUY","HTI","VAT","HND","HUN","ISL","IND","IDN","IRN","IRQ","IRL","IMN","ISR","ITA","JAM","JPN","JEY","JOR","KAZ","KEN","XKX","KWT","KGZ","LAO","LVA","LBN","LSO","LBR","LBY","LIE","LTU","LUX","MDG","MWI","MYS","MDV","MLI","MLT","MHL","MRT","MUS","MEX","MDA","MCO","MNG","MNE","MSF","MAR","MOZ","MMR","NAM","NPL","NLD","NCL","NZL","NIC","NER","NGA","MKD","MNP","NOR","OMN","PAK","PSE","PAN","PNG","PRY","PER","PHL","POL","PRT","PRI","QAT","ROU","RUS","RWA","KNA","LCA","VCT","SMR","STP","SAU","SEN","SRB","SYC","SLE","SGP","SXM","SVK","SVN","SLB","SOM","ZAF","KOR","SSD","ESP","LKA","SDN","SUR","SWE","CHE","SYR","CNG1925","TJK","THA","TLS","TGO","TTO","TUN","TUR","TCA","UGA","UKR","ARE","GBR","TZA","USA","VIR","URY","UZB","VUT","VEN","VNM","Leer","ESH","YEM","ZMB","ZWE"};
    int laenderEinwohner[215] = {38041757,2862427,43053054,76177,31825299,14872,97115,44780675,2957728,106310,25203200,8858775,10047719,389486,1641164,163046173,287021,9452409,11455519,390351,11801151,62508,763094,11513102,25983,3300998,2303703,211049519,30033,433296,7000039,20321383,11530577,16486542,25876387,37411038,549936,-999,64948,4745179,15946882,18952035,1433783692,50339443,850891,5380504,5047561,25716554,4076246,11333484,163423,875899,10649800,86790568,5806081,973557,71808,10738957,17373657,100388076,6453550,1355982,3497117,1324820,1148133,112078727,3372,48677,889955,5517919,67012883,279285,2172578,2347696,3996762,83019213,30417858,33706,10724599,56660,112002,167295,17581476,64468,12771246,1920917,782775,11263079,815,9746115,9772756,356991,1366417756,270625567,82913893,39309789,4904240,84589,8519373,60359546,2948277,126860299,107796,10101697,18551428,52573967,1798506,4207077,6415851,7169456,1919968,6855709,2125267,4937374,6777453,38378,2794184,613894,26969306,18628749,31949789,530957,19658023,493559,58791,4525698,1269670,127575529,4043258,33085,3225166,622182,4991,36471766,30366043,54045422,2494524,28608715,17282163,282757,4783062,6545503,23310719,200963603,2077132,57213,5328212,4974992,216565317,4981422,4246440,8776119,7044639,32510462,108116622,37972812,10276617,2933404,2832071,19414458,145872260,12626938,52834,182795,110593,34453,215048,34268529,16296362,6963764,97741,7813207,5804343,42389,5450421,2080908,669821,15442906,58558267,51225321,11062114,46937060,21323734,42813237,581363,10230185,8544527,17070132,23773881,9321023,69625581,1293120,8082359,1394969,11694721,82003882,38194,44269587,43993643,9770526,66647112,58005461,329064917,104579,3461731,32981715,299882,28515829,96462108,-999,582458,29161922,17861034,14645473};

    QString* allNamen = laenderName;

    QString* allGeoID = laenderGeoID;

    QString* allLandCode = laenderCode;

    int* allEinwohner = laenderEinwohner;

signals:

};

#endif // LAENDER_H
