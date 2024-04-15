/********************************************************************************
** Form generated from reading UI file 'channeldatabase.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANNELDATABASE_H
#define UI_CHANNELDATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChannelDatabaseClass
{
public:
    QPushButton *quit_pushButton;
    QTableWidget *tableWidget;

    void setupUi(QWidget *ChannelDatabaseClass)
    {
        if (ChannelDatabaseClass->objectName().isEmpty())
            ChannelDatabaseClass->setObjectName(QString::fromUtf8("ChannelDatabaseClass"));
        ChannelDatabaseClass->resize(1252, 627);
        quit_pushButton = new QPushButton(ChannelDatabaseClass);
        quit_pushButton->setObjectName(QString::fromUtf8("quit_pushButton"));
        quit_pushButton->setGeometry(QRect(1070, 520, 131, 51));
        tableWidget = new QTableWidget(ChannelDatabaseClass);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        if (tableWidget->rowCount() < 10)
            tableWidget->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem18);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(40, 100, 1181, 411));

        retranslateUi(ChannelDatabaseClass);

        QMetaObject::connectSlotsByName(ChannelDatabaseClass);
    } // setupUi

    void retranslateUi(QWidget *ChannelDatabaseClass)
    {
        ChannelDatabaseClass->setWindowTitle(QCoreApplication::translate("ChannelDatabaseClass", "ChannelDatabase", nullptr));
        quit_pushButton->setText(QCoreApplication::translate("ChannelDatabaseClass", "\345\205\263\351\227\255", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ChannelDatabaseClass", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ChannelDatabaseClass", "\346\265\213\347\202\271\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ChannelDatabaseClass", "\346\265\213\347\202\271\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ChannelDatabaseClass", "\346\235\277\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ChannelDatabaseClass", "\351\200\232\351\201\223\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ChannelDatabaseClass", "\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("ChannelDatabaseClass", "\346\265\213\347\202\271\351\207\217\347\250\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("ChannelDatabaseClass", "\345\256\236\346\265\213\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("ChannelDatabaseClass", "\345\267\245\347\250\213\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("ChannelDatabaseClass", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("ChannelDatabaseClass", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("ChannelDatabaseClass", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("ChannelDatabaseClass", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("ChannelDatabaseClass", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("ChannelDatabaseClass", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("ChannelDatabaseClass", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("ChannelDatabaseClass", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("ChannelDatabaseClass", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("ChannelDatabaseClass", "\346\226\260\345\273\272\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChannelDatabaseClass: public Ui_ChannelDatabaseClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANNELDATABASE_H
