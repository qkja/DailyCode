#pragma once
#include <QMainWindow>
#include "ui_rodtypewindpowderdiagram.h"
#include <iostream>
#include "Task.hpp"
#include "resultdata.h"
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
	void init();
private:
	Ui::RodTypeWindPowderDiagramClass* ui;
	ResultData* _result_data;  // 派发数据
	std::vector<BarChartWidget*> _v;// 收藏ui所有的的自定义控件
};
