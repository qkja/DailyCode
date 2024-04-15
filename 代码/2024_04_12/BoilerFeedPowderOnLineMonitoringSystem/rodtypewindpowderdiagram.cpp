#include "rodtypewindpowderdiagram.h"

RodTypeWindPowderDiagram::RodTypeWindPowderDiagram(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::RodTypeWindPowderDiagramClass())
{
	std::cout << "RodTypeWindPowderDiagram()" << std::endl;

	ui->setupUi(this);


	// ����ÿһ�� ����,��Ҫ��һ�������� Y��, ˳���������ǵ����޺�����
	ui->wind_velocity_a->addYAxis(0, 10, 2, 5);
	ui->pulverized_coal_concentration_a->addYAxis(0, 10, 2, 5);
	ui->temperature_a->addYAxis(0, 10, 2, 5);
}

RodTypeWindPowderDiagram::~RodTypeWindPowderDiagram()
{
	std::cout << "~RodTypeWindPowderDiagram()" << std::endl;
	delete ui;
}
