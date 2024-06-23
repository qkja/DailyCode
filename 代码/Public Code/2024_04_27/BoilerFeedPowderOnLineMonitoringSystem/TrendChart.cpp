#include "TrendChart.h"

TrendChart::TrendChart(QWidget* parent, ResultData* resultData)
	: QMainWindow(parent)
	, ui(new Ui::TrendChartClass())
	, _result_data(resultData)
{
	ui->setupUi(this);
	init();
	std::cout << "TrendChart()" << std::endl;
}

TrendChart::~TrendChart()
{
	std::cout << "~TrendChart()" << std::endl;
	delete ui;
}

void TrendChart::init()
{
	this->setWindowTitle("趋势图");
	initMap();     // 处理哈希表
	createChart(); // 创建图标
	updateData();  // 更新数据
}

void TrendChart::closeEvent(QCloseEvent*)
{
	emit trendChartCloseSignals();
}

void TrendChart::initMap()
{
	for (int i = 1; i <= 24; i++) // 创建哈希表
	{
		std::string str = std::to_string(i);
		_wind_speed_map[str];
		_concentration_map[str];
		_temperature_1[str];
		_temperature_2[str];
		// 先开辟空间
		_wind_speed_map[str].reserve(NUMBER_OF_DATA);
		_concentration_map[str].reserve(NUMBER_OF_DATA);
		_temperature_1[str].reserve(NUMBER_OF_DATA);
		_temperature_2[str].reserve(NUMBER_OF_DATA);
	}
}

void TrendChart::updateData()
{
	// 选中之后更新数据
	connect(ui->wind_speed, &QComboBox::currentTextChanged, [=](const QString& s) {
		_updateData(WINDCHOICE, s.toStdString(), true);
		});
	connect(ui->temperature_1, &QComboBox::currentTextChanged, [=](const QString& s) {
		_updateData(TEMPERATUREONECHOICE, s.toStdString(), true);
		});
	connect(ui->temperature_2, &QComboBox::currentTextChanged, [=](const QString& s) {
		_updateData(TEMPERATURETWOCHOICE, s.toStdString(), true);
		});
	connect(ui->concentration, &QComboBox::currentTextChanged, [=](const QString& s) {
		_updateData(CONCENTRATIONCHOICE, s.toStdString(), true);
		});

	connect(_result_data, &ResultData::tendencyChartDataSignals, [=](const std::vector<struct TendencyChartData>& data) {
		// 查看我们目前的元素
		std::string windStr = ui->wind_speed->currentText().toStdString();
		std::string concentrationStr = ui->concentration->currentText().toStdString();
		std::string temperatureOneStr = ui->temperature_1->currentText().toStdString();
		std::string temperatureTwoStr = ui->temperature_2->currentText().toStdString();
		// 查一下我们数据的个数
		int num = _wind_speed_map[windStr].size();

		bool falg = false;
		if (num > NUMBER_OF_DATA)
		{
			falg = true;
			// 对于之前的所有的元素最旧的元素要删除掉
			for (int i = 0; i < 24; i++)
			{
				std::string str = std::to_string(i + 1);
				_wind_speed_map[str].erase(_wind_speed_map[str].begin()); // 删除风速的
				_concentration_map[str].erase(_concentration_map[str].begin());  // 删除密度的
				_temperature_1[str].erase(_temperature_1[str].begin());          // 删除温度1的
				_temperature_2[str].erase(_temperature_2[str].begin());// 删除温度2的
			}
		}

		// 然后把最新的数据放进来
		for (int i = 0; i < data.size(); ++i)
		{
			std::string str = std::to_string(i + 1);
			_wind_speed_map[str].push_back(data[i]._wind_speed);
			_concentration_map[str].push_back(data[i]._concentration);
			_temperature_1[str].push_back(data[i]._temperature_1);
			_temperature_2[str].push_back(data[i]._temperature_2);
		}

		if (this->isVisible())
		{
			_updateData(WINDCHOICE, windStr, falg);                    // 更行风速, 其中更新风速的windStr号数据
			_updateData(CONCENTRATIONCHOICE, concentrationStr, falg);
			_updateData(TEMPERATUREONECHOICE, temperatureOneStr, falg);
			_updateData(TEMPERATURETWOCHOICE, temperatureTwoStr, falg);

			std::cout << "update data" << std::endl;
		}
		else
		{
			std::cout << "no3: " << num << std::endl;
		}
		});
}

// dataCategory: 是24个数据的哪一个数据
// polygonalCategory: 是一组数据的风速,还是温度等
// falg 是否全部更新,还是只在后面添加数据
void TrendChart::_updateData(int polygonalCategory, const std::string& dataCategory, bool falg)
{
	if (polygonalCategory == WINDCHOICE)
	{
		if (falg)
		{
			_line_wind->clear();
			for (int i = 0; i < _wind_speed_map[dataCategory].size(); i++)
				_line_wind->append(i, _wind_speed_map[dataCategory][i]);
		}
		else
		{
			int index = _line_wind->count();
			for (index; index < _wind_speed_map[dataCategory].size(); ++index)
			{
				_line_wind->append(index, _wind_speed_map[dataCategory][index]);
			}
		}
	}
	else if (polygonalCategory == CONCENTRATIONCHOICE)
	{
		if (falg)
		{
			_line_concentration->clear();
			for (int i = 0; i < _concentration_map[dataCategory].size(); i++)
				_line_concentration->append(i, _concentration_map[dataCategory][i]);
		}
		else
		{
			int index = _line_concentration->count();

			for (index; index < _concentration_map[dataCategory].size(); ++index)
			{
				_line_concentration->append(index, _concentration_map[dataCategory][index]);
			}
		}
	}
	else if (polygonalCategory == TEMPERATUREONECHOICE)
	{
		if (falg)
		{
			_line_temperature_1->clear();
			for (int i = 0; i < _temperature_1[dataCategory].size(); i++)
				_line_temperature_1->append(i, _temperature_1[dataCategory][i]);
		}
		else
		{
			int index = _line_temperature_1->count();

			for (index; index < _temperature_1[dataCategory].size(); ++index)
			{
				_line_temperature_1->append(index, _temperature_1[dataCategory][index]);
			}
		}
	}
	else if (polygonalCategory == TEMPERATURETWOCHOICE)
	{
		if (falg)
		{
			_line_temperature_2->clear();
			for (int i = 0; i < _temperature_2[dataCategory].size(); i++)
				_line_temperature_2->append(i, _temperature_2[dataCategory][i]);
		}
		else
		{
			int index = _line_temperature_2->count();

			for (index; index < _temperature_2[dataCategory].size(); ++index)
			{
				_line_temperature_2->append(index, _temperature_2[dataCategory][index]);
			}
		}
	}
	else
	{
		std::cerr << "error" << std::endl;
	}
	_chart->update();
	dataCategory;

	ui->lineEdit->setText(std::to_string(_wind_speed_map[dataCategory].back()).c_str());
	ui->lineEdit_3->setText(std::to_string(_concentration_map[dataCategory].back()).c_str());
	ui->lineEdit_2->setText(std::to_string(_temperature_1[dataCategory].back()).c_str());
	ui->lineEdit_4->setText(std::to_string(_temperature_2[dataCategory].back()).c_str());
}

void TrendChart::createChart()
{
	//  创建视图
	_chartView = new QChartView(this);
	//  创建文档类
	_chart = new QChart();
	// 设置名字
	_chart->setTitle("line");
	// 设置_chart
	_chartView->setChart(_chart);

	// 设计视图的位置
	_chartView->resize(800, 400);
	_chartView->move(100, 200);
	// 启用抗锯齿
	_chartView->setRenderHint(QPainter::Antialiasing);

	// 实例化 风速,浓度, 温度1, 温度2曲线
	_line_wind = new QLineSeries();
	_line_concentration = new QLineSeries();
	_line_temperature_1 = new QLineSeries();
	_line_temperature_2 = new QLineSeries();

	// 给曲线起名字
	_line_wind->setName("_line_wind");
	_line_concentration->setName("_line_concentration");
	_line_temperature_1->setName("_line_temperature_1");
	_line_temperature_2->setName("_line_temperature_2");

	// 添加曲线到chart中
	_chart->addSeries(_line_wind);
	_chart->addSeries(_line_concentration);
	_chart->addSeries(_line_temperature_1);
	_chart->addSeries(_line_temperature_2);

	// 实例化坐标轴
	_x = new QValueAxis;
	_y_wind = new QValueAxis;
	_y_concentration = new QValueAxis;
	_y_temperature_1 = new QValueAxis;
	_y_temperature_2 = new QValueAxis;
	// 给坐标轴设置名字
	/*_x->setTitleText("x");
	_y_wind->setTitleText("_y_wind");
	_y_concentration->setTitleText(" _y_concentration");
	_y_temperature_1->setTitleText(" _y_temperature_1");
	_y_temperature_2->setTitleText(" _y_temperature_2");*/

	// 给轴设置范围
	_x->setRange(0, NUMBER_OF_DATA);
	_y_wind->setRange(0, 100);
	_y_concentration->setRange(0, 100);
	_y_temperature_1->setRange(0, 100);
	_y_temperature_2->setRange(0, 100);

	// 将坐标轴添加到chart中
	_chart->addAxis(_x, Qt::AlignBottom);
	_chart->addAxis(_y_wind, Qt::AlignLeft);
	_chart->addAxis(_y_concentration, Qt::AlignLeft);
	_chart->addAxis(_y_temperature_1, Qt::AlignLeft);
	_chart->addAxis(_y_temperature_2, Qt::AlignLeft);

	// 将数据和坐标轴关联起来
	_line_wind->attachAxis(_x);
	_line_wind->attachAxis(_y_wind);
	_line_concentration->attachAxis(_x);
	_line_concentration->attachAxis(_y_concentration);
	_line_temperature_1->attachAxis(_x);
	_line_temperature_1->attachAxis(_y_temperature_1);
	_line_temperature_2->attachAxis(_x);
	_line_temperature_2->attachAxis(_y_temperature_2);
}