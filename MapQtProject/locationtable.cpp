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

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "loadConnection");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("Asd123");
    db.setDatabaseName("locations");
    db.open();
    if(db.isOpen())
    {
        QSqlQueryModel* model = new QSqlQueryModel();
        QSqlQuery* query = new QSqlQuery(db);
        query->prepare("select * from location");
        query->exec();
        model->setQuery(*query);
        ui->tableView->setModel(model);
    }
    else
    {
        QMessageBox::information(this, "connection", "coulden't load data...");
    }
}
