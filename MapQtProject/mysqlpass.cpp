#include "mysqlpass.h"
#include "ui_mysqlpass.h"
#include <QDebug>
#include "mainwindow.h"

MainWindow mainW;
mysqlPass::mysqlPass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mysqlPass)
{
    ui->setupUi(this);
    //connect(this, &mysqlPass::on_pushButton_clicked, MainWindow::setPassword(QString));
}

mysqlPass::~mysqlPass()
{
    delete ui;
}

void mysqlPass::on_pushButton_clicked()
{
    QString password = ui->lineEdit->text();
    qDebug() << "password : " << password;
    delete this;
    emit mainW.setPassword(password);
}
