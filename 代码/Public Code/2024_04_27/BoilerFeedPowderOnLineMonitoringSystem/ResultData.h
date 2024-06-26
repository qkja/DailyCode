#pragma once

#include "Task.h"
#include <QWidget>
#include "ChannelData.h"
#include "AlertData.h"

/*
* 由于子线程计算的数据无法直接给折线图,此时这里多上一步
* 将子线程结算的结果放在这里,然后进行派发
*/

// 棒型风粉图数据
struct BarPatternOfWindPowder
{
	double _wind_speed;     // 风速
	double	_concentration; // 浓度
	double _temperature;    // 温度
};
// 折线图数据
struct TendencyChartData
{
	int    _category;       // 类别
	double _wind_speed;     // 风速
	double _concentration;  // 浓度
	double _temperature_1;  // 温度1
	double _temperature_2;  // 温度2
};

class ResultData : public QWidget
{
	Q_OBJECT

public:
	ResultData(QWidget* parent = nullptr);
	~ResultData();
signals:
	// 棒型风粉图数据
	void barPatternOfWindPowderSignals(const std::vector<struct BarPatternOfWindPowder>&);
	// 趋势图
	void tendencyChartDataSignals(const std::vector<struct TendencyChartData>&);
	void alarmDataSignals(const struct AlertData&);
	void channeDataSignals(const struct ChannelData&);
public slots:
	// 将解析后的数据拿出来,进行派发
	void distributeAllData(std::vector<struct Result>);
	void distributeAlarmData(std::vector<struct AlertData>);
	void distributeChannelData(std::vector<struct ChannelData>);
};
