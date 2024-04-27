#include "RodTypeWindPowderDiagram.h"
RodTypeWindPowderDiagram::RodTypeWindPowderDiagram(QWidget* parent, ResultData* result_data)
	: QWidget(parent)
	, ui(new Ui::RodTypeWindPowderDiagramClass())
	, _result_data(result_data)
	, _wind_speed_view(nullptr)
	, _pulverized_coal_concentration_view(nullptr)
	, _temperature_view(nullptr)
{
	ui->setupUi(this);
	std::cout << "RodTypeWindPowderDiagram()" << std::endl;
	init();
}

RodTypeWindPowderDiagram::~RodTypeWindPowderDiagram()
{
	std::cout << "~RodTypeWindPowderDiagram()" << std::endl;
	delete ui;
}

void RodTypeWindPowderDiagram::init()
{
	this->setWindowTitle("���ͷ��ͼ");
	createChart();
	updateData();
}

void RodTypeWindPowderDiagram::closeEvent(QCloseEvent*)
{
	emit rodTypeWindPowderDiagramCloseSignals();
}

void RodTypeWindPowderDiagram::updateData()
{
	connect(_result_data, &ResultData::barPatternOfWindPowderSignals, [=](const std::vector<struct BarPatternOfWindPowder>& data) {
		std::vector<double> v1; // ����24������
		std::vector<double> v2; // ����24��Ũ��
		std::vector<double> v3; // ����24���¶�

		for (int i = 0; i < data.size(); i++)
		{
			v1.push_back(data[i]._wind_speed);
			v2.push_back(data[i]._concentration);
			v3.push_back(data[i]._temperature);
		}
		_wind_speed_view->writeData(v1);
		_pulverized_coal_concentration_view->writeData(v2);
		_temperature_view->writeData(v3);
		});
}

void RodTypeWindPowderDiagram::createChart()
{
	_wind_speed_view = new BarChartWidget(this);
	_pulverized_coal_concentration_view = new BarChartWidget(this);
	_temperature_view = new BarChartWidget(this);

	int totalViewHeight = this->height();
	int totalViewwidth = this->width();

	int oneViewHeight = 351;
	int oneViewWidth = 1381;

	// ������� ��ͼŪ����,�Լ����ð�
	// ����ͼ��
	_wind_speed_view->createChart(oneViewWidth, oneViewHeight, 70, 20, "windSpeed");
	_pulverized_coal_concentration_view->createChart(oneViewWidth, oneViewHeight, 70, 410, "pulverizedCoalConcentration");
	_temperature_view->createChart(oneViewWidth, oneViewHeight, 70, 780, "temperature");

	// ���÷�Χ

	_wind_speed_view->setRange(0, 100);
	_pulverized_coal_concentration_view->setRange(0, 100);
	_temperature_view->setRange(0, 100);
}