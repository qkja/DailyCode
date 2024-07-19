#pragma once

#include <QWidget>
#include "ui_trendlinechart.h"
#include <QtCharts>

QT_BEGIN_NAMESPACE
namespace Ui { class TrendLineChartClass; };
QT_END_NAMESPACE

class TrendLineChart : public QWidget
{
	Q_OBJECT

public:
	TrendLineChart(QWidget *parent = nullptr);
	~TrendLineChart();
	void CreateChartFunc();
private:
	Ui::TrendLineChartClass *ui;
	QChart* _chart;
	QValueAxis* _x;
	QValueAxis* _y_wind;              // 风速Y轴
	QValueAxis* _y_concentration;     // 浓度Y轴
	QValueAxis* _y_temperature_1;     // 温度1 Y轴
	QValueAxis* _y_temperature_2;     // 温度2 Y轴
	QLineSeries* _line_wind;          // 风速折现
	QLineSeries* _line_concentration; // 浓度折现
	QLineSeries* _line_temperature_1; // 温度1折现
	QLineSeries* _line_temperature_2; // 温度2折现
	QChartView* _chartView;           // 视图
};
