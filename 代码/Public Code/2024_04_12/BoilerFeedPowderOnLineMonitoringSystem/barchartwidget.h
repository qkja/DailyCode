#pragma once

#include <QWidget>
#include <QtCharts>
QT_CHARTS_USE_NAMESPACE
class BarChartWidget : public QWidget
{
	Q_OBJECT

public:
	BarChartWidget(QWidget* parent);
	~BarChartWidget();
	void setRange(int, int);
	void writeData(const std::vector<double>&);
	void createChart(int, int, int, int, const std::string&);
	void addXAxis();
private:
	QBarSet* _set;
	QBarSeries* _series;
	QChart* _chart;            // �ĵ���
	QChartView* _chartView;    // ��ͼ
	QBarCategoryAxis* _axisX;  // X��
	QValueAxis* _axisY;        // Y��
};
