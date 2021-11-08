#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QDeclarativeView>
#include <QQuickView>
#include <QTimeEdit>
#include <QQuickWindow>
#include <QQuickWidget>
#include <QtQuick>
#include <QDebug>

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

    QObject::connect(item, SIGNAL(submitClicked()), this, SLOT(addTableElement()));
//    ui->quickWidget->setSource(QUrl::fromLocalFile(":/main.qml"));
//    setCentralWidget(container);
    ui->vBox->addWidget(container);
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

void MainWindow::addTableElement()
{
    qDebug() << "!!!!!!!!!!!!!!!!!!!";
    // QMessageBox::information(this, "Connection", "hi");
}

