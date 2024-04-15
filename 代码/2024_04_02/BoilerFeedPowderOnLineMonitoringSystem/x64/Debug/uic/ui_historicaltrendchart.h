/********************************************************************************
** Form generated from reading UI file 'historicaltrendchart.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORICALTRENDCHART_H
#define UI_HISTORICALTRENDCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "historicallinechart.h"

QT_BEGIN_NAMESPACE

class Ui_HistoricalTrendChartClass
{
public:
    QWidget *centralWidget;
    HistoricalLineChart *widget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HistoricalTrendChartClass)
    {
        if (HistoricalTrendChartClass->objectName().isEmpty())
            HistoricalTrendChartClass->setObjectName(QString::fromUtf8("HistoricalTrendChartClass"));
        HistoricalTrendChartClass->resize(923, 557);
        centralWidget = new QWidget(HistoricalTrendChartClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new HistoricalLineChart(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(100, 0, 691, 491));
        HistoricalTrendChartClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HistoricalTrendChartClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 923, 26));
        HistoricalTrendChartClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(HistoricalTrendChartClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        HistoricalTrendChartClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(HistoricalTrendChartClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        HistoricalTrendChartClass->setStatusBar(statusBar);

        retranslateUi(HistoricalTrendChartClass);

        QMetaObject::connectSlotsByName(HistoricalTrendChartClass);
    } // setupUi

    void retranslateUi(QMainWindow *HistoricalTrendChartClass)
    {
        HistoricalTrendChartClass->setWindowTitle(QCoreApplication::translate("HistoricalTrendChartClass", "HistoricalTrendChart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistoricalTrendChartClass: public Ui_HistoricalTrendChartClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORICALTRENDCHART_H
