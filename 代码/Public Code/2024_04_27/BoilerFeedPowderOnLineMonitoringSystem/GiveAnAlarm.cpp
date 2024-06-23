#include "GiveAnAlarm.h"

GiveAnAlarm::GiveAnAlarm(QWidget* parent, Configure* configure)
	: QWidget(parent)
	, _configure(configure)
	, ui(new Ui::GiveAnAlarmClass())
{
	ui->setupUi(this);
	std::cout << "GiveAnAlarm()" << std::endl;
	init();
}

GiveAnAlarm::~GiveAnAlarm()
{
	std::cout << "~GiveAnAlarm()" << std::endl;
	delete ui;
}

void GiveAnAlarm::init()
{
	this->setWindowTitle("设定报警限");

	// 当垂直滑块滑动时，它会发出valueChanged(int)信号
	connect(ui->upper_wind_speed, &QSlider::valueChanged, [=](int val) {
		ui->label_26->setText(std::to_string(val).c_str());
		});
	connect(ui->limit_wind_speed, &QSlider::valueChanged, [=](int val) {
		ui->label_28->setText(std::to_string(val).c_str());
		});
	connect(ui->upper_temperature, &QSlider::valueChanged, [=](int val) {
		ui->label_36->setText(std::to_string(val).c_str());
		});
	connect(ui->limit_temperature, &QSlider::valueChanged, [=](int val) {
		ui->label_38->setText(std::to_string(val).c_str());
		});
	// 这里存在一个小数
	connect(ui->upper_limit_of_pulverized_coal_concentration, &QSlider::valueChanged, [=](int val) {
		ui->label_32->setText(intToStr(val).c_str());
		});
	connect(ui->limit_limit_of_pulverized_coal_concentration, &QSlider::valueChanged, [=](int val) {
		ui->label_34->setText(intToStr(val).c_str());
		});

	// 设置当前值
	connect(_configure, &Configure::setAlarmLimitValueSignals, [=](const std::vector<std::string>& v) {
		ui->upper_wind_speed->setValue(std::stoi(v[1]));
		ui->limit_wind_speed->setValue(std::stoi(v[0]));
		ui->upper_limit_of_pulverized_coal_concentration->setValue(strfromDoubleToInt(v[3]));
		ui->limit_limit_of_pulverized_coal_concentration->setValue(strfromDoubleToInt(v[2]));
		ui->upper_temperature->setValue(std::stoi(v[5]));
		ui->limit_temperature->setValue(std::stoi(v[4]));
		});
	// 设置范围
	connect(_configure, &Configure::setAlarmLimitRangeSignals, [=](const std::vector<std::string>& v) {
		// 设置范围
		ui->upper_wind_speed->setRange(std::stoi(v[0]), std::stoi(v[1]));
		ui->limit_wind_speed->setRange(std::stoi(v[0]), std::stoi(v[1]));
		ui->upper_limit_of_pulverized_coal_concentration->setRange(strfromDoubleToInt(v[2]), strfromDoubleToInt(v[3]));
		ui->limit_limit_of_pulverized_coal_concentration->setRange(strfromDoubleToInt(v[2]), strfromDoubleToInt(v[3]));
		ui->upper_temperature->setRange(std::stoi(v[4]), std::stoi(v[5]));
		ui->limit_temperature->setRange(std::stoi(v[4]), std::stoi(v[5]));

		// 数据提示
		ui->label_2->setText(v[0].c_str());
		ui->label_4->setText(v[0].c_str());
		ui->label_1->setText(v[1].c_str());
		ui->label_3->setText(v[1].c_str());

		ui->label_6->setText(v[2].c_str());
		ui->label_8->setText(v[2].c_str());
		ui->label_5->setText(v[3].c_str());
		ui->label_7->setText(v[3].c_str());

		ui->label_10->setText(v[4].c_str());
		ui->label_12->setText(v[4].c_str());
		ui->label_9->setText(v[5].c_str());
		ui->label_11->setText(v[5].c_str());
		});
	// 确定修改
	connect(ui->identify_pushButton, &QPushButton::clicked, [=]()
		{
			std::string upper_wind_speed_val = ui->label_26->text().toStdString();
			std::string limit_wind_speed_val = ui->label_28->text().toStdString();
			std::string upper_limit_of_pulverized_coal_concentration_val = ui->label_32->text().toStdString();
			std::string limit_limit_of_pulverized_coal_concentration_val = ui->label_34->text().toStdString();
			std::string upper_temperature_val = ui->label_36->text().toStdString();
			std::string limit_temperature_val = ui->label_38->text().toStdString();

			// 只需要在这里修改就可以了
			std::vector<std::string> v;
			v.push_back(limit_wind_speed_val);
			v.push_back(upper_wind_speed_val);
			v.push_back(limit_limit_of_pulverized_coal_concentration_val);
			v.push_back(upper_limit_of_pulverized_coal_concentration_val);
			v.push_back(limit_temperature_val);
			v.push_back(upper_temperature_val);
			_configure->alterAlarmLimitValue(v);
			emit fromGiveAnAlarmToMainScreenSignals();
		});
	connect(ui->cancel_pushButton, &QPushButton::clicked, [=]() {
		emit fromGiveAnAlarmToMainScreenSignals(); });
}

void GiveAnAlarm::closeEvent(QCloseEvent*)
{
	emit giveAnAlarmCloseSignals();
}

int GiveAnAlarm::strfromDoubleToInt(const std::string& str)
{
	return 10 * std::stod(str);
}
// 整数转字符串
std::string GiveAnAlarm::intToStr(int val)
{
	std::string result;
	if (val < 10)
	{
		result += "0.";
		result += ('0' + val);
	}
	else
	{
		result = std::to_string(val);
		char ch = result.back();
		result.pop_back();
		result += ".";
		result += ch;
	}
	return result;
}