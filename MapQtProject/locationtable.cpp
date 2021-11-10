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
}

locationTable::~locationTable()
{
    delete ui;
}

