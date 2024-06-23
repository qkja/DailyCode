#include "VerifyPassword.h"
/*
* ��֤����Ĺ���
*/

VerifyPassword::VerifyPassword(QWidget* parent, Configure* configure)
	: QWidget(parent)
	, ui(new Ui::VerifyPasswordClass())
	, _configure(configure)
{
	ui->setupUi(this);
	init();
	std::cout << "VerifyPassword()" << std::endl;
}

VerifyPassword::~VerifyPassword()
{
	std::cout << "~VerifyPassword()" << std::endl;
	delete ui;
}

void VerifyPassword::init()
{
	this->setWindowTitle("��֤����");

	connect(_configure, &Configure::setPasswordSignals, [=](std::string password) {
		_password = password;
		ui->lineEdit->clear();
		});

	connect(ui->identify_pushButton, &QPushButton::clicked, [=]() {
		std::string passward = ui->lineEdit->text().toStdString();
		if (_password == passward)
		{
			if (1 == _option)
			{
				emit fromVerifyPasswordToSpoutSignalsIsTrue(); // ���������ȷ��
			}
			else if (2 == _option)
			{
				emit fromVerifyPasswordToBackrestCanalSignalsIsTrue(); // ��ϵ������ȷ��
			}
			else
			{
				std::cerr << "please choose" << std::endl;
			}
		}
		else
		{
			std::cerr << passward << " error!!!" << std::endl;
			std::cout << "right passward: " << _password << std::endl;
			ui->lineEdit->clear();
		}
		});
	connect(ui->cancel_pushButton, &QPushButton::clicked, [=]() {
		emit fromVerifyPasswordSignalsIsFalse(); });
}

void VerifyPassword::setOption(int option)
{
	_option = option;
}

void VerifyPassword::closeEvent(QCloseEvent*)
{
	emit verifyPasswordCloseSignals();
}