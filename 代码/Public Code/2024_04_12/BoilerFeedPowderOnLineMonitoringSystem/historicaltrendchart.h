#pragma once

#include <QMainWindow>
#include "ui_historicaltrendchart.h"
#include <iostream>
#include <iostream>
#include <QtCharts>
#include "resultdata.h"
#include <unordered_map>
#define REFRESH_TIME_HIS  5                                              // ����5s��һ��
#define TOTAL_TIME_HIS 120                                               // ����120min������
#define NUMBER_OF_DATA_HIS   ((TOTAL_TIME_HIS*60)/REFRESH_TIME_HIS)      // �����������ݵĸ���

#define STAGE_TIME  30                                                   // ����30min������
#define STAGE_FREQUENCY      ((STAGE_TIME*60)/REFRESH_TIME_HIS)          // ����������ʾ�ĸ���

#define STEP_SIZE 20

#define WINDCHOICE_HIS 1
#define CONCENTRATIONCHOICE_HIS 2
#define TEMPERATUREONECHOICE_HIS 3
#define TEMPERATURETWOCHOICE_HIS 4
QT_BEGIN_NAMESPACE
namespace Ui
{
	class HistoricalTrendChartClass;
};
QT_END_NAMESPACE

class HistoricalTrendChart : public QMainWindow
{
	Q_OBJECT

public:
	HistoricalTrendChart(QWidget* parent = nullptr, ResultData* resultData = nullptr);
	~HistoricalTrendChart();
public:
	void init();
	void initMap();
	void updateData();
	void _updateData(int, const std::string&, int, int);
	void createChart();
private:
	Ui::HistoricalTrendChartClass* ui;
	ResultData* _resultData; // �յ�������

	std::unordered_map<std::string, std::vector<double>> _wind_speed_map;         // ����24������
	std::unordered_map<std::string, std::vector<double>> _concentration_map;      // ����24��ú��Ũ��
	std::unordered_map<std::string, std::vector<double>> _temperature_1_map;      // ����24���¶�1
	std::unordered_map<std::string, std::vector<double>> _temperature_2_map;      // ����24���¶�2

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

	int _left_wind;      // �������ķ�Χ
	int _right_wind;     // �����Ҳ�ķ�Χ

	int _left_concentration;      // Ũ�����ķ�Χ
	int _right_concentration;     // Ũ���Ҳ�ķ�Χ

	int _left_temperature_1;      // �¶�1���ķ�Χ
	int _right_temperature_1;     // �¶�2�Ҳ�ķ�Χ

	int _left_temperature_2;      // �¶�2���ķ�Χ
	int _right_temperature_2;     // �¶�2�Ҳ�ķ�Χ
	bool _left_right_clickde;     // ������������Ҳ�
};
