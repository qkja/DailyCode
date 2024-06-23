#include "Test03.h"

Test03::Test03(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Test03Class())
{
    ui->setupUi(this);
    // �������� widget �Ͳ���
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
    setCentralWidget(centralWidget);

    // ���� QChartView ʵ��
    m_chartView = new QChartView(centralWidget);
    layout->addWidget(m_chartView);

    // �����첽ͼ����
    buildChartAsync();
}

Test03::~Test03()
{
    delete ui;
}

void Test03::onChartBuilt(QVector<double> x, QVector<double> y)
{
    // ��������ͼ����ӵ� QChartView
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
    // ����һ���߳��й���ͼ������
    QFuture<QPair<QVector<double>, QVector<double>>> future = QtConcurrent::run([this]() {
        // ģ���ʱ�����ݼ���
        QThread::sleep(2);
        return qMakePair(QVector<double>{1, 2, 3, 4, 5}, QVector<double>{1, 4, 9, 16, 25});
        });

    // �����ݼ������ʱ,�����ź�֪ͨ���̸߳���ͼ��
    QFutureWatcher<QPair<QVector<double>, QVector<double>>> watcher;
    connect(&watcher, &QFutureWatcher<QPair<QVector<double>, QVector<double>>>::finished, this, [this, future]() {
        onChartBuilt(future.result().first, future.result().second);
        });
    watcher.setFuture(future);
}