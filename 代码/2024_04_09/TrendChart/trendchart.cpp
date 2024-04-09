#include "trendchart.h"

TrendChart::TrendChart(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TrendChartClass())
{
    ui->setupUi(this);
}

TrendChart::~TrendChart()
{
    delete ui;
}
