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
		
		struct BarPatternOfWindPowder barData;
		barData._wind_speed = qrand() % 100;
		barData._concentration = qrand() % 100;
		barData._temperature = qrand() % 100;
		bar.push_back(barData);

		struct TendencyChartData tendencyData;                  // ������һ���¶��Ҳ�̫ȷ��,��ʱ�䵱һ��
		tendencyData._category = i;                            // ������������24�����ݵ���һ��
		tendencyData._wind_speed = qrand() % 100;
		tendencyData._concentration = qrand() % 100;
		tendencyData._temperature_1 = qrand() % 100;
		tendencyData._temperature_2 = qrand() % 100;
		tendency.push_back(tendencyData);
	}
	//emit barPatternOfWindPowderSignals(bar); // ���� ���ͷ��ͼ ����
	//emit tendencyChartDataSignals(tendency); // ��������ͼ����
}