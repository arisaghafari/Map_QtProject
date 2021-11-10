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
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("locations");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTableElement(QString lat, QString lon, QString description)
{
    qDebug() << lat;
    qDebug() << lon;
    qDebug() << description;
    if (!locationsViewExist){
        ui->tabWidget->addTab(new locationTable, QString("Locations"));
        locationsViewExist = true;
    }
    //write data in data base
    if(db.open()){
        QMessageBox::information(this, "Connection", "Database connected successfully");
    }
    else{
        QMessageBox::information(this, "Not conncted", "Database is not connected");
    }
}
