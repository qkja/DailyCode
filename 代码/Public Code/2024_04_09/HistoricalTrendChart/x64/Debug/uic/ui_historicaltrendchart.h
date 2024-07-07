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
#include <QtWidgets/QWidget>
#include "historicallinechart.h"

QT_BEGIN_NAMESPACE

class Ui_HistoricalTrendChartClass
{
public:
    HistoricalLineChart *widget;

    void setupUi(QWidget *HistoricalTrendChartClass)
    {
        if (HistoricalTrendChartClass->objectName().isEmpty())
            HistoricalTrendChartClass->setObjectName(QString::fromUtf8("HistoricalTrendChartClass"));
        HistoricalTrendChartClass->resize(926, 622);
        widget = new HistoricalLineChart(HistoricalTrendChartClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(130, 70, 691, 491));

        retranslateUi(HistoricalTrendChartClass);

        QMetaObject::connectSlotsByName(HistoricalTrendChartClass);
    } // setupUi

    void retranslateUi(QWidget *HistoricalTrendChartClass)
    {
        HistoricalTrendChartClass->setWindowTitle(QCoreApplication::translate("HistoricalTrendChartClass", "HistoricalTrendChart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistoricalTrendChartClass: public Ui_HistoricalTrendChartClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORICALTRENDCHART_H
