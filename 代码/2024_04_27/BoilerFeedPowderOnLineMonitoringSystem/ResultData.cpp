#include "ResultData.h"
ResultData::ResultData(QWidget* parent)
	: QWidget(parent)
{}

ResultData::~ResultData()
{}

void ResultData::distributeAllData(std::vector<struct Result> task)
{
	std::vector<struct BarPatternOfWindPowder> bar; // 棒型风粉图 数据
	std::vector<struct TendencyChartData> tendency; // 趋势图数据
	for (int i = 0; i < task.size(); i++)
	{
		// 单个保存数据
		//struct BarPatternOfWindPowder barData;
		//barData._wind_speed = task[i]._wind_speed;
		//barData._concentration = task[i]._pulverized_coal_concentration;
		//barData._temperature = task[i]._temperature;
		//bar.push_back(barData);

		//struct TendencyChartData tendencyData;                  // 这里有一个温度我不太确定,暂时充当一下
		//tendencyData._category = i;                            // 类别就是我们是24个数据的哪一个
		//tendencyData._wind_speed = task[i]._wind_speed + qrand() % 50;
		//tendencyData._concentration = task[i]._pulverized_coal_concentration + qrand() % 50;
		//tendencyData._temperature_1 = task[i]._temperature + qrand()*qrand()%100;
		//tendencyData._temperature_2 = task[i]._temperature + qrand() % 50;
		//tendency.push_back(tendencyData);

		//这是一个尝试
		struct BarPatternOfWindPowder barData;
		barData._wind_speed = qrand() % 100;
		barData._concentration = qrand() % 100;
		barData._temperature = qrand() % 100;
		bar.push_back(barData);

		struct TendencyChartData tendencyData;                  // 这里有一个温度我不太确定,暂时充当一下
		tendencyData._category = i;                             // 类别就是我们是24个数据的哪一个
		tendencyData._wind_speed = qrand() % 100;
		tendencyData._concentration = qrand() % 100;
		tendencyData._temperature_1 = qrand() % 100;
		tendencyData._temperature_2 = qrand() % 100;
		tendency.push_back(tendencyData);
	}
	emit barPatternOfWindPowderSignals(bar); // 发送 棒型风粉图 数据
	emit tendencyChartDataSignals(tendency); // 发送趋势图数据
}

// 报警数据
void  ResultData::distributeAlarmData(std::vector<struct AlertData> data)
{
	/*for (int i = 0; i < data.size(); i++)
	{
		alarmDataSignals(data[i]);
	}*/

	struct AlertData v;
	static int i = 1;

	v._sensor_name = "测试" + std::to_string(i);
	v._alarm_type = "测试";
	v._initial_time_point = "测试";
	v._data = "测试";
	v._end_time_point = "测试";
	++i;
	alarmDataSignals(v);
}

void ResultData::distributeChannelData(std::vector<struct ChannelData> data)
{
	/*for (int i = 0; i < data.size(); i++)
	{
		channeDataSignals(data[i]);
	}*/
	struct ChannelData v;
	static int i = 1;
	v._name = "测试" + std::to_string(i);
	v._serial_number = "测试";
	v._slate_number = "测试";
	v._channel_number = "测试";
	v._type = "测试";
	v._range = "测试";
	v._measured_value = "测试";
	v._engineering_value = "测试";
	++i;
	channeDataSignals(v);
}