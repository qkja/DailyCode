#include "barchartwidget.h"
#include <iostream>
BarChartWidget::BarChartWidget(QWidget *parent)
	: QWidget(parent)
{
    createChart(0,0,0,0, "test");
}

BarChartWidget::~BarChartWidget()
{
    delete _chartView;
    std::cout << "1" << std::endl;
}

void BarChartWidget::createChart(int width, int height, int x, int y, const std::string& name)
{
    _chartView = new QChartView(this->parentWidget());
    _chart = new QChart();

    _chartView->resize(800, 400);
    _chartView->move(100, 200);

    
    _chartView->setChart(_chart);

    _series = new QBarSeries();

    _set = new QBarSet(name.c_str());
    _series->append(_set);

    _chart->addSeries(_series);

    _axisY = new QValueAxis();
    _axisY->setRange(0, 100);
    _chart->addAxis(_axisY, Qt::AlignLeft);

    _axisX = new QBarCategoryAxis();
    _chart->addAxis(_axisX, Qt::AlignBottom);

    _series->attachAxis(_axisY);
    _series->attachAxis(_axisX);



    QTimer* timer = new QTimer;
    QObject::connect(timer, &QTimer::timeout, [&]() {
        // 模拟获取新的数据
        qreal newValue1 = qrand() % 100;
        qreal newValue2 = qrand() % 100;
        qreal newValue3 = qrand() % 100;
        qreal newValue4 = qrand() % 100;
        std::cout << "测试 " << std::endl;
        std::cout << newValue1 << std::endl;
        std::cout << newValue2 << std::endl;
        std::cout << newValue3 << std::endl;
        std::cout << newValue4 << std::endl;

        if (_set->count() != 0)
        {
            _set->replace(0, newValue1);
            _set->replace(1, newValue2);
            _set->replace(2, newValue3);
            _set->replace(3, newValue4);
        }
        else
        {
            *_set << newValue1 << newValue2 << newValue3 << newValue4;

        }
        addXAxis();
        _chart->update();
        });
    timer->start(1000); // 1000毫秒（1秒）更新一次
}


void BarChartWidget::addXAxis()
{

    QStringList categories;
    for (int i = 0; i < _set->count(); ++i) {
        categories << QString::number(_set->at(i));
    }
    _axisX->setCategories(categories);
}