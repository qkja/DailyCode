#include "Test03.h"

Test03::Test03(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Test03Class())
{
    ui->setupUi(this);
    // 创建中心 widget 和布局
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
    setCentralWidget(centralWidget);

    // 创建 QChartView 实例
    m_chartView = new QChartView(centralWidget);
    layout->addWidget(m_chartView);

    // 启动异步图表构建
    buildChartAsync();
}

Test03::~Test03()
{
    delete ui;
}

void Test03::onChartBuilt(QVector<double> x, QVector<double> y)
{
    // 创建折线图并添加到 QChartView
    QLineSeries* series = new QLineSeries();
    for (int i = 0; i < x.size(); ++i) {
        series->append(x[i], y[i]);
    }

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Asynchronous Line Chart Example");
    chart->createDefaultAxes();
    m_chartView->setChart(chart);
}

void Test03::buildChartAsync()
{
    // 在另一个线程中构建图表数据
    QFuture<QPair<QVector<double>, QVector<double>>> future = QtConcurrent::run([this]() {
        // 模拟耗时的数据计算
        QThread::sleep(2);
        return qMakePair(QVector<double>{1, 2, 3, 4, 5}, QVector<double>{1, 4, 9, 16, 25});
        });

    // 当数据计算完成时,发送信号通知主线程更新图表
    QFutureWatcher<QPair<QVector<double>, QVector<double>>> watcher;
    connect(&watcher, &QFutureWatcher<QPair<QVector<double>, QVector<double>>>::finished, this, [this, future]() {
        onChartBuilt(future.result().first, future.result().second);
        });
    watcher.setFuture(future);
}