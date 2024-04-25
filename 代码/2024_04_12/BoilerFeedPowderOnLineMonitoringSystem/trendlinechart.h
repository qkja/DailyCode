#pragma once

#include <QWidget>
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
class TrendLineChart : public QWidget
{
	Q_OBJECT

public:
	TrendLineChart(QWidget *parent);
	~TrendLineChart();
	void writeData(const std::string&, const std::vector<double>&);
	void writeData(const std::string&, const double&);
private:
	QChart *_chart;
	QValueAxis *_x;   
	QValueAxis* _y_wind;              // 风速Y轴
	QValueAxis* _y_concentration;     // 浓度Y轴
	QValueAxis* _y_temperature_1;     // 温度1 Y轴
	QValueAxis *_y_temperature_2;     // 温度2 Y轴
	QLineSeries* _line_wind;          // 风速折现
	QLineSeries* _line_concentration; // 浓度折现
	QLineSeries* _line_temperature_1; // 温度1折现
	QLineSeries *_line_temperature_2; // 温度2折现
	QChartView *_chartView;           // 视图

};
