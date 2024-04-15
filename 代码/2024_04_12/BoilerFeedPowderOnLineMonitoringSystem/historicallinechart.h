#pragma once

#include <QWidget>
#include <QtCharts>
#include <iostream>

QT_CHARTS_USE_NAMESPACE
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/qlineseries.h>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/qvalueaxis.h>
class HistoricalLineChart : public QWidget
{
	Q_OBJECT

public:
	HistoricalLineChart(QWidget *parent);
	~HistoricalLineChart();

private:
	QChart *_chart;
	QValueAxis *_x;
	QValueAxis *_y;

	QLineSeries *_line; // ����

	QChartView *_chartView;
};
