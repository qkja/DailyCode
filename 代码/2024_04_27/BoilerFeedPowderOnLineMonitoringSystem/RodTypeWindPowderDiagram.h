#pragma once

#include <QWidget>
#include "ui_RodTypeWindPowderDiagram.h"
#include <iostream>
#include <iostream>
#include "Task.h"
#include "ResultData.h"
#include "BarChartWidget.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// 该指令仅支持VS环境
#endif
QT_BEGIN_NAMESPACE
namespace Ui { class RodTypeWindPowderDiagramClass; };
QT_END_NAMESPACE

class RodTypeWindPowderDiagram : public QWidget
{
	Q_OBJECT

public:
	RodTypeWindPowderDiagram(QWidget* parent = nullptr, ResultData* result_data = nullptr);
	~RodTypeWindPowderDiagram();
	void init();
private:
	void createChart();
	void updateData();
	void closeEvent(QCloseEvent*) override;

signals:
	void rodTypeWindPowderDiagramCloseSignals();

private:
	Ui::RodTypeWindPowderDiagramClass* ui;
	ResultData* _result_data;  // 派发数据
	// 三个图形
	BarChartWidget* _wind_speed_view;
	BarChartWidget* _pulverized_coal_concentration_view;
	BarChartWidget* _temperature_view;
};
