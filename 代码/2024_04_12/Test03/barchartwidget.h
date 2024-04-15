#pragma once

#include <QWidget>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/qvalueaxis.h>
#include <iostream>


QT_CHARTS_USE_NAMESPACE
QT_CHARTS_USE_NAMESPACE
class BarChartWidget : public QWidget
{
	Q_OBJECT

public:
	BarChartWidget(QWidget *parent);
	~BarChartWidget();

	void addXAxis();
	void addYAxis();
private:
	void init();
private:
	QChart *_chart;
	QBarSeries *_series;
	QChartView *_chartView;
	QBarSet *_first;
	QBarSet *_second;
	QBarSet *_third;
	QBarSet *_fourth;
};