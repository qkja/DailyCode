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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Test01Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Test01Class)
    {
        if (Test01Class->objectName().isEmpty())
            Test01Class->setObjectName(QString::fromUtf8("Test01Class"));
        Test01Class->resize(600, 400);
        menuBar = new QMenuBar(Test01Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Test01Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Test01Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Test01Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Test01Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Test01Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Test01Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Test01Class->setStatusBar(statusBar);

        retranslateUi(Test01Class);

        QMetaObject::connectSlotsByName(Test01Class);
    } // setupUi

    void retranslateUi(QMainWindow *Test01Class)
    {
        Test01Class->setWindowTitle(QCoreApplication::translate("Test01Class", "Test01", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Test01Class: public Ui_Test01Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST01_H
