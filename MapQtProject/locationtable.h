#ifndef LOCATIONTABLE_H
#define LOCATIONTABLE_H
#include <QtSql>
#include <QSqlDatabase>
#include <QWidget>

namespace Ui {
class locationTable;
}

class locationTable : public QWidget
{
    Q_OBJECT

public:
    explicit locationTable(QWidget *parent = nullptr);
    ~locationTable();

private slots:
    void on_load_button_clicked();

private:
    Ui::locationTable *ui;
};

#endif // LOCATIONTABLE_H
