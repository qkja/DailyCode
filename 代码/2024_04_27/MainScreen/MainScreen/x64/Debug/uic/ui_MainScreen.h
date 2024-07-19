/********************************************************************************
** Form generated from reading UI file 'MainScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCREEN_H
#define UI_MAINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScreenClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainScreenClass)
    {
        if (MainScreenClass->objectName().isEmpty())
            MainScreenClass->setObjectName(QString::fromUtf8("MainScreenClass"));
        MainScreenClass->resize(600, 400);
        menuBar = new QMenuBar(MainScreenClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        MainScreenClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainScreenClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainScreenClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MainScreenClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainScreenClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainScreenClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainScreenClass->setStatusBar(statusBar);

        retranslateUi(MainScreenClass);

        QMetaObject::connectSlotsByName(MainScreenClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainScreenClass)
    {
        MainScreenClass->setWindowTitle(QCoreApplication::translate("MainScreenClass", "MainScreen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainScreenClass: public Ui_MainScreenClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
