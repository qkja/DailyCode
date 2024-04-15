#include "statusview.h"
StatusView::StatusView(QWidget *parent)
	: QWidget(parent), _rod_type_wind_powder_diagram(new RodTypeWindPowderDiagram(nullptr)), _tangential_circle_diagram_of_primary_wind(new TangentialCircleDiagramOfPrimaryWind(nullptr)), _trend_chart(new TrendChart(nullptr)), _historical_trend_chart(new HistoricalTrendChart(nullptr))
{
	std::cout << "StatusView()" << std::endl;
}

StatusView::~StatusView()
{
	std::cout << "~StatusView()" << std::endl;
	delete _rod_type_wind_powder_diagram;
	delete _tangential_circle_diagram_of_primary_wind;
	delete _trend_chart;
	delete _historical_trend_chart;
}