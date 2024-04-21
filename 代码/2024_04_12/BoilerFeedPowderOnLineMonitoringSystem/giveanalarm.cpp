#include "giveanalarm.h"
#include <qdebug.h>
GiveAnAlarm::GiveAnAlarm(QWidget *parent, Configure* configure)
	: QWidget(parent)
	, _configure(configure)
	, ui(new Ui::GiveAnAlarmClass())
{
	ui->setupUi(this);
	qDebug() << "GiveAnAlarm()";
	this->setWindowTitle("sss");
	myConnect();

}

GiveAnAlarm::~GiveAnAlarm()
{
	delete ui;
	qDebug() << "~GiveAnAlarm()";
}

void GiveAnAlarm::myConnect()
{

	// 当垂直滑块滑动时，它会发出valueChanged(int)信号
	connect(ui->upper_wind_speed, &QSlider::valueChanged, [=](int val) {
		ui->label_26->setText(std::to_string(val).c_str());
		});
	connect(ui->limit_wind_speed, &QSlider::valueChanged, [=](int val) {
		ui->label_28->setText(std::to_string(val).c_str());
		});
	// 这里存在一个小数
	connect(ui->upper_limit_of_pulverized_coal_concentration, &QSlider::valueChanged, [=](int val) {
		ui->label_32->setText(intToStr(val).c_str());
		});
	connect(ui->limit_limit_of_pulverized_coal_concentration, &QSlider::valueChanged, [=](int val) {
		ui->label_34->setText(intToStr(val).c_str());
		});
	connect(ui->upper_temperature, &QSlider::valueChanged, [=](int val) {
		ui->label_36->setText(std::to_string(val).c_str());
		});
	connect(ui->limit_temperature, &QSlider::valueChanged, [=](int val) {
		ui->label_38->setText(std::to_string(val).c_str());
		});
	

	// 设置当前值
	connect(_configure, &Configure::setAlarmLimitValueSignals, [=](std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, std::string s6) {
		ui->upper_wind_speed->setValue(std::stoi(s2));
		ui->limit_wind_speed->setValue(std::stoi(s1));
		ui->upper_limit_of_pulverized_coal_concentration->setValue(strfromDoubleToInt(s4));
		ui->limit_limit_of_pulverized_coal_concentration->setValue(strfromDoubleToInt(s3));
		ui->upper_temperature->setValue(std::stoi(s6));
		ui->limit_temperature->setValue(std::stoi(s5));
		});
	// 设置范围
	connect(_configure, &Configure::setAlarmLimitRangeSignals, [=](std::string s1, std::string s2, std::string s3, std::string s4, std::string s5 , std::string s6) {
		    // 设置范围
		    ui->upper_wind_speed->setRange(std::stoi(s1), std::stoi(s2));
			ui->limit_wind_speed->setRange(std::stoi(s1), std::stoi(s2));
			ui->upper_limit_of_pulverized_coal_concentration->setRange(strfromDoubleToInt(s3), strfromDoubleToInt(s4));
			ui->limit_limit_of_pulverized_coal_concentration->setRange(strfromDoubleToInt(s3), strfromDoubleToInt(s4));
			ui->upper_temperature->setRange(std::stoi(s5), std::stoi(s6));
			ui->limit_temperature->setRange(std::stoi(s5), std::stoi(s6));

			// 数据提示
			ui->label_2->setText(s1.c_str());
			ui->label_4->setText(s1.c_str());
			ui->label_1->setText(s2.c_str());
			ui->label_3->setText(s2.c_str());

			ui->label_6->setText(s3.c_str());
			ui->label_8->setText(s3.c_str());
			ui->label_5->setText(s4.c_str());
			ui->label_7->setText(s4.c_str());

			ui->label_10->setText(s5.c_str());
			ui->label_12->setText(s5.c_str());
			ui->label_9->setText(s6.c_str());
			ui->label_11->setText(s6.c_str());
		});


	

	connect(ui->identify_pushButton, &QPushButton::clicked, [=]()
		{ 
			std::string upper_wind_speed_val = ui->label_26->text().toStdString();
			std::string limit_wind_speed_val = ui->label_28->text().toStdString();
			std::string upper_limit_of_pulverized_coal_concentration_val = ui->label_32->text().toStdString();
			std::string limit_limit_of_pulverized_coal_concentration_val = ui->label_34->text().toStdString();
			std::string upper_temperature_val = ui->label_36->text().toStdString();
			std::string limit_temperature_val = ui->label_38->text().toStdString();

			emit fromGiveAnAlarmToMainScreenToSaveSignals(limit_wind_speed_val, upper_wind_speed_val,
				limit_limit_of_pulverized_coal_concentration_val, upper_limit_of_pulverized_coal_concentration_val,
				limit_temperature_val, upper_temperature_val);
		});
	connect(ui->cancel_pushButton, &QPushButton::clicked, [=]()
		{ emit fromGiveAnAlarmToMainScreenSignals(); });

}


int GiveAnAlarm::strfromDoubleToInt(std::string& str)
{
	return 10*std::stod(str);
}

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
