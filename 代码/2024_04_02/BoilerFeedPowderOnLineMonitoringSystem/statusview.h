#pragma once

#include <QWidget>
#include "rodtypewindpowderdiagram.h"
#include "tangentialcirclediagramofprimarywind.h"
#include "trendchart.h"
#include "historicaltrendchart.h"
class StatusView  : public QWidget
{
	Q_OBJECT
	friend class MainScreen;
public:
	StatusView(QWidget *parent);
	~StatusView();
private:
	RodTypeWindPowderDiagram* _rod_type_wind_powder_diagram; // 棒型风粉图
	TangentialCircleDiagramOfPrimaryWind* _tangential_circle_diagram_of_primary_wind; // 一次风切圆图
	TrendChart* _trend_chart;
	HistoricalTrendChart* _historical_trend_chart;
};