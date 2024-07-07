#pragma once

#include <QtCharts>
QT_CHARTS_USE_NAMESPACE

#include <QtCharts/qbarset.h>
#include <QtCharts/qbarseries.h>
#include <QtCharts/qchartview.h>
#include <QtCharts/qlegend.h>

QT_CHARTS_USE_NAMESPACE
class MyChartView : public QChartView
{
	Q_OBJECT
	friend class RodTypeWindPowderDiagram;

public:
	MyChartView(QWidget *parent);
	~MyChartView();
	void initChart();

private:
	// �ĸ�����
	QBarSet *_first;
	QBarSet *_second;
	QBarSet *_third;
	QBarSet *_fourth;
	// QBarSeries���Դ�ֱ������ʽ����һϵ�����ݣ��������顣
	QBarSeries *_series;
	// ͼ��
	QChart *_chart;
};
