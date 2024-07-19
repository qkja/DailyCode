#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test02.h"
#include <QtCharts>
#include <qtimer.h>
QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class Test02Class; };
QT_END_NAMESPACE

class Test02 : public QMainWindow
{
    Q_OBJECT

public:
    Test02(QWidget *parent = nullptr);
    ~Test02();
    void CreateChartFunc();
	void _updateData(std::vector<double>, int, int);

public slots:
	void handleTextChanged(const QString&);
private:
	QChart* _chart;
	QValueAxis* _x;
	QValueAxis* _y_wind;              // 风速Y轴
	QValueAxis* _y_concentration;     // 浓度Y轴
	QValueAxis* _y_temperature_1;     // 温度1 Y轴
	QValueAxis* _y_temperature_2;     // 温度2 Y轴
	QLineSeries* _line_wind;          // 风速折现
	QLineSeries* _line_concentration; // 浓度折现
	QLineSeries* _line_temperature_1; // 温度1折现
	QLineSeries* _line_temperature_2; // 温度2折现
	QChartView* _chartView;           // 视图
    //QChartView* chartview; //  QChartView用于展示图表（视图类）
    //QChart* chart;         //  QChart类主要是组织图表的内容（文档类）
    Ui::Test02Class *ui;
	int _left_wind  = 0;      // 风速左侧的范围
	int _right_wind =  0;     // 风速右侧的范围
	std::vector<double> v;
};
