#include "ResultData.h"
#include <Windows.h>
ResultData::ResultData(QWidget* parent)
	: QWidget(parent)
{}

ResultData::~ResultData()
{}

void ResultData::distributeData(Task task)
{
	std::vector<struct BarPatternOfWindPowder> bar; // 棒型风粉图 数据
	std::vector<struct TendencyChartData> tendency; // 趋势图数据
	for (int i = 0; i < task._primary_result.size(); i++)
	{
		
		struct BarPatternOfWindPowder barData;
		barData._wind_speed = qrand() % 100;
		barData._concentration = qrand() % 100;
		barData._temperature = qrand() % 100;
		bar.push_back(barData);

		struct TendencyChartData tendencyData;                  // 这里有一个温度我不太确定,暂时充当一下
		tendencyData._category = i;                            // 类别就是我们是24个数据的哪一个
		tendencyData._wind_speed = qrand() % 100;
		tendencyData._concentration = qrand() % 100;
		tendencyData._temperature_1 = qrand() % 100;
		tendencyData._temperature_2 = qrand() % 100;
		tendency.push_back(tendencyData);
	}
	//emit barPatternOfWindPowderSignals(bar); // 发送 棒型风粉图 数据
	//emit tendencyChartDataSignals(tendency); // 发送趋势图数据
}