#pragma once

#include <QMainWindow>
#include "ui_TrendChart.h"
#include <iostream>
#include <QtCharts>
#include "ResultData.h"
#include <unordered_map>

#define REFRESH_TIME  5                                   // ����5s��һ��
#define TOTAL_TIME 30                                     // ����30min������
#define NUMBER_OF_DATA   ((TOTAL_TIME*60)/REFRESH_TIME)   // �����������ݵĸ���

#define WINDCHOICE 1
#define CONCENTRATIONCHOICE 2
#define TEMPERATUREONECHOICE 3
#define TEMPERATURETWOCHOICE 4
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// ��ָ���֧��VS����
#endif
QT_BEGIN_NAMESPACE
namespace Ui { class TrendChartClass; };
QT_END_NAMESPACE

class TrendChart : public QMainWindow
{
	Q_OBJECT

public:
	TrendChart(QWidget* parent = nullptr, ResultData* resultData = nullptr);
	~TrendChart();
	void init();

signals:
	void trendChartCloseSignals();
private:
	void closeEvent(QCloseEvent*);
	void initMap();
	void updateData();
	void createChart();
	void _updateData(int, const std::string&, bool);
private:
	Ui::TrendChartClass* ui;
	ResultData* _result_data; // �յ�������
	std::unordered_map<std::string, std::vector<double>> _wind_speed_map;     // ����24������
	std::unordered_map<std::string, std::vector<double>> _concentration_map;  // ����24��ú��Ũ��
	std::unordered_map<std::string, std::vector<double>> _temperature_1;      // ����24���¶�1
	std::unordered_map<std::string, std::vector<double>> _temperature_2;      // ����24���¶�2

	QChartView* _chartView;           // QChartView ����չʾ QChart
	QChart* _chart;                   // QChart �����ɺ͹���һ����������ϵ��
	QValueAxis* _x;                   // X��
	QValueAxis* _y_wind;              // ����Y��
	QValueAxis* _y_concentration;     // Ũ��Y��
	QValueAxis* _y_temperature_1;     // �¶�1 Y��
	QValueAxis* _y_temperature_2;     // �¶�2 Y��
	QLineSeries* _line_wind;          // ��������
	QLineSeries* _line_concentration; // Ũ������
	QLineSeries* _line_temperature_1; // �¶�1����
	QLineSeries* _line_temperature_2; // �¶�2����
};
