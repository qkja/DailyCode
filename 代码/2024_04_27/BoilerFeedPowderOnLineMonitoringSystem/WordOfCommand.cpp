#include "WordOfCommand.h"

WordOfCommand::WordOfCommand(QWidget* parent, Configure* configure)
	: QWidget(parent)
	, ui(new Ui::WordOfCommandClass())
	, _configure(configure)
{
	std::cout << "WordOfCommand()" << std::endl;
	ui->setupUi(this);
	init();
}

WordOfCommand::~WordOfCommand()
{
	std::cout << "~WordOfCommand()" << std::endl;
	delete ui;
}

void WordOfCommand::init()
{
	this->setWindowTitle("ÐÞ¸Ä¿ÚÁî");
	connect(_configure, &Configure::setPasswordSignals, [=](std::string password) {
		_password = password;
		});
	connect(ui->identify_pushButton, &QPushButton::clicked, [=]() {
		std::string oldPassword = ui->old_password->text().toStdString();
		std::string newPassword = ui->new_password->text().toStdString();
		if (oldPassword == _password)
		{
			_password = newPassword;
			_configure->alterPassword(_password);
			emit fromWordOfCommandToMainScreenSignals();
		}
		else
		{
			std::cerr << oldPassword << " error" << std::endl;
			std::cerr << _password << std::endl;
			ui->old_password->clear();
			ui->new_password->clear();
		}
		});
	connect(ui->cancel_pushButton, &QPushButton::clicked, [=]()
		{ emit fromWordOfCommandToMainScreenSignals(); });
}

void WordOfCommand::closeEvent(QCloseEvent*)
{
	emit wordOfCommandCloseSignals();
}