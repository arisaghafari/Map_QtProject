#ifndef MYSQLPASS_H
#define MYSQLPASS_H

#include <QDialog>

namespace Ui {
class mysqlPass;
}

class mysqlPass : public QDialog
{
    Q_OBJECT

public:
    explicit mysqlPass(QWidget *parent = nullptr);
    ~mysqlPass();

private slots:
    void on_pushButton_clicked();

private:
    Ui::mysqlPass *ui;
};

#endif // MYSQLPASS_H
