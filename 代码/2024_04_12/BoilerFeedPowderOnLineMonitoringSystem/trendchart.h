#pragma once

#include <QMainWindow>
#include "ui_trendchart.h"
#include <iostream>
#include "resultdata.h"
#include <unordered_map>
#define REFRESH_TIME  10       // 数据10s来一次
#define TOTAL_TIME 30          // 保存30min的数据
#define NUMBER_OF_DATA   ((TOTAL_TIME*10)/10)   // 计算我们数据的个数

QT_BEGIN_NAMESPACE
namespace Ui
{
	class TrendChartClass;
};
QT_END_NAMESPACE

class TrendChart : public QMainWindow
{
	Q_OBJECT

public:
	TrendChart(QWidget *parent = nullptr, ResultData* resultData = nullptr);
	~TrendChart();
private:
	void init();
private:

	Ui::TrendChartClass *ui;
	ResultData* _resultData;
	std::unordered_map<std::string, std::vector<double>> _wind_speed_map;
	std::unordered_map<std::string, std::vector<double>> _concentration_map;
	std::unordered_map<std::string, std::vector<double>> _temperature_1;
	std::unordered_map<std::string, std::vector<double>> _temperature_2;
};
