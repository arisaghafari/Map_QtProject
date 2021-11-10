/********************************************************************************
** Form generated from reading UI file 'locationtable.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCATIONTABLE_H
#define UI_LOCATIONTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_locationTable
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QTableWidget *tableWidget;

    void setupUi(QWidget *locationTable)
    {
        if (locationTable->objectName().isEmpty())
            locationTable->setObjectName(QString::fromUtf8("locationTable"));
        locationTable->resize(867, 750);
        verticalLayout = new QVBoxLayout(locationTable);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(locationTable);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        tableWidget = new QTableWidget(locationTable);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(locationTable);

        QMetaObject::connectSlotsByName(locationTable);
    } // setupUi

    void retranslateUi(QWidget *locationTable)
    {
        locationTable->setWindowTitle(QCoreApplication::translate("locationTable", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("locationTable", "Load", nullptr));
    } // retranslateUi

};

namespace Ui {
    class locationTable: public Ui_locationTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCATIONTABLE_H
