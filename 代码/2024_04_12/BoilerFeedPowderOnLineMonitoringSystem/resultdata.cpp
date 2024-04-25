#include "resultdata.h"
#include <Windows.h>
ResultData::ResultData(QWidget *parent)
	: QWidget(parent)
{}

ResultData::~ResultData()
{}

void ResultData::distributeData(Task task)
{
	// 处理 棒型风粉图

	// 这是一个测试
	/*for (int j = 0; j < 10; j++)
	{
		std::vector<struct BarPatternOfWindPowder> bar;
		for (int i = 0; i < task._primary_result.size(); i++)
		{
			struct BarPatternOfWindPowder data;
			qreal newValue1 = qrand() % 10;
			qreal newValue2 = qrand() % 10;
			qreal newValue3 = qrand() % 10;


			data._wind_speed = newValue1;
			data._concentration = newValue2;
			data._temperature = newValue3;
			
			bar.push_back(data);
		}
		emit barPatternOfWindPowderSignals(bar);
		std::cout << "send " << j + 1 << std::endl;
	}*/

	
	std::vector<struct BarPatternOfWindPowder> bar; // 棒型风粉图 数据
	std::vector<struct TendencyChartData> tendency; // 趋势图数据
	for (int i = 0; i < task._primary_result.size(); i++)
	{
		// 单个保存数据
		struct BarPatternOfWindPowder barData;
		barData._wind_speed = task._primary_result[i]._wind_speed;
		barData._concentration = task._primary_result[i]._pulverized_coal_concentration;
		barData._temperature = task._primary_result[i]._temperature;
		bar.push_back(barData);


		struct TendencyChartData tendencyData;// 这里有一个温度我不太确定,暂时充当一下
		tendencyData._category = i;
		tendencyData._wind_speed = task._primary_result[i]._wind_speed;
		tendencyData._temperature_1 = task._primary_result[i]._temperature;
		tendencyData._temperature_2 = task._primary_result[i]._temperature;
		tendency.push_back(tendencyData);
	}
	//emit barPatternOfWindPowderSignals(bar); // 发送 棒型风粉图 数据
	emit tendencyChartDataSignals(tendency); // 发送趋势图数据
}											 