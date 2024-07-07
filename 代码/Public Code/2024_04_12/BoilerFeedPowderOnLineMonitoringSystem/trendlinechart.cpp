#include "trendlinechart.h"
#include <Windows.h>
TrendLineChart::TrendLineChart(QWidget *parent)
    : QWidget(parent)
{


    _chart = new QChart();


    
    // 实例化折线
    _line_wind = new QLineSeries();
    _line_wind->setName("_line_wind");
    _chart->addSeries(_line_wind);


    _line_concentration = new QLineSeries();
    _line_concentration->setName("_line_concentration");
    _chart->addSeries(_line_concentration);

    _line_temperature_1 = new QLineSeries();
    _line_temperature_1->setName("_line_temperature_1");
    _chart->addSeries(_line_temperature_1);

    _line_temperature_2 = new QLineSeries();
    _line_temperature_2->setName("_line_temperature_2");
    _chart->addSeries(_line_temperature_2);


    // 实例化一个X轴
    _x = new QValueAxis();
    _x->setRange(0, 60);
    _x->setGridLineVisible(true);
    _x->setMinorTickCount(5);



    // 实例化Y轴
    _y_wind = new QValueAxis();
    _y_wind->setRange(0, 60);
    _y_wind->setGridLineVisible(true);
    _y_wind->setMinorTickCount(5);


    _y_concentration = new QValueAxis();
    _y_concentration->setRange(0, 60);
    _y_concentration->setGridLineVisible(true);
    _y_concentration->setMinorTickCount(5);


    _y_temperature_1 = new QValueAxis();
    _y_temperature_1->setRange(0, 60);
    _y_temperature_1->setGridLineVisible(true);
    _y_temperature_1->setMinorTickCount(5);



   _y_temperature_2 = new QValueAxis();
   _y_temperature_2->setRange(0, 60);
   _y_temperature_2->setGridLineVisible(true);
   _y_temperature_2->setMinorTickCount(5);



    // 把Y轴和Y轴放入进去

    _chart->addAxis(_x, Qt::AlignBottom);
    _chart->addAxis(_y_wind, Qt::AlignLeft);
    _chart->addAxis(_y_concentration, Qt::AlignLeft);
    _chart->addAxis(_y_temperature_1, Qt::AlignLeft);
    _chart->addAxis(_y_temperature_2, Qt::AlignLeft);

    // 联动数据与轴
    _line_wind->attachAxis(_x);
    _line_concentration->attachAxis(_x);
    _line_temperature_1->attachAxis(_x);
    _line_temperature_2->attachAxis(_x);
    
    _line_wind->attachAxis(_y_wind);
    _line_concentration->attachAxis(_y_concentration);
    _line_temperature_1->attachAxis(_y_temperature_1);
    _line_temperature_2->attachAxis(_y_temperature_2);


    _line_wind->append(0,0);
    _line_concentration->append(0, 0);
    _line_temperature_1->append(0, 0);
    _line_temperature_2->append(0, 0);

   
    //_chart->legend()->hide();
    _chartView = new QChartView(_chart);
    _chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(_chartView);
    setLayout(layout);
}

TrendLineChart::~TrendLineChart()
{

    delete _chart;
    delete _x;
    delete _y_wind;              // 风速Y轴
    delete _y_concentration;     // 浓度Y轴
    delete _y_temperature_1;     // 温度1 Y轴
    delete _y_temperature_2;     // 温度2 Y轴
    delete _line_wind;           // 风速折现
    delete _line_concentration;  // 浓度折现
    delete _line_temperature_1;  // 温度1折现
    delete _line_temperature_2;  // 温度2折现
    delete _chartView;           // 视图
}

void TrendLineChart::writeData(const std::string& choiceLine, const std::vector<double>& data)
{

    
    // 这里有一个问题
    /*for (size_t i = 0; i < 6; i++)
    {
        _line_wind->append(i, qrand() % 200);
        _line_concentration->append(i, qrand() % 200);
        _line_temperature_1->append(i, qrand() % 200);
        _line_temperature_2->append(i, qrand() % 200);
        _chart->update();
        Sleep(1000);
    }*/

    // 选择一个折线,我们里面重写数据,更新所有的数据
    int index = 0;
    if ("wind" == choiceLine)
    {
        // 清除数据,这里可以看看是否存在swap方法,或者看这个结构体的底层,我们直接交换
        _line_wind->clear();
        for (auto& val : data)
            _line_wind->append(index++, val);
    }
    else if("concentration" == choiceLine)
    {
        _line_concentration->clear();
        for (auto& val : data)
            _line_concentration->append(index++, val);
    }
    else if ("temperature_1" == choiceLine)
    {
        _line_temperature_1->clear();
        for (auto& val : data)
            _line_temperature_1->append(index++, val);
    }
    else if ("temperature_2" == choiceLine)
    {
        _line_temperature_2->clear();
        for (auto& val : data)
            _line_temperature_2->append(index++, val);
    }
    else
    {
        std::cerr << "choiceLine: " << choiceLine << "error" << std::endl;
    }
}

void TrendLineChart::writeData(const std::string& choiceLine, const double& data)
{
    // 根据选择,只是添加一个数据


    int index = 0;
    if ("wind" == choiceLine)
    {
        int index = _line_wind->count();

    }
    else if ("concentration" == choiceLine)
    {
        
    }
    else if ("temperature_1" == choiceLine)
    {

    }
    else if ("temperature_2" == choiceLine)
    {
    }
    else
    {
        std::cerr << "choiceLine: " << choiceLine << "error" << std::endl;
    }
}
