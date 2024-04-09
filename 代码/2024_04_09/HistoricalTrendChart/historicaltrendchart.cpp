#include "historicaltrendchart.h"

HistoricalTrendChart::HistoricalTrendChart(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HistoricalTrendChartClass())
{
    ui->setupUi(this);
}

HistoricalTrendChart::~HistoricalTrendChart()
{
    delete ui;
}
