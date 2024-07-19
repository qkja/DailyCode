#include "Test01.h"

Test01::Test01(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Test01Class())
{
    ui->setupUi(this);

    //QChart* _chart = new QChart();
    //QLineSeries* _line_wind = new QLineSeries();        // ·çËÙÕÛÏÖ
    //_line_wind->setName("line");
    //_chart->addSeries(_line_wind);

    //QValueAxis* _x = new QValueAxis();
    //_x->setRange(0, 60);
    //_x->setGridLineVisible(true);
    //_x->setMinorTickCount(5);

    //QValueAxis* _y_wind = new QValueAxis();
    //_y_wind->setRange(0, 60);
    //_y_wind->setGridLineVisible(true);
    //_y_wind->setMinorTickCount(5);


    //_chart->addAxis(_x, Qt::AlignBottom);
    //_chart->addAxis(_y_wind, Qt::AlignLeft);


    //_line_wind->attachAxis(_x);
    //_line_wind->attachAxis(_y_wind);

    //QChartView* _chartView = new QChartView(_chart);
    //_chartView->setRenderHint(QPainter::Antialiasing);

    //QVBoxLayout* layout = new QVBoxLayout(this);
    //layout->addWidget(_chartView);
    //setLayout(layout);

}

Test01::~Test01()
{
    delete ui;
}
