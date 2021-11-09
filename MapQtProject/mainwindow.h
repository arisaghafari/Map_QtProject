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

signals:
    void addTableElementSignal();

private slots:
    void on_pushButton_clicked();
    void addTableElement(double, double, QString);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
