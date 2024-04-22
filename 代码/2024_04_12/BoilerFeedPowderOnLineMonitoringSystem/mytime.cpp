#include "mytime.h"
#include <qdebug.h>
MyTime::MyTime(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::MyTimeClass())
	, _timer(new QTimer(nullptr))
{
	qDebug() << "MyTime()";
	ui->setupUi(this);
	this->setWindowTitle("time");


	connect(ui->identify_pushButton, &QPushButton::clicked, [=]()
		{ emit fromMyTimeToMianScreenSignals(); });
	connect(ui->cancel_pushButton, &QPushButton::clicked, [=]()
		{ emit fromMyTimeToMianScreenSignals(); });

	connect(_timer, &QTimer::timeout, [=]() {

		// 获取当前日期和时间
		QDateTime currentDateTime = QDateTime::currentDateTime();
		// 获取当前日期
		QDate currentDate = currentDateTime.date();
		// 获取当前时间
		QTime currentTime = currentDateTime.time();

		ui->dateEdit->setDate(currentDate);
		ui->timeEdit->setTime(currentTime);
		});
	_timer->start(1000); // 1000毫秒，即1秒
}

MyTime::~MyTime()
{
	qDebug() << "~MyTime()";
	delete _timer;
	delete ui;
}
