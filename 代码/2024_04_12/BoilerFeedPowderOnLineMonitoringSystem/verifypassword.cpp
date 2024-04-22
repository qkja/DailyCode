#include "verifypassword.h"
#include "qdebug.h"
VerifyPassword::VerifyPassword(QWidget *parent, Configure* configure)
	: QWidget(parent)
	, ui(new Ui::VerifyPasswordClass())
	, _configure(configure)
{
	qDebug() << "VerifyPassword()";
	ui->setupUi(this);
	this->setWindowTitle("check");
	connect(_configure, &Configure::setPasswordSignals, [=](std::string password) {
		_password = password;
		});
	connect(ui->identify_pushButton, &QPushButton::clicked, [=]()
			{ 
			std::string passward = ui->lineEdit->text().toStdString();
			if (_password == passward)
			{
				emit fromVerifyPasswordSignalsIsTrue();
			}
			else
			{
				std::cerr << passward << " error!!!" << std::endl;
				ui->lineEdit->clear();
			}
		});
	connect(ui->cancel_pushButton, &QPushButton::clicked, [=]()
			{ emit fromVerifyPasswordSignalsIsFalse(); });
}

VerifyPassword::~VerifyPassword()
{
	qDebug() << "~VerifyPassword()";
	delete ui;
}

void VerifyPassword::closeEvent(QCloseEvent *)
{
	emit ExitWin();
}