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

    // ������״ͼ����
    QBarSet* set = new QBarSet("Data");
    QBarSeries* series = new QBarSeries();
    *set << 100;
    series->append(set);

    // ����ͼ����ͼ
    QChart* chart = new QChart();
    chart->addSeries(series);

    // ���� Y ��
    QValueAxis* axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // ���� X ��
    QValueAxis* axisX = new QValueAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // ����ͼ����ͼ
    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // ������ʱ����ÿ�����һ������


    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        // ģ���ȡ�µ�����
        qreal newValue = qrand() % 100;
        set->replace(0, newValue); // ������״ͼ������

        // �ػ�ͼ��
        chart->update();
        });
    timer.start(1000); // 1000���루1�룩����һ��

    // ��ʾͼ����ͼ
    chartView->resize(400, 300);
    chartView->show();

    return a.exec();
}