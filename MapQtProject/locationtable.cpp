#include "locationtable.h"
#include "ui_locationtable.h"
#include <QDebug>
#include <QMessageBox>
#include <QDebug>
#include <map>
#include <QString>
#include <QProgressBar>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QTimer>
#include <QRadioButton>
#include <QTimeEdit>
#include <QTableWidgetItem>

locationTable::locationTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::locationTable)
{
    ui->setupUi(this);
    //ui->tableWidget->setColumnCount(3);
}

locationTable::~locationTable()
{
    delete ui;
}

void locationTable::insertElement()
{
    ui->tableWidget->setColumnCount(3);
    //ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    //ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1,0,new QTableWidgetItem("ui->comboBox->currentText()"));
    qDebug() << "hi";
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem(QString("kheyli olaghi")));
}

void locationTable::on_pushButton_clicked()
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1,0,new QTableWidgetItem("ui->comboBox->currentText()"));

}
