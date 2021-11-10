#ifndef LOCATIONTABLE_H
#define LOCATIONTABLE_H

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
    void on_pushButton_clicked();

private:
    Ui::locationTable *ui;
};

#endif // LOCATIONTABLE_H
