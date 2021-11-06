#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    /*QDeclarativeView *qmlView = new QDeclarativeView;
    qmlView->setSource(QUrl::fromLocalFile("main.qml"));

    QWidget *widget = myExistingWidget();
    QVBoxLayout *layout = new QVBoxLayout(widget);
    layout->addWidget(qmlView);
*/}
