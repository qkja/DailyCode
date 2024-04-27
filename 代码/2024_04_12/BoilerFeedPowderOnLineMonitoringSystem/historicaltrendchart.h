#pragma once

#include <QMainWindow>
#include "ui_historicaltrendchart.h"
#include <iostream>
#include <iostream>
#include <QtCharts>
#include "resultdata.h"
#include <unordered_map>
#define REFRESH_TIME_HIS  5                                              // 数据5s来一次
#define TOTAL_TIME_HIS 120                                               // 保存120min的数据
#define NUMBER_OF_DATA_HIS   ((TOTAL_TIME_HIS*60)/REFRESH_TIME_HIS)      // 计算我们数据的个数

#define STAGE_TIME  30                                                   // 保存30min的数据
#define STAGE_FREQUENCY      ((STAGE_TIME*60)/REFRESH_TIME_HIS)          // 计算我们显示的个数

#define STEP_SIZE 20

#define WINDCHOICE_HIS 1
#define CONCENTRATIONCHOICE_HIS 2
#define TEMPERATUREONECHOICE_HIS 3
#define TEMPERATURETWOCHOICE_HIS 4
QT_BEGIN_NAMESPACE
namespace Ui
{
	class HistoricalTrendChartClass;
};
QT_END_NAMESPACE

class HistoricalTrendChart : public QMainWindow
{
	Q_OBJECT

public:
	HistoricalTrendChart(QWidget* parent = nullptr, ResultData* resultData = nullptr);
	~HistoricalTrendChart();
public:
	void init();
	void initMap();
	void updateData();
	void _updateData(int, const std::string&, int, int);
	void createChart();
private:
	Ui::HistoricalTrendChartClass* ui;
	ResultData* _resultData; // 收到的数据

	std::unordered_map<std::string, std::vector<double>> _wind_speed_map;         // 保存24个风速
	std::unordered_map<std::string, std::vector<double>> _concentration_map;      // 保存24个煤粉浓度
	std::unordered_map<std::string, std::vector<double>> _temperature_1_map;      // 保存24个温度1
	std::unordered_map<std::string, std::vector<double>> _temperature_2_map;      // 保存24个温度2

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

	int _left_wind;      // 风速左侧的范围
	int _right_wind;     // 风速右侧的范围

	int _left_concentration;      // 浓度左侧的范围
	int _right_concentration;     // 浓度右侧的范围

	int _left_temperature_1;      // 温度1左侧的范围
	int _right_temperature_1;     // 温度2右侧的范围

	int _left_temperature_2;      // 温度2左侧的范围
	int _right_temperature_2;     // 温度2右侧的范围
	bool _left_right_clickde;     // 点击了左侧或者右侧
};
