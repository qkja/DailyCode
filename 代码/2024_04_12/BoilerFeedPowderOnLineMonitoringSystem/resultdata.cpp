#include "resultdata.h"
#include <Windows.h>
ResultData::ResultData(QWidget *parent)
	: QWidget(parent)
{}

ResultData::~ResultData()
{}

void ResultData::distributeData(Task task)
{
	// ���� ���ͷ��ͼ

	// ����һ������
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

	
	std::vector<struct BarPatternOfWindPowder> bar; // ���ͷ��ͼ ����
	std::vector<struct TendencyChartData> tendency; // ����ͼ����
	for (int i = 0; i < task._primary_result.size(); i++)
	{
		// ������������
		struct BarPatternOfWindPowder barData;
		barData._wind_speed = task._primary_result[i]._wind_speed;
		barData._concentration = task._primary_result[i]._pulverized_coal_concentration;
		barData._temperature = task._primary_result[i]._temperature;
		bar.push_back(barData);


		struct TendencyChartData tendencyData;// ������һ���¶��Ҳ�̫ȷ��,��ʱ�䵱һ��
		tendencyData._category = i;
		tendencyData._wind_speed = task._primary_result[i]._wind_speed;
		tendencyData._temperature_1 = task._primary_result[i]._temperature;
		tendencyData._temperature_2 = task._primary_result[i]._temperature;
		tendency.push_back(tendencyData);
	}
	//emit barPatternOfWindPowderSignals(bar); // ���� ���ͷ��ͼ ����
	emit tendencyChartDataSignals(tendency); // ��������ͼ����
}											 