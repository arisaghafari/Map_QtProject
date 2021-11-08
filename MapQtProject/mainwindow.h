#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

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

private slots:
    void on_pushButton_clicked();
    void addTableElement();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
