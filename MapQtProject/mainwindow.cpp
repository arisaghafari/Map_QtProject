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
    db = QSqlDatabase::addDatabase("QMYSQL", "myConnection");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("Asd123");
    db.setDatabaseName("locations");
    //conn = connOpen();
    bool conn = db.open();
    QSqlQuery query(db);
    query.prepare("CREATE TABLE IF NOT EXISTS location(latitude VARCHAR(50) NOT NULL, longitude VARCHAR(50) NOT NULL, description VARCHAR(200))");
    if(query.exec())
        qDebug() << "created ...";
    else
        qDebug() << "table could not create: " << query.lastError();
}
//Asd123

MainWindow::~MainWindow()
{
    //connClose();
    delete ui;
}

/*void MainWindow::connClose()
{
    //qDebug() << "connClose....";
    db.close();
    db.removeDatabase(db.connectionName());
}
bool MainWindow::connOpen()
{
    //Please wait
    //salam ostad
    //ostad man chon natoonestam be mysql vasl konam az sqlit estefade kardam ta projaro tamoom knam va hamoon bakhshe mysql bemoone
    //alan ba sqlite kamel kar mikone
    //Ok, please change sqlite to mysql, I see
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
}*/
void MainWindow::addTableElement(QString lat, QString lon, QString description)
{
    if (!locationsViewExist){
        ui->tabWidget->addTab(new locationTable, QString("Locations"));
        locationsViewExist = true;
    }
    if(db.isOpen()){

        //qDebug() << "conn ...";
        QSqlQuery queryAdd(db);
        queryAdd.prepare("INSERT INTO location (latitude, longitude, description) VALUES (:lat, :lon, :description);");
        //queryAdd.prepare("SELECT * FROM location");

        queryAdd.bindValue(":lat", lat);
        queryAdd.bindValue(":lon", lon);
        queryAdd.bindValue(":description", description);
        if(queryAdd.exec())
            qDebug() << "success !!!";
        else
            qDebug() << "record could not add: " << queryAdd.lastError();
        //QMessageBox::information(this, "connected", "connect!!");
    }
    else{
        QMessageBox::information(this, "Not conncted", "query.lastError().text()");
    }
    //connClose();
}

