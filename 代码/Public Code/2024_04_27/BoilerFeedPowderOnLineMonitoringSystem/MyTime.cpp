#include "MyTime.h"

MyTime::MyTime(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::MyTimeClass())
	, _timer(new QTimer(nullptr))
{
	std::cout << "MyTime()" << std::endl;
	ui->setupUi(this);
	init();
}

MyTime::~MyTime()
{
	std::cout << "~MyTime()" << std::endl;
	delete _timer;
	delete ui;
}

void MyTime::init()
{
	this->setWindowTitle("�޶�ʱ��");

	connect(ui->identify_pushButton, &QPushButton::clicked, [=]()
		{ emit fromMyTimeToMianScreenSignals(); });
	connect(ui->cancel_pushButton, &QPushButton::clicked, [=]()
		{ emit fromMyTimeToMianScreenSignals(); });

	connect(_timer, &QTimer::timeout, [=]() {
		// ��ȡ��ǰ���ں�ʱ��
		QDateTime currentDateTime = QDateTime::currentDateTime();
		// ��ȡ��ǰ����
		QDate currentDate = currentDateTime.date();
		// ��ȡ��ǰʱ��
		QTime currentTime = currentDateTime.time();

		ui->dateEdit->setDate(currentDate);
		ui->timeEdit->setTime(currentTime);
		});
	_timer->start(1000); // 1000���룬��1��
}

void MyTime::closeEvent(QCloseEvent*)
{
	emit myTimeCloseSignals();
}