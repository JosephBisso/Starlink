#ifndef DATENBANK_H
#define DATENBANK_H


#include <QDialog>
#include "databank.h"

//...
#include <iostream>
#include <QMessageBox>
#include <QTableView>
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QFile>


namespace Ui {
class Datenbank;
}

class Datenbank : public QDialog
{
    Q_OBJECT

public:
    explicit Datenbank(QWidget *parent = nullptr);
    ~Datenbank();

private slots:
    void on_dbConnect_clicked();

    void on_dbShow_clicked();

    void on_dbUpdate_clicked();

    void on_dbOK_accepted();


private:
    Ui::Datenbank *ui;

    databank datenbank;

};

#endif // DATENBANK_H
