#include "barchartwidget.h"
#include <QVBoxLayout>
BarChartWidget::BarChartWidget(QWidget *parent)
	: QWidget(parent)
{
    init();
}

BarChartWidget::~BarChartWidget()
{
   /* delete _chart;
    delete _series;
    delete  _chartView;
    delete _first;
    delete _second;
    delete _third;*/
    //delete _fourth;
}

void BarChartWidget::init()
{
    _first = new QBarSet("first");
    _second = new QBarSet("second");
    _third = new QBarSet("third");
    _fourth = new QBarSet("fourth");

    *_first << 1;
    *_second << 1;
    *_third << 1;
    *_fourth << 1;

    _series = new QBarSeries();
    _series->append(_first);
    _series->append(_second);
    _series->append(_third);
    _series->append(_fourth);

    _chart = new QChart();
    _chart->addSeries(_series);
    _chart->setTitle("Simple Bar Chart");
    _chart->setAnimationOptions(QChart::SeriesAnimations);

    _chartView = new QChartView(_chart);
    _chartView->setRenderHint(QPainter::Antialiasing);

     QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(_chartView);
    setLayout(layout);
}

