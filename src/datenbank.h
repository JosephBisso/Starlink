#ifndef DATENBANK_H
#define DATENBANK_H

#include <QDialog>

//...
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <iostream>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QTableView>

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

    void on_dbDelete_clicked();

    void on_dbOK_accepted();

private:
    Ui::Datenbank *ui;
};

#endif // DATENBANK_H
