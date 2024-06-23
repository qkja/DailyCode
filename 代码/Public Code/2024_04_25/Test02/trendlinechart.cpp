#include "trendlinechart.h"

TrendLineChart::TrendLineChart(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::TrendLineChartClass())
{
	ui->setupUi(this);
}

TrendLineChart::~TrendLineChart()
{
	delete ui;
}

void TrendLineChart::CreateChartFunc()
{
 




	_chartView = new QChartView(this);           // 视图
	_chart = new QChart();
    _chart->setTitle("line");
    _chartView->setChart(_chart);
    
    _line_wind = new QLineSeries();          // 风速折现
    _line_concentration = new QLineSeries(); // 浓度折现
    _line_temperature_1 = new QLineSeries(); // 温度1折现
    _line_temperature_2 = new QLineSeries(); // 温度2折现

    _line_wind->setName("_line_wind");
    _line_concentration->setName("_line_concentration");
    _line_temperature_1->setName("_line_temperature_1");
    _line_temperature_2->setName("_line_temperature_2");

    // 添加曲线到chart中
    _chart->addSeries(_line_wind);
    _chart->addSeries(_line_concentration);
    _chart->addSeries(_line_temperature_1);
    _chart->addSeries(_line_temperature_2);


	_x = new QValueAxis;
	_y_wind = new QValueAxis;           // 风速Y轴
	_y_concentration = new QValueAxis;     // 浓度Y轴
	_y_temperature_1 = new QValueAxis;   // 温度1 Y轴
	_y_temperature_2 = new QValueAxis;  // 温度2 Y轴

    _x->setRange(0, 100);
    _y_wind->setRange(0, 100);
    _y_concentration->setRange(0, 100);
    _y_temperature_1->setRange(0, 100);
    _y_temperature_2->setRange(0, 100);



    // 将坐标轴添加到chart中
    _chart->addAxis(_x, Qt::AlignBottom);
    _chart->addAxis(_y_wind, Qt::AlignLeft);
    _chart->addAxis(_y_concentration, Qt::AlignLeft);
    _chart->addAxis(_y_temperature_1, Qt::AlignLeft);
    _chart->addAxis(_y_temperature_2, Qt::AlignLeft);




    // 将数据和坐标轴关联起来


    _line_wind->attachAxis(_x);
    _line_wind->attachAxis(_y_wind);

    _line_concentration->attachAxis(_x);
    _line_concentration->attachAxis(_y_concentration);

    _line_temperature_1->attachAxis(_x);
    _line_temperature_1->attachAxis(_y_temperature_1);

    _line_temperature_2->attachAxis(_x);
    _line_temperature_2->attachAxis(_y_temperature_2);


    for (int i = 0; i < 80; ++i)
    {
        _line_wind->append(i, i);
        _line_concentration->append(i, i);
        _line_temperature_1->append(i, i);
        _line_temperature_2->append(i, i);

    }
    QTimer* timer = new QTimer();
    connect(timer, &QTimer::timeout, [=]() {

        int x = _line_wind->count();
        if (x > 100)
        {
            _line_wind->clear();
            x = 0;
        }
        _line_wind->append(x, x);
        _chart->update();
        });

    timer->start(1000);

}
