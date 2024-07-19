#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_trendchart.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TrendChartClass; };
QT_END_NAMESPACE

class TrendChart : public QMainWindow
{
    Q_OBJECT

public:
    TrendChart(QWidget *parent = nullptr);
    ~TrendChart();

private:
    Ui::TrendChartClass *ui;
};
