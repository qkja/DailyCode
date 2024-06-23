#include "historicallinechart.h"

HistoricalLineChart::HistoricalLineChart(QWidget *parent)
	: QWidget(parent)
{

    _chart = new QChart();

    _line = new QLineSeries();
    _line->setName("折现");
    _chart->addSeries(_line);

    // X轴


    _x = new QValueAxis();

    _x->setRange(0, 60);
    _x->setGridLineVisible(true);
    _x->setMinorTickCount(5);

    //Y轴

    _y = new QValueAxis();

    _y->setRange(0, 60);
    _y->setGridLineVisible(true);
    _y->setMinorTickCount(5);


    // 添加到char中

    _chart->addAxis(_x, Qt::AlignBottom);
    _chart->addAxis(_y, Qt::AlignLeft);


    // 将折线图加载两个轴上
    _line->attachAxis(_x);
    _line->attachAxis(_y);


    for (size_t i = 0; i < 60; i++)
    {
        _line->append(i, qrand() % 200);
    }

    // 隐藏图例
    _chart->legend()->hide();
    _chartView = new QChartView(_chart);

    _chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(_chartView);
    setLayout(layout);
}

HistoricalLineChart::~HistoricalLineChart()
{}

