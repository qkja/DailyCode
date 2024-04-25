#pragma once
#include "Task.hpp"
#include <QWidget>
// 棒型风粉图数据
struct BarPatternOfWindPowder
{

	double _wind_speed;     // 风速
	double	_concentration; // 浓度
	double _temperature;    // 温度
};

struct TendencyChartData
{
	int    _category;       // 类别
	double _wind_speed;     // 风速
	double _concentration;  // 浓度
	double _temperature_1;  // 温度1
	double _temperature_2;  // 温度2
};

class ResultData  : public QWidget
{
	Q_OBJECT

public:
	ResultData(QWidget *parent = nullptr);
	~ResultData();
signals:
	// 棒型风粉图数据
	void barPatternOfWindPowderSignals(std::vector<struct BarPatternOfWindPowder>);
	// 趋势图
	void tendencyChartDataSignals(std::vector<struct TendencyChartData>);
public slots:
	void distributeData(Task);
};
