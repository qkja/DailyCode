//#include "Test01.h"
//#include <QtWidgets/QApplication>
//
//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
// 
//    Test01 w;
//    w.show();
//    return a.exec();
//}

//
//#include <QApplication>
//#include <QTimer>
//#include <QtCharts/QChartView>
//#include <QtCharts/QLineSeries>
//#include <QtCharts/QValueAxis>
//#include <QHBoxLayout>
//#include <QMainWindow>
//
//QT_CHARTS_USE_NAMESPACE
//
//int main(int argc, char* argv[])
//{
//    QApplication a(argc, argv);
//
//    // 创建一个折线图对象
//    QChart* chart = new QChart();
//    chart->setTitle("Simple line chart example");
//
//    // 创建一个折线图系列
//    QLineSeries* series = new QLineSeries();
//    series->append(0, 0);
//    series->append(1, 1);
//    series->append(2, 3);
//    series->append(3, 2);
//
//    // 将系列添加到图表中
//    chart->addSeries(series);
//
//    // 创建 X 轴和 Y 轴
//    QValueAxis* axisX = new QValueAxis();
//    QValueAxis* axisY = new QValueAxis();
//    chart->addAxis(axisX, Qt::AlignBottom);
//    chart->addAxis(axisY, Qt::AlignLeft);
//    series->attachAxis(axisX);
//    series->attachAxis(axisY);
//    // 创建一个图表视图
//    QChartView* chartView = new QChartView(chart);
//    // 开启抗锯齿，让显示效果更好
//    chartView->setRenderHint(QPainter::Antialiasing);
//    // 创建一个主窗口
//    QMainWindow window;
//    window.setCentralWidget(chartView);
//    window.resize(400, 300);
//    window.show();
//   
//
//    QTimer timer;
//    QObject::connect(&timer, &QTimer::timeout, [&series, &chart]() {
//        int xValue = series->count();
//        static int yValue = 0;
//        series->append(xValue, yValue);
//
//        yValue++;
//
//        // 更新图形
//        chart->update();
//        std::cout << "数据更新:" << xValue << std::endl;
//        });
//    timer.start(1000); // 每隔1秒触发计时器
//
//
//    return a.exec();
//}


#include "MainWindow.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}