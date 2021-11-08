#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QDeclarativeView>
#include <QQuickView>
#include <QTimeEdit>
#include <QQuickWindow>
#include <QQuickWidget>
#include <QtQuick>
#include <QDebug>

void MainWindow::addTableElement()
{
    qDebug("hi");
    QMessageBox::information(this, "Connection", "hi");
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->quickWidget->setSource(QUrl::fromLocalFile(":/main.qml"));
    QQuickView view(QUrl::fromLocalFile((":/main.qml")));
    QObject *item = view.rootObject();
    QObject::connect(item, SIGNAL(zoomClicked()), this, SLOT(addTableElement()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("locations");

    if(db.open()){
        QMessageBox::information(this, "Connection", "Database connected successfully");
    }
    else{
        QMessageBox::information(this, "Not conncted", "Database is not connected");
    }
}


