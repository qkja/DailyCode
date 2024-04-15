#include "barchartwidget.h"
#include <QVBoxLayout>
#include <qlineseries.h>
BarChartWidget::BarChartWidget(QWidget *parent)
    : QWidget(parent)
    ,_chart(nullptr)
    ,_series(nullptr)
    ,_chartView(nullptr)
    ,_qBarSet(nullptr)
    , _axisX(nullptr)
    ,_axisY(nullptr)
{
    std::cout << "BarChartWidget()" << std::endl;

    init();
    DataResult<int> a;
    writeData(a);
    addXAxis();
}

BarChartWidget::~BarChartWidget()
{
     delete _chart;
     delete _series;
     delete  _chartView;
     delete _qBarSet;
     delete _axisX;

     if(_axisY)
        delete _axisY;

     _chart = nullptr;
     _series = nullptr;
     _chartView = nullptr;
     _qBarSet = nullptr;
     _axisX = nullptr;
     _axisY = nullptr;
     std::cout << "~BarChartWidget()" << std::endl;
}

void BarChartWidget::writeData(const DataResult<int> data)
{

    if (_qBarSet->count() == 0)
    {
        //*_qBarSet << data._first << data._second << data._third << data._fourth;
        *_qBarSet << 1 << 3 << 6 << 7;  //Õâ¸öÊÇ

    }
    else
    {
        _qBarSet->replace(0, data._first);
        _qBarSet->replace(1, data._second);
        _qBarSet->replace(2, data._third);
        _qBarSet->replace(3, data._fourth);
    }
  
    _chart->removeSeries(_series);
    _chart->addSeries(_series);

}

void BarChartWidget::addYAxis(int min_imum, int max_imum,  int lower_limit, int upper_limit)
{
    _axisY = new QValueAxis();
    _axisY->setRange(min_imum, max_imum);

    _chart->addAxis(_axisY, Qt::AlignLeft);
    _series->attachAxis(_axisY);

}

void BarChartWidget::addXAxis()
{
    _axisX = new QBarCategoryAxis();
    _chart->addAxis(_axisX, Qt::AlignBottom);
    _series->attachAxis(_axisX);

   
    QStringList categories;
    for (int i = 0; i < _qBarSet->count(); ++i) {
        categories << QString::number(_qBarSet->at(i));
    }
    _axisX->setCategories(categories);
}
void BarChartWidget::init()
{
    if(nullptr == _qBarSet)
        _qBarSet = new QBarSet("data");
    if (nullptr == _series)
        _series = new QBarSeries();

    _series->append(_qBarSet);

    if (nullptr == _chart)
        _chart = new QChart();
    _chart->addSeries(_series);
    _chart->setTitle("Simple Bar Chart");
    _chart->setAnimationOptions(QChart::SeriesAnimations);
    addXAxis();
    if (nullptr == _chartView)
        _chartView = new QChartView(_chart);
    _chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(_chartView);
    setLayout(layout);
}
