#pragma once

#include <QtWidgets/QWidget>
#include "ui_historicaltrendchart.h"

QT_BEGIN_NAMESPACE
namespace Ui { class HistoricalTrendChartClass; };
QT_END_NAMESPACE

class HistoricalTrendChart : public QWidget
{
    Q_OBJECT

public:
    HistoricalTrendChart(QWidget *parent = nullptr);
    ~HistoricalTrendChart();
private:
    Ui::HistoricalTrendChartClass *ui;
   
};
