#include "barchartwidget.h"
#include <QVBoxLayout>
#include <qlineseries.h>
BarChartWidget::BarChartWidget(QWidget* parent)
	: QWidget(parent)
	, _chart(nullptr)
	, _series(nullptr)
	, _chartView(nullptr)
	, _qBarSet(nullptr)
	, _axisX(nullptr)
	, _axisY(nullptr)
{
	std::cout << "BarChartWidget()" << std::endl;

	init();
	addXAxis();
}

BarChartWidget::~BarChartWidget()
{
	delete _chart;
	delete _series;
	delete  _chartView;
	delete _qBarSet;
	delete _axisX;

	if (_axisY)
		delete _axisY;

	_chart = nullptr;
	_series = nullptr;
	_chartView = nullptr;
	_qBarSet = nullptr;
	_axisX = nullptr;
	_axisY = nullptr;
	std::cout << "~BarChartWidget()" << std::endl;
}
void BarChartWidget::writeData(int index, double value)
{
	_qBarSet->replace(index, value);

	_chart->removeSeries(_series);
	_chart->addSeries(_series);

	_chart->update();
}

void BarChartWidget::addYAxis(int min_imum, int max_imum, int lower_limit, int upper_limit)
{
	_axisY = new QValueAxis();
	_axisY->setRange(min_imum, max_imum);

	_chart->addAxis(_axisY, Qt::AlignLeft);
	_series->attachAxis(_axisY);
}

void BarChartWidget::addXAxis()
{
	_axisX = new QBarCategoryAxis();
	_chart->addAxis(_axisX, Qt::AlignBottom);
	_series->attachAxis(_axisX);

	QStringList categories;
	for (int i = 0; i < _qBarSet->count(); ++i) {
		categories << QString::number(_qBarSet->at(i));
	}
	_axisX->setCategories(categories);
}
void BarChartWidget::init()
{
	if (nullptr == _qBarSet)
		_qBarSet = new QBarSet("data");
	_qBarSet->append(1);
	_qBarSet->append(2);
	_qBarSet->append(3);
	_qBarSet->append(4);
	if (nullptr == _series)
		_series = new QBarSeries();

	_series->append(_qBarSet);

	if (nullptr == _chart)
		_chart = new QChart();
	_chart->addSeries(_series);
	_chart->setTitle("Simple Bar Chart");
	_chart->setAnimationOptions(QChart::SeriesAnimations);
	addXAxis();
	if (nullptr == _chartView)
		_chartView = new QChartView(_chart);
	_chartView->setRenderHint(QPainter::Antialiasing);

	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->addWidget(_chartView);
	setLayout(layout);
}