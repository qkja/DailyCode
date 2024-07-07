/********************************************************************************
** Form generated from reading UI file 'AlarmDatabase.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMDATABASE_H
#define UI_ALARMDATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlarmDatabaseClass
{
public:
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QLabel *label_cur;
    QLabel *label_total;
    QPushButton *pushButton_next;
    QPushButton *pushButton_up;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AlarmDatabaseClass)
    {
        if (AlarmDatabaseClass->objectName().isEmpty())
            AlarmDatabaseClass->setObjectName(QString::fromUtf8("AlarmDatabaseClass"));
        AlarmDatabaseClass->resize(1051, 567);
        centralWidget = new QWidget(AlarmDatabaseClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(90, 100, 311, 301));
        label_cur = new QLabel(centralWidget);
        label_cur->setObjectName(QString::fromUtf8("label_cur"));
        label_cur->setGeometry(QRect(600, 350, 72, 15));
        label_total = new QLabel(centralWidget);
        label_total->setObjectName(QString::fromUtf8("label_total"));
        label_total->setGeometry(QRect(820, 400, 72, 15));
        pushButton_next = new QPushButton(centralWidget);
        pushButton_next->setObjectName(QString::fromUtf8("pushButton_next"));
        pushButton_next->setGeometry(QRect(650, 130, 89, 24));
        pushButton_up = new QPushButton(centralWidget);
        pushButton_up->setObjectName(QString::fromUtf8("pushButton_up"));
        pushButton_up->setGeometry(QRect(650, 200, 89, 24));
        AlarmDatabaseClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AlarmDatabaseClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1051, 25));
        AlarmDatabaseClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AlarmDatabaseClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        AlarmDatabaseClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AlarmDatabaseClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AlarmDatabaseClass->setStatusBar(statusBar);

        retranslateUi(AlarmDatabaseClass);

        QMetaObject::connectSlotsByName(AlarmDatabaseClass);
    } // setupUi

    void retranslateUi(QMainWindow *AlarmDatabaseClass)
    {
        AlarmDatabaseClass->setWindowTitle(QCoreApplication::translate("AlarmDatabaseClass", "AlarmDatabase", nullptr));
        label_cur->setText(QCoreApplication::translate("AlarmDatabaseClass", "1", nullptr));
        label_total->setText(QCoreApplication::translate("AlarmDatabaseClass", "1", nullptr));
        pushButton_next->setText(QCoreApplication::translate("AlarmDatabaseClass", "\344\270\213", nullptr));
        pushButton_up->setText(QCoreApplication::translate("AlarmDatabaseClass", "\344\270\212", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AlarmDatabaseClass: public Ui_AlarmDatabaseClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMDATABASE_H
