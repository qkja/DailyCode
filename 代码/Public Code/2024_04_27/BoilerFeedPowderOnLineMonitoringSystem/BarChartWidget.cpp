#include "barchartwidget.h"

BarChartWidget::BarChartWidget(QWidget* parent)
	: QWidget(parent)
{
	std::cout << "BarChartWidget()" << std::endl;
}

BarChartWidget::~BarChartWidget()
{
	delete _chartView;
	std::cout << "~BarChartWidget()" << std::endl;
}

// 设置Y轴的范围
void BarChartWidget::setRange(int begin, int end)
{
	_axisY->setRange(begin, end);
}
// 写数据
void BarChartWidget::writeData(const std::vector<double>& data)
{
	if (_set->count() != 0)
	{
		for (int i = 0; i < data.size(); ++i)
		{
			_set->replace(i, data[i]);
		}
	}
	else
	{
		for (int i = 0; i < data.size(); ++i)
		{
			_set->append(data[i]);
		}
	}
	addXAxis(); // 更新X数据
	_chart->update(); // 更新图形
}

// 创建折线图
void BarChartWidget::createChart(int width, int height, int x, int y, const std::string& name)
{
	_chartView = new QChartView(this->parentWidget());
	_chart = new QChart();
	_chartView->resize(width, height);
	_chartView->move(x, y);
	_chartView->setChart(_chart);
	_series = new QBarSeries();
	_set = new QBarSet(name.c_str());
	_series->append(_set);
	_chart->addSeries(_series);

	_axisX = new QBarCategoryAxis();
	_chart->addAxis(_axisX, Qt::AlignBottom);
	_series->attachAxis(_axisX);
	_axisY = new QValueAxis();
	_chart->addAxis(_axisY, Qt::AlignLeft);
	_series->attachAxis(_axisY);
}

// 给折线图添加X轴
void BarChartWidget::addXAxis()
{
	QStringList categories;
	for (int i = 0; i < _set->count(); ++i) {
		categories << QString::number(_set->at(i));
	}
	_axisX->setCategories(categories);
}