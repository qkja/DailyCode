#include "ResultData.h"
ResultData::ResultData(QWidget* parent)
	: QWidget(parent)
{}

ResultData::~ResultData()
{}

void ResultData::distributeAllData(std::vector<struct Result> task)
{
	std::vector<struct BarPatternOfWindPowder> bar; // ���ͷ��ͼ ����
	std::vector<struct TendencyChartData> tendency; // ����ͼ����
	for (int i = 0; i < task.size(); i++)
	{
		// ������������
		//struct BarPatternOfWindPowder barData;
		//barData._wind_speed = task[i]._wind_speed;
		//barData._concentration = task[i]._pulverized_coal_concentration;
		//barData._temperature = task[i]._temperature;
		//bar.push_back(barData);

		//struct TendencyChartData tendencyData;                  // ������һ���¶��Ҳ�̫ȷ��,��ʱ�䵱һ��
		//tendencyData._category = i;                            // ������������24�����ݵ���һ��
		//tendencyData._wind_speed = task[i]._wind_speed + qrand() % 50;
		//tendencyData._concentration = task[i]._pulverized_coal_concentration + qrand() % 50;
		//tendencyData._temperature_1 = task[i]._temperature + qrand()*qrand()%100;
		//tendencyData._temperature_2 = task[i]._temperature + qrand() % 50;
		//tendency.push_back(tendencyData);

		//����һ������
		struct BarPatternOfWindPowder barData;
		barData._wind_speed = qrand() % 100;
		barData._concentration = qrand() % 100;
		barData._temperature = qrand() % 100;
		bar.push_back(barData);

		struct TendencyChartData tendencyData;                  // ������һ���¶��Ҳ�̫ȷ��,��ʱ�䵱һ��
		tendencyData._category = i;                             // ������������24�����ݵ���һ��
		tendencyData._wind_speed = qrand() % 100;
		tendencyData._concentration = qrand() % 100;
		tendencyData._temperature_1 = qrand() % 100;
		tendencyData._temperature_2 = qrand() % 100;
		tendency.push_back(tendencyData);
	}
	emit barPatternOfWindPowderSignals(bar); // ���� ���ͷ��ͼ ����
	emit tendencyChartDataSignals(tendency); // ��������ͼ����
}

// ��������
void  ResultData::distributeAlarmData(std::vector<struct AlertData> data)
{
	/*for (int i = 0; i < data.size(); i++)
	{
		alarmDataSignals(data[i]);
	}*/

	struct AlertData v;
	static int i = 1;

	v._sensor_name = "����" + std::to_string(i);
	v._alarm_type = "����";
	v._initial_time_point = "����";
	v._data = "����";
	v._end_time_point = "����";
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
	v._name = "����" + std::to_string(i);
	v._serial_number = "����";
	v._slate_number = "����";
	v._channel_number = "����";
	v._type = "����";
	v._range = "����";
	v._measured_value = "����";
	v._engineering_value = "����";
	++i;
	channeDataSignals(v);
}