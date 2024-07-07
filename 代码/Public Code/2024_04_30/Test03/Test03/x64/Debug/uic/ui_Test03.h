/********************************************************************************
** Form generated from reading UI file 'Test03.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST03_H
#define UI_TEST03_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "primarywindcutcirclediagramview.h"

QT_BEGIN_NAMESPACE

class Ui_Test03Class
{
public:
    QWidget *centralWidget;
    PrimaryWindCutCircleDiagramView *widget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Test03Class)
    {
        if (Test03Class->objectName().isEmpty())
            Test03Class->setObjectName(QString::fromUtf8("Test03Class"));
        Test03Class->resize(600, 400);
        centralWidget = new QWidget(Test03Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new PrimaryWindCutCircleDiagramView(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 40, 381, 241));
        Test03Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Test03Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 25));
        Test03Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Test03Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Test03Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Test03Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Test03Class->setStatusBar(statusBar);

        retranslateUi(Test03Class);

        QMetaObject::connectSlotsByName(Test03Class);
    } // setupUi

    void retranslateUi(QMainWindow *Test03Class)
    {
        Test03Class->setWindowTitle(QCoreApplication::translate("Test03Class", "Test03", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Test03Class: public Ui_Test03Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST03_H
