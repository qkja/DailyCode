/********************************************************************************
** Form generated from reading UI file 'Test04.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST04_H
#define UI_TEST04_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "mywidget.h"

QT_BEGIN_NAMESPACE

class Ui_Test04Class
{
public:
    QWidget *centralWidget;
    MyWidget *widget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Test04Class)
    {
        if (Test04Class->objectName().isEmpty())
            Test04Class->setObjectName(QString::fromUtf8("Test04Class"));
        Test04Class->resize(600, 400);
        centralWidget = new QWidget(Test04Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new MyWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(110, 60, 301, 181));
        Test04Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Test04Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        Test04Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Test04Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Test04Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Test04Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Test04Class->setStatusBar(statusBar);

        retranslateUi(Test04Class);

        QMetaObject::connectSlotsByName(Test04Class);
    } // setupUi

    void retranslateUi(QMainWindow *Test04Class)
    {
        Test04Class->setWindowTitle(QCoreApplication::translate("Test04Class", "Test04", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Test04Class: public Ui_Test04Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST04_H
