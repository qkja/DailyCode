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
//    // ����һ������ͼ����
//    QChart* chart = new QChart();
//    chart->setTitle("Simple line chart example");
//
//    // ����һ������ͼϵ��
//    QLineSeries* series = new QLineSeries();
//    series->append(0, 0);
//    series->append(1, 1);
//    series->append(2, 3);
//    series->append(3, 2);
//
//    // ��ϵ����ӵ�ͼ����
//    chart->addSeries(series);
//
//    // ���� X ��� Y ��
//    QValueAxis* axisX = new QValueAxis();
//    QValueAxis* axisY = new QValueAxis();
//    chart->addAxis(axisX, Qt::AlignBottom);
//    chart->addAxis(axisY, Qt::AlignLeft);
//    series->attachAxis(axisX);
//    series->attachAxis(axisY);
//    // ����һ��ͼ����ͼ
//    QChartView* chartView = new QChartView(chart);
//    // ��������ݣ�����ʾЧ������
//    chartView->setRenderHint(QPainter::Antialiasing);
//    // ����һ��������
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
//        // ����ͼ��
//        chart->update();
//        std::cout << "���ݸ���:" << xValue << std::endl;
//        });
//    timer.start(1000); // ÿ��1�봥����ʱ��
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