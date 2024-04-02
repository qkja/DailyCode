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

QT_BEGIN_NAMESPACE

class Ui_HistoricalTrendChartClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HistoricalTrendChartClass)
    {
        if (HistoricalTrendChartClass->objectName().isEmpty())
            HistoricalTrendChartClass->setObjectName(QString::fromUtf8("HistoricalTrendChartClass"));
        HistoricalTrendChartClass->resize(600, 400);
        menuBar = new QMenuBar(HistoricalTrendChartClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        HistoricalTrendChartClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(HistoricalTrendChartClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        HistoricalTrendChartClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(HistoricalTrendChartClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        HistoricalTrendChartClass->setCentralWidget(centralWidget);
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
