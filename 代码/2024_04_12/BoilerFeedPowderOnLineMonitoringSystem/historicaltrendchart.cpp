#include "historicaltrendchart.h"
#include <Windows.h>
HistoricalTrendChart::HistoricalTrendChart(QWidget* parent, ResultData* resultData)
	: QMainWindow(parent)
	, ui(new Ui::HistoricalTrendChartClass())
	, _resultData(resultData)
	, _left_wind(0)
	, _right_wind(0)
	, _left_concentration(0)
	, _right_concentration(0)
	, _left_temperature_1(0)
	, _right_temperature_1(0)
	, _left_temperature_2(0)
	, _right_temperature_2(0)
	, _left_right_clickde(false)
{
	ui->setupUi(this);

	std::cout << "HistoricalTrendChart()" << std::endl;
	init();
}

HistoricalTrendChart::~HistoricalTrendChart()
{
	std::cout << "~HistoricalTrendChart()" << std::endl;
	delete ui;
}

void HistoricalTrendChart::init()
{
	initMap();     // 处理哈希表
	createChart(); // 创建图标
	updateData();  // 更新数据
}

void HistoricalTrendChart::initMap()
{
	for (int i = 1; i <= 24; i++) // 创建哈希表
	{
		std::string str = std::to_string(i);
		_wind_speed_map[str];
		_concentration_map[str];
		_temperature_1_map[str];
		_temperature_2_map[str];
	}
}

void HistoricalTrendChart::updateData()
{
	// 选中之后更新数据
	connect(ui->wind_speed, &QComboBox::currentTextChanged, [=](const QString& s) {
		// 只有图新上面已经出现了,我们才更新图形
		if (_line_wind->count())
			_updateData(WINDCHOICE_HIS, s.toStdString(), _left_wind, _right_wind);
		});
	connect(ui->temperature_1, &QComboBox::currentTextChanged, [=](const QString& s) {
		if (_line_temperature_1->count())
			_updateData(CONCENTRATIONCHOICE_HIS, s.toStdString(), _left_concentration, _right_concentration);
		});
	connect(ui->temperature_2, &QComboBox::currentTextChanged, [=](const QString& s) {
		if (_line_temperature_2->count())
			_updateData(TEMPERATUREONECHOICE_HIS, s.toStdString(), _left_temperature_1, _right_temperature_1);
		});
	connect(ui->concentration, &QComboBox::currentTextChanged, [=](const QString& s) {
		if (_line_concentration->count())
			_updateData(TEMPERATURETWOCHOICE_HIS, s.toStdString(), _left_temperature_2, _right_temperature_2);
		});

	// 显示数据
	connect(ui->pushButton, &QPushButton::clicked, [=]() {
		std::string windStr = ui->wind_speed->currentText().toStdString();
		std::string concentrationStr = ui->concentration->currentText().toStdString();
		std::string temperatureOneStr = ui->temperature_1->currentText().toStdString();
		std::string temperatureTwoStr = ui->temperature_2->currentText().toStdString();
		_updateData(WINDCHOICE_HIS, windStr, _left_wind, _right_wind);
		_updateData(CONCENTRATIONCHOICE_HIS, concentrationStr, _left_concentration, _right_concentration);
		_updateData(TEMPERATUREONECHOICE_HIS, temperatureOneStr, _left_temperature_1, _right_temperature_1);
		_updateData(TEMPERATURETWOCHOICE_HIS, temperatureTwoStr, _left_temperature_2, _right_temperature_2);
		});

	connect(ui->pushButton_left, &QPushButton::clicked, [=]() {
		_left_right_clickde = true;
		std::string windStr = ui->wind_speed->currentText().toStdString();
		std::string concentrationStr = ui->concentration->currentText().toStdString();
		std::string temperatureOneStr = ui->temperature_1->currentText().toStdString();
		std::string temperatureTwoStr = ui->temperature_2->currentText().toStdString();
		if (_line_wind->count())
		{
			_right_wind = std::max(0, (int)(_line_wind->at(_line_wind->count() - 1).x() - STEP_SIZE - 1));
			_left_wind = std::max(0, _right_wind - STAGE_FREQUENCY);
			if (!_wind_speed_map[windStr].empty() && _right_wind == 0)
			{
				// 为了避免我们_left_wind和_right_wind都是0的情况,刷新不出图形
				// 但是这里有一个问题,我们把_right_wind值为, 如果我们数组没有数据,
				// 那么这个图新还是不会显示,这里的概率很小, 毕竟的人的操作速度还是慢于计算机的, 暂时先忽略
				_right_wind = 1;
			}
			_updateData(WINDCHOICE_HIS, windStr, _left_wind, _right_wind);
		}
		if (_line_concentration->count())
		{
			_right_concentration = std::max(0, (int)(_line_concentration->at(_line_concentration->count() - 1).x() - STEP_SIZE - 1));
			_left_concentration = std::max(0, _right_concentration - STAGE_FREQUENCY);

			if (!_concentration_map[concentrationStr].empty() && _right_concentration == 0)
			{
				_right_concentration = 1;
			}
			_updateData(CONCENTRATIONCHOICE_HIS, concentrationStr, _left_concentration, _right_concentration);
		}
		if (_line_temperature_1->count())
		{
			_right_temperature_1 = std::max(0, (int)(_line_temperature_1->at(_line_temperature_1->count() - 1).x() - STEP_SIZE - 1));
			_left_temperature_1 = std::max(0, _right_temperature_1 - STAGE_FREQUENCY);
			if (!_temperature_1_map[temperatureOneStr].empty() && _right_temperature_1 == 0)
			{
				_right_temperature_1 = 1;
			}
			_updateData(TEMPERATUREONECHOICE_HIS, temperatureOneStr, _left_temperature_1, _right_temperature_1);
		}
		if (_line_temperature_2->count())
		{
			_right_temperature_2 = std::max(0, (int)(_line_temperature_2->at(_line_temperature_2->count() - 1).x() - STEP_SIZE - 1));
			_left_temperature_2 = std::max(0, _right_temperature_2 - STAGE_FREQUENCY);
			if (!_temperature_2_map[temperatureTwoStr].empty() && _right_temperature_2 == 0)
			{
				_right_temperature_2 = 1;
			}
			_updateData(TEMPERATURETWOCHOICE_HIS, temperatureTwoStr, _left_temperature_2, _right_temperature_2);
		}
		});

	connect(ui->pushButton_right, &QPushButton::clicked, [=]() {
		_left_right_clickde = true;

		std::string windStr = ui->wind_speed->currentText().toStdString();
		std::string concentrationStr = ui->concentration->currentText().toStdString();
		std::string temperatureOneStr = ui->temperature_1->currentText().toStdString();
		std::string temperatureTwoStr = ui->temperature_2->currentText().toStdString();

		if (_line_wind->count())
		{
			_right_wind = std::min((int)(_wind_speed_map[windStr].size()), std::min(NUMBER_OF_DATA_HIS + 1, (int)(_line_wind->at(_line_wind->count() - 1).x() + STEP_SIZE + 1)));

			_left_wind = std::max(0, _right_wind - STAGE_FREQUENCY);
			if (!_wind_speed_map[windStr].empty() && _right_wind == 0)
			{
				// 为了避免我们_left_wind和_right_wind都是0的情况,刷新不出图形
				// 但是这里有一个问题,我们把_right_wind值为, 如果我们数组没有数据,
				// 那么这个图新还是不会显示,这里的概率很小, 毕竟的人的操作速度还是慢于计算机的, 暂时先忽略
				_right_wind = 1;
			}
			_updateData(WINDCHOICE_HIS, windStr, _left_wind, _right_wind);
		}

		if (_line_concentration->count())
		{
			_right_concentration = std::min((int)(_concentration_map[concentrationStr].size()), std::min(NUMBER_OF_DATA_HIS + 1, (int)(_line_concentration->at(_line_concentration->count() - 1).x() + STEP_SIZE + 1)));

			_left_concentration = std::max(0, _right_concentration - STAGE_FREQUENCY);

			if (!_concentration_map[concentrationStr].empty() && _right_concentration == 0)
			{
				_right_concentration = 1;
			}
			_updateData(CONCENTRATIONCHOICE_HIS, concentrationStr, _left_concentration, _right_concentration);
		}
		if (_line_temperature_1->count())
		{
			_right_temperature_1 = std::min((int)(_temperature_1_map[temperatureOneStr].size()), std::min(NUMBER_OF_DATA_HIS + 1, (int)(_line_temperature_1->at(_line_temperature_1->count() - 1).x() + STEP_SIZE + 1)));

			_left_temperature_1 = std::max(0, _right_temperature_1 - STAGE_FREQUENCY);
			if (!_temperature_1_map[temperatureOneStr].empty() && _right_temperature_1 == 0)
			{
				_right_temperature_1 = 1;
			}
			_updateData(TEMPERATUREONECHOICE_HIS, temperatureOneStr, _left_temperature_1, _right_temperature_1);
		}
		if (_line_temperature_2->count())
		{
			_right_temperature_2 = std::min((int)(_temperature_2_map[temperatureTwoStr].size()), std::min(NUMBER_OF_DATA_HIS + 1, (int)(_line_temperature_2->at(_line_temperature_2->count() - 1).x() + STEP_SIZE + 1)));

			_left_temperature_2 = std::max(0, _right_temperature_2 - STAGE_FREQUENCY);
			if (!_temperature_2_map[temperatureTwoStr].empty() && _right_temperature_2 == 0)
			{
				_right_temperature_2 = 1;
			}
			_updateData(TEMPERATURETWOCHOICE_HIS, temperatureTwoStr, _left_temperature_2, _right_temperature_2);
		}
		});

	connect(_resultData, &ResultData::tendencyChartDataSignals, [=](const std::vector<struct TendencyChartData>& data) {
		// 查看我们目前的元素
		std::string windStr = ui->wind_speed->currentText().toStdString();
		std::string concentrationStr = ui->concentration->currentText().toStdString();
		std::string temperatureOneStr = ui->temperature_1->currentText().toStdString();
		std::string temperatureTwoStr = ui->temperature_2->currentText().toStdString();
		// 查一下我们数据的个数
		int num = _wind_speed_map[windStr].size();
		if (num > NUMBER_OF_DATA_HIS)
		{
			// 对于之前的所有的元素最旧的元素要删除掉
			for (int i = 0; i < 24; i++)
			{
				std::string str = std::to_string(i + 1);
				_wind_speed_map[str].erase(_wind_speed_map[str].begin());       // 删除风速的
				_concentration_map[str].erase(_concentration_map[str].begin());  // 删除密度的
				_temperature_1_map[str].erase(_temperature_1_map[str].begin());          // 删除温度1的
				_temperature_2_map[str].erase(_temperature_2_map[str].begin());         // 删除温度2的
			}
		}

		// 然后把最新的数据放进来
		for (int i = 0; i < data.size(); ++i)
		{
			std::string str = std::to_string(i + 1);
			_wind_speed_map[str].push_back(data[i]._wind_speed);
			_concentration_map[str].push_back(data[i]._concentration);
			_temperature_1_map[str].push_back(data[i]._temperature_1);
			_temperature_2_map[str].push_back(data[i]._temperature_2);
		}

		// 计算我们的区域范围, 这里是两个标准
		if (_left_right_clickde)
		{
			_right_wind = std::min((int)(_line_wind->at(_line_wind->count() - 1).x() + 2), NUMBER_OF_DATA_HIS + 1);
			_right_concentration = std::min((int)(_line_concentration->at(_line_concentration->count() - 1).x() + 2), NUMBER_OF_DATA_HIS + 1);
			_right_temperature_1 = std::min((int)(_line_temperature_1->at(_line_temperature_1->count() - 1).x() + 2), NUMBER_OF_DATA_HIS + 1);
			_right_temperature_2 = std::min((int)(_line_temperature_2->at(_line_temperature_2->count() - 1).x() + 2), NUMBER_OF_DATA_HIS + 1);
		}
		else
		{
			_right_wind = _wind_speed_map[windStr].size();
			_right_concentration = _concentration_map[concentrationStr].size();
			_right_temperature_1 = _temperature_1_map[temperatureOneStr].size();
			_right_temperature_2 = _temperature_2_map[temperatureTwoStr].size();
		}

		_left_wind = std::max(0, _right_wind - STAGE_FREQUENCY);
		_left_concentration = std::max(0, _right_concentration - STAGE_FREQUENCY);
		_left_temperature_1 = std::max(0, _right_temperature_1 - STAGE_FREQUENCY);
		_left_temperature_2 = std::max(0, _right_temperature_2 - STAGE_FREQUENCY);

		// 更新图形
		if (_line_wind->count())
			_updateData(WINDCHOICE_HIS, windStr, _left_wind, _right_wind);
		if (_line_temperature_2->count())
			_updateData(CONCENTRATIONCHOICE_HIS, concentrationStr, _left_concentration, _right_concentration);
		if (_line_concentration->count())
			_updateData(TEMPERATUREONECHOICE_HIS, temperatureOneStr, _left_temperature_1, _right_temperature_1);
		if (_line_temperature_1->count())
			_updateData(TEMPERATURETWOCHOICE_HIS, temperatureTwoStr, _left_temperature_2, _right_temperature_2);

		std::cout << "数据更新" << std::endl;
		});
}

void HistoricalTrendChart::_updateData(int polygonalCategory, const std::string& dataCategory, int left, int right)
{
	if (polygonalCategory == WINDCHOICE_HIS)
	{
		_line_wind->clear();
		std::cout << "WINDCHOICE_HIS : " << dataCategory << " : " << _wind_speed_map[dataCategory][right - 1] << std::endl;
		for (int i = left; i < right; i++)
			_line_wind->append(i, _wind_speed_map[dataCategory][i]);
		ui->lineEdit->setText(std::to_string(_wind_speed_map[dataCategory][std::max(0, right - 1)]).c_str());
	}
	else if (polygonalCategory == CONCENTRATIONCHOICE_HIS)
	{
		_line_concentration->clear();
		for (int i = left; i < right; i++)
			_line_concentration->append(i, _concentration_map[dataCategory][i]);
		ui->lineEdit_3->setText(std::to_string(_concentration_map[dataCategory][std::max(0, right - 1)]).c_str());
	}
	else if (polygonalCategory == TEMPERATUREONECHOICE_HIS)
	{
		_line_temperature_1->clear();
		for (int i = left; i < right; i++)
			_line_temperature_1->append(i, _temperature_1_map[dataCategory][i]);
		ui->lineEdit_2->setText(std::to_string(_temperature_1_map[dataCategory][std::max(0, right - 1)]).c_str());
	}
	else if (polygonalCategory == TEMPERATURETWOCHOICE_HIS)
	{
		_line_temperature_2->clear();
		for (int i = left; i < right; i++)
			_line_temperature_2->append(i, _temperature_2_map[dataCategory][i]);
		ui->lineEdit_4->setText(std::to_string(_temperature_2_map[dataCategory][std::max(0, right - 1)]).c_str());
	}
	else
	{
		std::cerr << "error" << std::endl;
	}

	_chart->update();
}

void HistoricalTrendChart::createChart()
{
	// 创建视图
	_chartView = new QChartView(this);
	// 创建文档类
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

	// 给轴设置范围
	_x->setRange(0, NUMBER_OF_DATA_HIS);
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