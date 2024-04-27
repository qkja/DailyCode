#include "ResultData.h"
#include <Windows.h>
ResultData::ResultData(QWidget* parent)
	: QWidget(parent)
{}

ResultData::~ResultData()
{}

void ResultData::distributeData(Task task)
{
	std::vector<struct BarPatternOfWindPowder> bar; // ���ͷ��ͼ ����
	std::vector<struct TendencyChartData> tendency; // ����ͼ����
	for (int i = 0; i < task._primary_result.size(); i++)
	{
		// ������������
		/*struct BarPatternOfWindPowder barData;
		barData._wind_speed = task._primary_result[i]._wind_speed;
		barData._concentration = task._primary_result[i]._pulverized_coal_concentration;
		barData._temperature = task._primary_result[i]._temperature;
		bar.push_back(barData);*/

		//struct TendencyChartData tendencyData;                  // ������һ���¶��Ҳ�̫ȷ��,��ʱ�䵱һ��
		//tendencyData._category = i;                            // ������������24�����ݵ���һ��
		//tendencyData._wind_speed = task._primary_result[i]._wind_speed + qrand() % 50;
		//tendencyData._concentration = task._primary_result[i]._pulverized_coal_concentration + qrand() % 50;
		//tendencyData._temperature_1 = task._primary_result[i]._temperature + qrand()*qrand()%100;
		//tendencyData._temperature_2 = task._primary_result[i]._temperature + qrand() % 50;
		//tendency.push_back(tendencyData);

		// ����һ������
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