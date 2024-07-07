//#include "Test01.h"
//#include <QtWidgets/QApplication>
//
//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    Test01 w;
//    w.show();
//    return a.exec();
//}
#include <QApplication>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QValueAxis>
#include <QTimer>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    // 创建柱状图数据
    QBarSet* set = new QBarSet("Data");
    QBarSeries* series = new QBarSeries();
    *set << 100;
    series->append(set);

    // 创建图表视图
    QChart* chart = new QChart();
    chart->addSeries(series);

    // 创建 Y 轴
    QValueAxis* axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // 创建 X 轴
    QValueAxis* axisX = new QValueAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // 创建图表视图
    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // 创建定时器，每秒更新一次数据


    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        // 模拟获取新的数据
        qreal newValue = qrand() % 100;
        set->replace(0, newValue); // 更新柱状图的数据

        // 重绘图表
        chart->update();
        });
    timer.start(1000); // 1000毫秒（1秒）更新一次

    // 显示图表视图
    chartView->resize(400, 300);
    chartView->show();

    return a.exec();
}