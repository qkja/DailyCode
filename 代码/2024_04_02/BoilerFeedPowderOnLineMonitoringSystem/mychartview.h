#pragma once

#include <QtCharts>
QT_CHARTS_USE_NAMESPACE

#include <QtCharts/qbarset.h>
#include <QtCharts/qbarseries.h>
#include <QtCharts/qchartview.h>
#include <QtCharts/qlegend.h>

QT_CHARTS_USE_NAMESPACE
class MyChartView  : public QChartView
{
	Q_OBJECT
		friend class RodTypeWindPowderDiagram;
public:
	MyChartView(QWidget *parent);
	~MyChartView();
	void initChart();
private:
	// 四个柱子
	QBarSet* _first ;
	QBarSet* _second;
	QBarSet* _third;
	QBarSet* _fourth;
	//QBarSeries类以垂直条的形式呈现一系列数据，按类别分组。
	QBarSeries* _series;
	// 图像
	QChart* _chart;
};
