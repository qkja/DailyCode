#include "Test02.h"
#include <qcombobox.h>
#include <iostream>
#include <string>
#include <qcombobox.h>
void Test02::handleTextChanged(const QString& s)
{
    std::cout << s.toStdString() << std::endl;
}
Test02::Test02(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Test02Class())
{
    ui->setupUi(this);

    //QComboBox* q = new QComboBox(this);
    //q->addItem("1");
    //q->addItem("2");
    //q->addItem("3");
    //q->addItem("4");

 /*   connect(ui->comboBox, &QComboBox::currentTextChanged, [](const QString& s) {
        std::cout << s.toStdString() << std::endl;

        });*/

    //CreateChartFunc();
    
    //connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), [](int index) {});

    //connect(ui->comboBox, SIGNAL(currentTextChanged(const QString&)), this, SLOT(Test02::handleTextChanged(const QString&)));


    CreateChartFunc();



    QTimer* timer = new QTimer();
    connect(timer, &QTimer::timeout, [=]() {
        qreal va1 = qrand() % 50;
        bool falg = false;
        if (v.size() > 5)
        {
            falg = true;
            v.erase(v.begin());
        }

        v.push_back(va1);
        _right_wind = v.size();
        _left_wind = std::max(0, _right_wind - 3);

        int count = _line_wind->count();
        if (_line_wind->count() != 0)
        {
            _updateData(v, _left_wind, _right_wind);
        }
        });

    timer->start(1000);


    connect(ui->pushButton, &QPushButton::clicked, [=]() {
        _updateData(v, _left_wind, _right_wind);
        std::cout << "clicked" << std::endl;
        });
}

Test02::~Test02()
{
    delete ui;
}


void Test02::CreateChartFunc()
{


    _chartView = new QChartView(this);           // 视图
    _chart = new QChart();
    _chart->setTitle("line");
    _chartView->setChart(_chart);
    _chartView->resize(800, 400);
    _chartView->move(100, 100);

    _line_wind = new QLineSeries();          // 风速折现

    _line_wind->setName("_line_wind");

    // 添加曲线到chart中
    _chart->addSeries(_line_wind);


    _x = new QValueAxis;
    _y_wind = new QValueAxis;           // 风速Y轴


    _x->setRange(0, 5);
    _y_wind->setRange(0, 100);



    // 将坐标轴添加到chart中
    _chart->addAxis(_x, Qt::AlignBottom);
    _chart->addAxis(_y_wind, Qt::AlignLeft);


    _line_wind->attachAxis(_x);
    _line_wind->attachAxis(_y_wind);

   

}

void Test02::_updateData(std::vector<double> v, int left, int right)
{
    _line_wind->clear();
    for(int i = left; i< right;++i)
        _line_wind->append(i, v[i]);

    int count = _line_wind->count();


    for (int i = 0; i < count; i++)
    {
        int x = _line_wind->at(i).x();
        int y = _line_wind->at(i).y();
        /*int x1 = _line_wind->at(1).x();
        int y1 = _line_wind->at(1).y();
        int x2 = _line_wind->at(2).x();
        int y2 = _line_wind->at(2).y();*/
        std::cout << x << " : " << y << std::endl;
    }

    _chart->update();
}

























// 创建图表

//void Test02::CreateChartFunc()
//{
//
//
//    _chartView = new QChartView(this);           // 视图
//    _chart = new QChart();
//    _chart->setTitle("line");
//    _chartView->setChart(_chart);
//    _chartView->resize(800, 400);
//    _chartView->move(100, 100); 
//
//    _line_wind = new QLineSeries();          // 风速折现
//    //_line_concentration = new QLineSeries(); // 浓度折现
//    //_line_temperature_1 = new QLineSeries(); // 温度1折现
//    //_line_temperature_2 = new QLineSeries(); // 温度2折现
//
//    _line_wind->setName("_line_wind");
//    //_line_concentration->setName("_line_concentration");
//    //_line_temperature_1->setName("_line_temperature_1");
//    //_line_temperature_2->setName("_line_temperature_2");
//
//    // 添加曲线到chart中
//    _chart->addSeries(_line_wind);
//    //_chart->addSeries(_line_concentration);
//    //_chart->addSeries(_line_temperature_1);
//    //_chart->addSeries(_line_temperature_2);
//
//
//    _x = new QValueAxis;
//    _y_wind = new QValueAxis;           // 风速Y轴
//    //_y_concentration = new QValueAxis;     // 浓度Y轴
//    //_y_temperature_1 = new QValueAxis;   // 温度1 Y轴
//    //_y_temperature_2 = new QValueAxis;  // 温度2 Y轴
//
//    _x->setRange(0, 10);
//    _y_wind->setRange(0, 100);
//    //_y_concentration->setRange(0, 100);
//    //_y_temperature_1->setRange(0, 100);
//    //_y_temperature_2->setRange(0, 100);
//
//
//
//    // 将坐标轴添加到chart中
//    _chart->addAxis(_x, Qt::AlignBottom);
//    _chart->addAxis(_y_wind, Qt::AlignLeft);
//    //_chart->addAxis(_y_concentration, Qt::AlignLeft);
//    //_chart->addAxis(_y_temperature_1, Qt::AlignLeft);
//    //_chart->addAxis(_y_temperature_2, Qt::AlignLeft);
//
//
//
//
//    // 将数据和坐标轴关联起来
//
//
//    _line_wind->attachAxis(_x);
//    _line_wind->attachAxis(_y_wind);
//
//  /*  _line_concentration->attachAxis(_x);
//    _line_concentration->attachAxis(_y_concentration);
//
//    _line_temperature_1->attachAxis(_x);
//    _line_temperature_1->attachAxis(_y_temperature_1);
//
//    _line_temperature_2->attachAxis(_x);
//    _line_temperature_2->attachAxis(_y_temperature_2);*/
//
//
//    for (int i = 0; i < 95; ++i)
//    {
//        _line_wind->append(i, i);
//      /*  int ret = _line_wind->count();
//        _line_concentration->append(i, i);
//        _line_temperature_1->append(i, i);
//        _line_temperature_2->append(i, i);*/
//
//    }
//    QTimer* timer = new QTimer();
//    connect(timer, &QTimer::timeout, [=]() {
//
//        int x = _line_wind->count();
//   /*     if (x == 99)
//        {
//            int a = 0;
//            int ret = _line_wind->count();
//            a = 0;
//        }*/
//        if (x > 10)
//        {
//            //int ret2 = _line_wind->count();
//            _line_wind->clear();
//   /*         _line_concentration->clear();
//            _line_temperature_1->clear();
//            _line_temperature_2->clear();*/
//            x = 0;
//        }
//        qreal va1 = qrand() % 50;
//   /*     qreal va2 = qrand() % 50;
//        qreal va3 = qrand() % 50;
//        qreal va4 = qrand() % 50;*/
//        _line_wind->append(x, va1);
//    /*    _line_concentration->append(x, va2);
//        _line_temperature_1->append(x, va3);
//        _line_temperature_2->append(x, va4);*/
//        _chart->update();
//        });
//
//    timer->start(1000);
//    //chartview = new QChartView(this);
//    //chart = new QChart();
//    //// 写个名字
//    //chart->setTitle("line");
//    //// 将文档类添加到视图中
//    //chartview->setChart(chart);
//    //// 将视图放在中央
//    //this->setCentralWidget(chartview);
//
//
//    //// 创建曲线序列
//    //QLineSeries* series = new QLineSeries();
//    //series->setName("sin");
//
//    //// 添加曲线到chart中
//    //chart->addSeries(series);
//
//
//    //// 创建一个坐标轴
//    //QValueAxis* axisX = new QValueAxis;
//    //QValueAxis* axisY = new QValueAxis;
//
//    //// 设置坐标轴的范围
//    //axisX->setRange(0, 100);
//    //axisY->setRange(0, 100);
//  
//    //// 设置标题
//    //axisX->setTitleText("time(sec)");
//    //axisY->setTitleText("values");
//
//    //// 将坐标轴添加到chart中
//    //chart->addAxis(axisX, Qt::AlignBottom);
//    //chart->addAxis(axisY, Qt::AlignLeft);
//
//
//    //// 将数据和坐标轴关联起来
//    //series->attachAxis(axisX);
//    //series->attachAxis(axisY);
//
//    //for (int i = 0; i < 80; ++i)
//    //    series->append(i, i);
//    //QTimer* timer = new QTimer();
//    //connect(timer, &QTimer::timeout, [=]() {
//    //    
//    //    int x = series->count();
//    //    if (x > 100)
//    //    {
//    //        series->clear();
//    //        x = 0;
//    //    }
//    //    series->append(x, x);
//    //    chart->update();
//    //    });
//
//    //timer->start(1000);
//}
