#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QDeclarativeView>
#include <QQuickView>
#include <QTimeEdit>
#include <QQuickWindow>
#include <QQuickWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->quickWidget->setSource(QUrl::fromLocalFile(":/main.qml"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
