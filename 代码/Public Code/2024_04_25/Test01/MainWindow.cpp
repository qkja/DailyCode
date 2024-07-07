#include "MainWindow.h"


int xAxisData[10];
int yAxisData[10];
int oldxData[10];
int oldyData[10];
QList<QPointF> pointList;

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    timer = new QTimer(this);
    this->startTimer(1000);
    // 按键
    button = new QPushButton(this);
    button->setText("KEY");
    button->move(400, 20);
    connect(button, &QPushButton::clicked, this, &MainWindow::button_slot);

    // 按键1
    button1 = new QPushButton(this);
    button1->setText("KEY1");
    button1->move(400, 40);
    connect(button1, &QPushButton::clicked, this, &MainWindow::button1_slot);

    // 按键2
    button2 = new QPushButton(this);
    button2->setText("KEY2");
    button2->move(400, 70);
    connect(button2, &QPushButton::clicked, this, &MainWindow::button2_slot);

    // 设置轴坐标
    axisX = new QValueAxis;
    axisX->setRange(0, 10);
    axisX->setTickCount(10);  // 设置轴坐标网格数
    axisX->setLabelFormat("%.1f");

    // 设置轴坐标
    axisY = new QValueAxis;
    axisY->setRange(0, 10);
    axisY->setTickCount(5);  // 设置轴坐标网格数
    axisY->setLabelFormat("%d");

    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::red);

    series = new QLineSeries;
    series->setPen(pen);

    chart = new QChart;
    chart->addSeries(series);
    chart->setTitle("坐标图");
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    chart->legend()->hide(); // 隐藏图例

    chartView = new QChartView(chart, this);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(400, 200);
    chartView->move(20, 20);

    // 设置轴坐标
    daxisX = new QDateTimeAxis;
    daxisX->setTickCount(5);  // 设置轴坐标网格数
    daxisX->setFormat("h:mm:ss");
    QDateTime xMin, xMax;// 设置时间坐标轴范围
    xMin = QDateTime::currentDateTime();
    xMax = xMin.addSecs(20);
    daxisX->setRange(xMin, xMax);

    // 设置轴坐标
    daxisY = new QValueAxis;
    daxisY->setRange(0, 10);
    daxisY->setTickCount(5);  // 设置轴坐标网格数
    daxisY->setLabelFormat("%d");

    QPen dpen;
    dpen.setWidth(3);
    dpen.setColor(Qt::red);

    dseries = new QLineSeries;
    dseries->setPen(pen);

    dchart = new QChart;
    dchart->addSeries(dseries);
    dchart->setTitle("坐标图");
    dchart->addAxis(daxisX, Qt::AlignBottom);
    dchart->addAxis(daxisY, Qt::AlignLeft);
    dchart->legend()->hide(); // 隐藏图例

    dchartView = new QChartView(dchart, this);
    dchartView->setRenderHint(QPainter::Antialiasing);
    dchartView->resize(400, 200);
    dchartView->move(20, 260);

}

MainWindow::~MainWindow()
{

}

void MainWindow::button_slot()
{
    static int j = 0, k = 0;
    qDebug() << "button";
    if (k == 0)
    {
        k = 1;
        for (int i = 0; i < 10; i++)
        {
            oldxData[i] = -1 + i;
            series->append(oldxData[i], oldyData[i]);
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            xAxisData[i] = oldxData[i] + 1;
            if (i != 9)yAxisData[i] = yAxisData[i + 1];
            else {
                yAxisData[9] = qrand() % 10;
                axisX->setRange(xAxisData[0], xAxisData[9]);
            }
            series->remove(oldxData[i], oldyData[i]);
            series->append(xAxisData[i], yAxisData[i]);
            oldxData[i] = xAxisData[i];
            oldyData[i] = yAxisData[i];
        }
    }
}

void MainWindow::button1_slot()
{
    qDebug() << "button1";
    QDateTime t(QDateTime::currentDateTime());

    dseries->append(t.toMSecsSinceEpoch(), (qrand() % 10));
    QDateTime xMax;// 设置时间坐标轴范围
    xMax = QDateTime::currentDateTime();

    if (xMax > daxisX->max())
    {
        QDateTime xMin;
        xMin = xMax.addSecs(qint64(-20));
        daxisX->setRange(xMin, xMax);
    }
}

/* 使用list队列添加折线图的点
 * 1、创建list
 * 2、按下按键，添加一个QPointF点到list内，刷新series内的点
 * 3、如果添加的个数大于10个需要：1）移动轴坐标 2）删除列表尾，删除曲线集的最后一个
 *
 *
*/
void MainWindow::button2_slot()
{
    qDebug() << "button2";
    static int i = 0;
    QPointF p11(i, (qrand() % 10));
    pointList.append(p11);
    series->append(p11);
    if (pointList.isEmpty() == false && pointList.count() > 10)
    {
        series->remove(*(pointList.begin()));
        pointList.removeFirst();
        qreal a1 = 0, a2 = 0;
        a1 = pointList.back().rx();
        a2 = pointList.front().rx();
        axisX->setRange(a2, a1);
    }
    i++;
}

void MainWindow::timerEvent(QTimerEvent* event)
{
    static int i = 0;
    if (i++ == 10)
    {
        i = 0;
        qDebug() << "timer";
    }
    QDateTime t(QDateTime::currentDateTime());

    dseries->append(t.toMSecsSinceEpoch(), (qrand() % 10));
    QDateTime xMax;// 设置时间坐标轴范围
    xMax = QDateTime::currentDateTime();

    if (xMax > daxisX->max())
    {
        QDateTime xMin;
        xMin = xMax.addSecs(qint64(-20));
        daxisX->setRange(xMin, xMax);
    }
}

void MainWindow::paintEvent(QPaintEvent* event)
{
}
