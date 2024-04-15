#include "historicaltrendchart.h"

HistoricalTrendChart::HistoricalTrendChart(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::HistoricalTrendChartClass())
{
	ui->setupUi(this);

	std::cout << "HistoricalTrendChart()" << std::endl;
}

HistoricalTrendChart::~HistoricalTrendChart()
{
	std::cout << "~HistoricalTrendChart()" << std::endl;
	delete ui;
}
