/********************************************************************************
** Form generated from reading UI file 'trendchart.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRENDCHART_H
#define UI_TRENDCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrendChartClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TrendChartClass)
    {
        if (TrendChartClass->objectName().isEmpty())
            TrendChartClass->setObjectName(QString::fromUtf8("TrendChartClass"));
        TrendChartClass->resize(600, 400);
        menuBar = new QMenuBar(TrendChartClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        TrendChartClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TrendChartClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TrendChartClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TrendChartClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        TrendChartClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TrendChartClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TrendChartClass->setStatusBar(statusBar);

        retranslateUi(TrendChartClass);

        QMetaObject::connectSlotsByName(TrendChartClass);
    } // setupUi

    void retranslateUi(QMainWindow *TrendChartClass)
    {
        TrendChartClass->setWindowTitle(QCoreApplication::translate("TrendChartClass", "TrendChart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TrendChartClass: public Ui_TrendChartClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRENDCHART_H
