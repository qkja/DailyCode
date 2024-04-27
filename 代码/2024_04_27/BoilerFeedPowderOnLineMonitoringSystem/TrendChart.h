#pragma once

#include <QMainWindow>
#include "ui_TrendChart.h"
#include <iostream>
#include <QtCharts>
#include "ResultData.h"
#include <unordered_map>

#define REFRESH_TIME  5                                   // 数据5s来一次
#define TOTAL_TIME 30                                     // 保存30min的数据
#define NUMBER_OF_DATA   ((TOTAL_TIME*60)/REFRESH_TIME)   // 计算我们数据的个数

#define WINDCHOICE 1
#define CONCENTRATIONCHOICE 2
#define TEMPERATUREONECHOICE 3
#define TEMPERATURETWOCHOICE 4
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// 该指令仅支持VS环境
#endif
QT_BEGIN_NAMESPACE
namespace Ui { class TrendChartClass; };
QT_END_NAMESPACE

class TrendChart : public QMainWindow
{
	Q_OBJECT

public:
	TrendChart(QWidget* parent = nullptr, ResultData* resultData = nullptr);
	~TrendChart();
	void init();

signals:
	void trendChartCloseSignals();
private:
	void closeEvent(QCloseEvent*);
	void initMap();
	void updateData();
	void createChart();
	void _updateData(int, const std::string&, bool);
private:
	Ui::TrendChartClass* ui;
	ResultData* _result_data; // 收到的数据
	std::unordered_map<std::string, std::vector<double>> _wind_speed_map;     // 保存24个风速
	std::unordered_map<std::string, std::vector<double>> _concentration_map;  // 保存24个煤粉浓度
	std::unordered_map<std::string, std::vector<double>> _temperature_1;      // 保存24个温度1
	std::unordered_map<std::string, std::vector<double>> _temperature_2;      // 保存24个温度2

	QChartView* _chartView;           // QChartView 用于展示 QChart
	QChart* _chart;                   // QChart 则容纳和管理一个或多个数据系列
	QValueAxis* _x;                   // X轴
	QValueAxis* _y_wind;              // 风速Y轴
	QValueAxis* _y_concentration;     // 浓度Y轴
	QValueAxis* _y_temperature_1;     // 温度1 Y轴
	QValueAxis* _y_temperature_2;     // 温度2 Y轴
	QLineSeries* _line_wind;          // 风速折线
	QLineSeries* _line_concentration; // 浓度折线
	QLineSeries* _line_temperature_1; // 温度1折线
	QLineSeries* _line_temperature_2; // 温度2折线
};
