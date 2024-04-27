#include "AlarmDatabase.h"

AlarmDatabase::AlarmDatabase(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::AlarmDatabaseClass())
{
	ui->setupUi(this);
	init();
	std::cout << "AlarmDatabase()" << std::endl;
}

AlarmDatabase::~AlarmDatabase()
{
	delete ui;
	std::cout << "~AlarmDatabase()" << std::endl;
}

void AlarmDatabase::init()
{
	this->setWindowTitle("±¨¾¯Êý¾Ý");
	connect(ui->quit_pushButton, &QPushButton::clicked, [=]()
		{ emit fromAlarmDatabaseToMainScreenSignals(); });
}

void AlarmDatabase::closeEvent(QCloseEvent*)
{
	emit alarmDatabaseCloseSignals();
}