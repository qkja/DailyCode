/********************************************************************************
** Form generated from reading UI file 'Test02.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST02_H
#define UI_TEST02_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Test02Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Test02Class)
    {
        if (Test02Class->objectName().isEmpty())
            Test02Class->setObjectName(QString::fromUtf8("Test02Class"));
        Test02Class->resize(600, 400);
        menuBar = new QMenuBar(Test02Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Test02Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Test02Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Test02Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Test02Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Test02Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Test02Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Test02Class->setStatusBar(statusBar);

        retranslateUi(Test02Class);

        QMetaObject::connectSlotsByName(Test02Class);
    } // setupUi

    void retranslateUi(QMainWindow *Test02Class)
    {
        Test02Class->setWindowTitle(QCoreApplication::translate("Test02Class", "Test02", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Test02Class: public Ui_Test02Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST02_H
