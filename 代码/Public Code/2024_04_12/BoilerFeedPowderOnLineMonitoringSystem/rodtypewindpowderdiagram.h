#pragma once
#include <QMainWindow>
#include "ui_rodtypewindpowderdiagram.h"
#include <iostream>
#include "Task.hpp"
#include "resultdata.h"
#include "barchartwidget.h"
QT_BEGIN_NAMESPACE
namespace Ui
{
	class RodTypeWindPowderDiagramClass;
};
QT_END_NAMESPACE

class RodTypeWindPowderDiagram : public QMainWindow
{
	Q_OBJECT

public:
	RodTypeWindPowderDiagram(QWidget* parent = nullptr, ResultData* result_data = nullptr);
	~RodTypeWindPowderDiagram();
private:
	void createChart();
	void init();
	void updateData();
private:
	Ui::RodTypeWindPowderDiagramClass* ui;
	ResultData* _result_data;  // 派发数据

	// 三个图形
	BarChartWidget* _wind_speed_view;
	BarChartWidget* _pulverized_coal_concentration_view;
	BarChartWidget* _temperature_view;
};
