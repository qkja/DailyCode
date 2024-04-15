#include "test01.h"
#include "windows.h"
#include <QtWidgets/QApplication>
#include <QApplication>
#include <QWidget>
#include <QPainter>
#include "packagevirtualizationcontext.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 /*   Test01 w;
    w.show();*/
    primaryWindCutCircleDiagramView widget;
    widget.resize(200, 200);
    widget.show();
    return a.exec();
}

//
//#include <QtCharts/QChartView>
//#include <QtCharts/QLineSeries>
//#include <QtWidgets/QApplication>
//#include <QtWidgets/QMainWindow>
//
//QT_CHARTS_USE_NAMESPACE
//
//int main(int argc, char* argv[])
//{
//    QApplication a(argc, argv);
//
//    QLineSeries* series = new QLineSeries();
//    series->append(0, 6);
//    series->append(2, 4);
//    series->append(3, 8);
//    series->append(7, 4);
//    series->append(10, 5);
//    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
//
//    QChart* chart = new QChart();
//    chart->legend()->hide();
//    chart->addSeries(series);
//    chart->createDefaultAxes();
//    chart->setTitle("Simple line chart example");
//
//    QChartView* chartView = new QChartView(chart);
//    chartView->setRenderHint(QPainter::Antialiasing);
//
//    QMainWindow window;
//    window.setCentralWidget(chartView);
//    window.resize(400, 300);
//    window.show();
//
//    return a.exec();
//}


//#include <QApplication>
//#include <QWidget>
//#include <QPainter>
//​
//class MyWidget : public QWidget {
//public:
//    MyWidget(QWidget* parent = nullptr) : QWidget(parent) {}
//    ​
//protected:
//    void paintEvent(QPaintEvent*) override {
//        QPainter painter(this);
//        painter.setPen(Qt::black);
//        painter.drawLine(50, 50, 150, 50);   // top line
//        painter.drawLine(150, 50, 150, 150); // right line
//        painter.drawLine(150, 150, 50, 150); // bottom line
//        painter.drawLine(50, 150, 50, 50);   // left line
//    }
//};
//​
//int main(int argc, char* argv[]) 
//{
//    QApplication app(argc, argv);
//    MyWidget widget;
//    widget.resize(200, 200);
//    widget.show();
//    return app.exec();
//}