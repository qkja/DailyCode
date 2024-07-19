#include "historicaltrendchart.h"

HistoricalTrendChart::HistoricalTrendChart(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::HistoricalTrendChartClass())
{
	ui->setupUi(this);
}

HistoricalTrendChart::~HistoricalTrendChart()
{
	delete ui;
}
