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
#include "mysqlpass.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    mysqlPass *mp = new mysqlPass();
    ui->setupUi(this);

    QQuickView* view = new QQuickView();
    QWidget *container = QWidget::createWindowContainer(view, this);
    view->setSource(QUrl::fromLocalFile((":/main.qml")));
    if (view)
        item = view->rootObject();

    QObject::connect(item, SIGNAL(submitClicked(QString, QString, QString)), this, SLOT(addTableElement(QString, QString, QString)));
    ui->vBox->addWidget(container);
    ui->tabWidget->removeTab(1);
    //database pass

    mp->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPassword(QString pass){
    databasePass = pass;
}
void MainWindow::databaseSetup(QString Password){
    db = QSqlDatabase::addDatabase("QMYSQL", "myConnection");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword(Password);
    db.setDatabaseName("locations");

    db.open();
    QSqlQuery query(db);
    query.prepare("CREATE TABLE IF NOT EXISTS location(latitude VARCHAR(50) NOT NULL, longitude VARCHAR(50) NOT NULL, description VARCHAR(200))");
    if(query.exec())
        qDebug() << "created ...";
    else
        qDebug() << "table could not create: " << query.lastError();

}
void MainWindow::addTableElement(QString lat, QString lon, QString description)
{
    if (dbSetup){
        databaseSetup(databasePass);
        dbSetup = false;
    }
    if (!locationsViewExist){
        ui->tabWidget->addTab(new locationTable, QString("Locations"));
        locationsViewExist = true;
    }
    if(db.isOpen()){

        QSqlQuery queryAdd(db);
        queryAdd.prepare("INSERT INTO location (latitude, longitude, description) VALUES (:lat, :lon, :description);");
        queryAdd.bindValue(":lat", lat);
        queryAdd.bindValue(":lon", lon);
        queryAdd.bindValue(":description", description);
        if(queryAdd.exec())
            qDebug() << "success !!!";
        else
            qDebug() << "record could not add: " << queryAdd.lastError();
    }
    else{
        QMessageBox::information(this, "Not conncted", "query.lastError().text()");
    }
}

