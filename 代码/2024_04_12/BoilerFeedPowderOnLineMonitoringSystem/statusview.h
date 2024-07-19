#pragma once

#include <QWidget>
#include "rodtypewindpowderdiagram.h"
#include "tangentialcirclediagramofprimarywind.h"
#include "trendchart.h"
#include "historicaltrendchart.h"
#include <iostream>
#include "resultdata.h"
class StatusView : public QWidget
{
	Q_OBJECT
		friend class BoilerFeedPowderOnLineMonitoringSystem;
public:
	StatusView(QWidget* parent, ResultData* result_data);
	~StatusView();

private:
	ResultData* _result_data;
	RodTypeWindPowderDiagram* _rod_type_wind_powder_diagram;	                      // 棒型风粉图
	TangentialCircleDiagramOfPrimaryWind* _tangential_circle_diagram_of_primary_wind; // 一次风切圆图
	TrendChart* _trend_chart;                                                         // 趋势图
	HistoricalTrendChart* _historical_trend_chart;                                    // 历史趋势图
};