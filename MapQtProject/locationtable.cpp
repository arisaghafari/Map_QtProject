#include "locationtable.h"
#include "ui_locationtable.h"
#include <QDebug>
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
//#include "mainwindow.h"

QSqlDatabase db;
locationTable::locationTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::locationTable)
{
    ui->setupUi(this);
}

locationTable::~locationTable()
{
    delete ui;
}

void locationTable::on_load_button_clicked()
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/arisa/location.db");

    if(db.open())
    {
        QSqlQueryModel* model = new QSqlQueryModel();
        QSqlQuery* query = new QSqlQuery(db);
        query->prepare("select * from location");
        query->exec();
        model->setQuery(*query);
        ui->tableView->setModel(model);
        //qDebug() << model->rowCount();
        //qDebug() << "loaded...";

    }
    else if(!db.open())
    {
        QMessageBox::information(this, "connection", "coulden't load data...");
        //qDebug() << "couldn't open in load tab....";
    }
    db.close();
    db.removeDatabase(db.connectionName());
}
