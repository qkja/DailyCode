#pragma once

#include <QWidget>
#include "ui_trendlinechart.h"
#include <QtCharts>

QT_BEGIN_NAMESPACE
namespace Ui { class TrendLineChartClass; };
QT_END_NAMESPACE

class TrendLineChart : public QWidget
{
	Q_OBJECT

public:
	TrendLineChart(QWidget *parent = nullptr);
	~TrendLineChart();
	void CreateChartFunc();
private:
	Ui::TrendLineChartClass *ui;
	QChart* _chart;
	QValueAxis* _x;
	QValueAxis* _y_wind;              // ����Y��
	QValueAxis* _y_concentration;     // Ũ��Y��
	QValueAxis* _y_temperature_1;     // �¶�1 Y��
	QValueAxis* _y_temperature_2;     // �¶�2 Y��
	QLineSeries* _line_wind;          // ��������
	QLineSeries* _line_concentration; // Ũ������
	QLineSeries* _line_temperature_1; // �¶�1����
	QLineSeries* _line_temperature_2; // �¶�2����
	QChartView* _chartView;           // ��ͼ
};
