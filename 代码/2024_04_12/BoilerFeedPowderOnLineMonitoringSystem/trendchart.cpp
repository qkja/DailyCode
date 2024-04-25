#include "trendchart.h"

TrendChart::TrendChart(QWidget *parent, ResultData* resultData)
	: QMainWindow(parent)
	, ui(new Ui::TrendChartClass())
	, _resultData(resultData)
{
	ui->setupUi(this);
	std::cout << "TrendChart()" << std::endl;

	init();
	/*if (_resultData == nullptr)
	{
		std::cout << "00000000000000000" << std::endl;
	}*/

	connect(_resultData, &ResultData::tendencyChartDataSignals, [=](std::vector<struct TendencyChartData> data) {
		
		// ������������, ���в��
		for (int i = 0; i < data.size(); ++i)
		{
			int j = i + 1;
			std::string str1 = std::to_string(j);
			std::string str2 = std::to_string(j);
			std::string str3 = std::to_string(j);
			std::string str4 = std::to_string(j);
			
			if (NUMBER_OF_DATA <= _wind_speed_map[str1].size())   _wind_speed_map[str1].erase(_wind_speed_map[str1].begin());          // ��������,��Ҫ���һ������, ������һ������
			if (NUMBER_OF_DATA <= _concentration_map[str2].size())   _concentration_map[str2].erase(_concentration_map[str2].begin()); // ��������,��Ҫ���һ������, ������һ������
			if (NUMBER_OF_DATA <= _temperature_1[str3].size())   _temperature_1[str3].erase(_temperature_1[str3].begin());             // ��������,��Ҫ���һ������, ������һ������
			if (NUMBER_OF_DATA <= _temperature_2[str4].size())   _temperature_2[str4].erase(_temperature_2[str4].begin());             // ��������,��Ҫ���һ������, ������һ������


			

			// �������
			_wind_speed_map[str1].push_back(data[i]._wind_speed);
			_concentration_map[str2].push_back(data[i]._concentration);
			_temperature_1[str3].push_back(data[i]._temperature_1);
			_temperature_2[str4].push_back(data[i]._temperature_2);
		}
		
		// ��������, �����������ѡ����ָ��ˢ������
		std::string windStr = ui->wind_speed->currentText().toStdString();
		std::string concentrationStr = ui->concentration->currentText().toStdString();
		std::string temperatureOneStr = ui->temperature_1->currentText().toStdString();
		std::string temperatureTwoStr = ui->temperature_2->currentText().toStdString();
		
		
		
		
		// ����
		/*if (windStr == std::string("1"))
		{
			std::cout <<  "1111111111111111111" << std::endl;
		}*/

		std::cout << "text" << std::endl;
		ui->widget->writeData();

		});
}

TrendChart::~TrendChart()
{
	std::cout << "~TrendChart()" << std::endl;
	delete ui;
}

void TrendChart::init()
{
	// �Ȳ���һЩ����
	for (int i = 1; i <= 24; i++)
	{
		std::string str1 = std::to_string(i);
		std::string str2 = std::to_string(i);
		std::string str3 = std::to_string(i);
		std::string str4 = std::to_string(i);

		_wind_speed_map[str1];
		_concentration_map[str2];
		_temperature_1[str3];
		_temperature_2[str4];
	}
}
