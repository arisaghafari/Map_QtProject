#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QDeclarativeView>
#include <QQuickView>
#include <QTimeEdit>
#include <QQuickWindow>
#include <QQuickWidget>
#include <QtQuick>
#include <QDebug>
#include "locationtable.h"


QSqlQuery query("CREATE TABLE location (id int not null primary key, lat text,lon text,description text)");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QQuickView* view = new QQuickView();
    QWidget *container = QWidget::createWindowContainer(view, this);
    view->setSource(QUrl::fromLocalFile((":/main.qml")));
    if (view)
        item = view->rootObject();

    QObject::connect(item, SIGNAL(submitClicked(QString, QString, QString)), this, SLOT(addTableElement(QString, QString, QString)));
    ui->vBox->addWidget(container);
    ui->tabWidget->removeTab(1);

    //database
    //db = QSqlDatabase::addDatabase("QMYSQL");
    //db.setHostName("127.0.0.1");
    //db.setUserName("root");
    //db.setPassword("");
    //db.setDatabaseName("locations");
    //conn = connOpen();
}

MainWindow::~MainWindow()
{
    connClose();
    delete ui;
}

void MainWindow::connClose()
{
    //qDebug() << "connClose....";
    db.close();
    db.removeDatabase(db.connectionName());
}
bool MainWindow::connOpen()
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/arisa/location.db");

    if(db.open())
    {
        QSqlQuery query;
        query.prepare("create table location(lat text, lon text, description text)");
        if(query.exec())
            qDebug() << "created ...";
        else
            qDebug() << "table could not create: " << query.lastError();
        return true;
    }
    else if(!db.open())
    {
        QMessageBox::information(this, "Not conncted", query.lastError().text());
        //qDebug() << "couldn't open....";
        return false;
    }
}
void MainWindow::addTableElement(QString lat, QString lon, QString description)
{
    if (!locationsViewExist){
        ui->tabWidget->addTab(new locationTable, QString("Locations"));
        locationsViewExist = true;
    }
    //write data in data base
    if(connOpen()){
        //qDebug() << "conn ...";
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO location(lat,lon,description) VALUES (:lat,:lon,:description)");
        queryAdd.bindValue(":lat", lat);
        queryAdd.bindValue(":lon", lon);
        queryAdd.bindValue(":description", description);
        if(queryAdd.exec())
            qDebug() << "success !!!";
        else
            qDebug() << "record could not add: " << queryAdd.lastError();
    }
    else{
        QMessageBox::information(this, "Not conncted", query.lastError().text());
    }
    connClose();
}

