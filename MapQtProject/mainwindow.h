#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include "locationtable.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QObject *item;
    ~MainWindow();
    bool locationsViewExist = false;
    locationTable* locationView = new locationTable();
    QSqlDatabase db;
    bool dbSetup = true;
    void databaseSetup(QString);
    QString databasePass = "Asd123";
    void setPassword(QString);

private slots:
    void addTableElement(QString, QString, QString);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
