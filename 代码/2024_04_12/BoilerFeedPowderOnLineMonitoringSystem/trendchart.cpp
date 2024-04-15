#include "trendchart.h"

TrendChart::TrendChart(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::TrendChartClass())
{
	ui->setupUi(this);
	std::cout << "TrendChart()" << std::endl;

}

TrendChart::~TrendChart()
{
	std::cout << "~TrendChart()" << std::endl;
	delete ui;
}
