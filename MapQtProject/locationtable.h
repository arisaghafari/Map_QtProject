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

private:
    Ui::locationTable *ui;
};

#endif // LOCATIONTABLE_H
