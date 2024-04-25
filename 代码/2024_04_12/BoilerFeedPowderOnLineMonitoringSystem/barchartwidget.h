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
	void writeData(int index, double value);
	void addYAxis(int min_imum, int max_imum, int upper_limit,int lower_limit);
private:
	void addXAxis();
	void init();
private:
	QChart *_chart;   
	QBarSeries *_series;
	QChartView *_chartView;
	QBarSet * _qBarSet;
	QBarCategoryAxis* _axisX;
	QValueAxis* _axisY;
};
