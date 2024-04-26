#include "rodtypewindpowderdiagram.h"
#include <windows.h>
#include <qtimer.h>
RodTypeWindPowderDiagram::RodTypeWindPowderDiagram(QWidget* parent, ResultData* result_data)
	: QMainWindow(parent)
	, ui(new Ui::RodTypeWindPowderDiagramClass())
	, _result_data(result_data)
{
	std::cout << "RodTypeWindPowderDiagram()" << std::endl;

	ui->setupUi(this);
	init();

	connect(_result_data, &ResultData::barPatternOfWindPowderSignals, [=](std::vector<struct BarPatternOfWindPowder> bar) {
		for (int i = 0; i < bar.size(); i++)
		{
			_v[i / 4 * 3]->writeData(i, bar[i]._wind_speed);
			_v[i / 4 * 3 + 1]->writeData(i, bar[i]._concentration);
			_v[i / 4 * 3 + 2]->writeData(i, bar[i]._temperature);
		}
		});
}

RodTypeWindPowderDiagram::~RodTypeWindPowderDiagram()
{
	std::cout << "~RodTypeWindPowderDiagram()" << std::endl;
	delete ui;
}

void RodTypeWindPowderDiagram::init()
{
	// 对于每一个 类型,需要加一个坐标轴 Y轴, 顺便设置我们的上限和下限
	ui->wind_velocity_a->addYAxis(0, 10, 2, 5);
	ui->pulverized_coal_concentration_a->addYAxis(0, 10, 2, 5);
	ui->temperature_a->addYAxis(0, 10, 2, 5);

	_v.push_back(ui->wind_velocity_a);
	_v.push_back(ui->pulverized_coal_concentration_a);
	_v.push_back(ui->temperature_a);

	_v.push_back(ui->wind_velocity_b);
	_v.push_back(ui->pulverized_coal_concentration_b);
	_v.push_back(ui->temperature_b);

	_v.push_back(ui->wind_velocity_c);
	_v.push_back(ui->pulverized_coal_concentration_c);
	_v.push_back(ui->temperature_c);

	_v.push_back(ui->wind_velocity_d);
	_v.push_back(ui->pulverized_coal_concentration_d);
	_v.push_back(ui->temperature_d);

	_v.push_back(ui->wind_velocity_e);
	_v.push_back(ui->pulverized_coal_concentration_e);
	_v.push_back(ui->temperature_e);

	_v.push_back(ui->wind_velocity_f);
	_v.push_back(ui->pulverized_coal_concentration_f);
	_v.push_back(ui->temperature_f);
}