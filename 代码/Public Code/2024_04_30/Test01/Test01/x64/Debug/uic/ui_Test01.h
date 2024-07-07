/********************************************************************************
** Form generated from reading UI file 'Test01.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST01_H
#define UI_TEST01_H

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

class Ui_Test01Class
{
public:
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Test01Class)
    {
        if (Test01Class->objectName().isEmpty())
            Test01Class->setObjectName(QString::fromUtf8("Test01Class"));
        Test01Class->resize(1077, 572);
        centralWidget = new QWidget(Test01Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(40, 30, 901, 291));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 400, 72, 15));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(300, 410, 72, 15));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(600, 410, 89, 24));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(840, 430, 89, 24));
        Test01Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Test01Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1077, 25));
        Test01Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Test01Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Test01Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Test01Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Test01Class->setStatusBar(statusBar);

        retranslateUi(Test01Class);

        QMetaObject::connectSlotsByName(Test01Class);
    } // setupUi

    void retranslateUi(QMainWindow *Test01Class)
    {
        Test01Class->setWindowTitle(QCoreApplication::translate("Test01Class", "Test01", nullptr));
        label->setText(QCoreApplication::translate("Test01Class", "1", nullptr));
        label_2->setText(QCoreApplication::translate("Test01Class", "1", nullptr));
        pushButton->setText(QCoreApplication::translate("Test01Class", "\344\270\213 ", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Test01Class", "\344\270\212", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Test01Class: public Ui_Test01Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST01_H
