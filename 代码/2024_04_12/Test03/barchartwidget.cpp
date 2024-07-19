#include "barchartwidget.h"
#include <QVBoxLayout>
BarChartWidget::BarChartWidget(QWidget *parent)
    : QWidget(parent)
    ,_chart(nullptr)
    ,_series(nullptr)
    ,_chartView(nullptr)
    ,_first(nullptr)
    ,_second(nullptr)
    ,_third(nullptr)
    ,_fourth(nullptr)
{
    std::cout << "BarChartWidget()" << std::endl;

    init();
    addXAxis();
    addYAxis();
}

BarChartWidget::~BarChartWidget()
{
     delete _chart;
     delete _series;
     delete  _chartView;
     delete _first;
     delete _second;
     delete _third;
     delete _fourth;
     _chart = nullptr;
     _series = nullptr;
     _chartView = nullptr;
     _first = nullptr;
     _second = nullptr;
     _third = nullptr;
     _fourth = nullptr;
     std::cout << "~BarChartWidget()" << std::endl;
}


void BarChartWidget::addXAxis()
{
    QBarCategoryAxis* axisX = new QBarCategoryAxis();
    _chart->addAxis(axisX, Qt::AlignBottom);
    _series->attachAxis(axisX);

  
    QStringList categories;
    for (int i = 0; i < _first->count(); ++i) {
        categories << QString::number(_first->at(i));
    }
    axisX->setCategories(categories);
}
void BarChartWidget::addYAxis()
{
    QValueAxis* axisY = new QValueAxis();

    axisY->setRange(0, 10);
   
    //axisY->setTickType(QCategoryAxis::TickType::AxisTicks); // ���ÿ̶�����
    axisY->setTickAnchor(3); // ���õ�һ����ǵ��λ��
    axisY->setTickAnchor(7); // ���õڶ�����ǵ��λ��
    axisY->setTickInterval(1); // ���ÿ̶ȼ��
    //axisY->setLabelsPosition(QCategoryAxis::AxisLabelsPosition::OnValue); // ���ñ�ǩλ��
    axisY->setLabelsVisible(true); // ���ñ�ǩ�ɼ���
    //axisY->setLabelsFormat("3|7"); // ���ñ�ǩ��ʽ

    _chart->addAxis(axisY, Qt::AlignLeft);
    _series->attachAxis(axisY);



}
void BarChartWidget::init()
{
    if(nullptr == _first)
        _first = new QBarSet("first");
    if (nullptr == _second)
        _second = new QBarSet("second");
    if (nullptr == _third)
        _third = new QBarSet("third");
    if (nullptr == _fourth)
        _fourth = new QBarSet("fourth");
    *_first << 1 << 3 << 6 << 7;


    if (nullptr == _series)
        _series = new QBarSeries();

    _series->append(_first);
   /* _series->append(_second);
    _series->append(_third);
    _series->append(_fourth);*/
    if (nullptr == _chart)
        _chart = new QChart();
    _chart->addSeries(_series);
    _chart->setTitle("Simple Bar Chart");
    _chart->setAnimationOptions(QChart::SeriesAnimations);

    if (nullptr == _chartView)
        _chartView = new QChartView(_chart);
    _chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(_chartView);
    setLayout(layout);
}
