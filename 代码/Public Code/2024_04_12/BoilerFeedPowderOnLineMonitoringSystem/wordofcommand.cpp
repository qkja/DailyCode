#include "wordofcommand.h"
#include <qdebug.h>
WordOfCommand::WordOfCommand(QWidget* parent, Configure* configure)
	: QWidget(parent)
	, ui(new Ui::WordOfCommandClass())
	, _configure(configure)
{
	ui->setupUi(this);
	qDebug() << "WordOfCommand()";

	this->setWindowTitle("modify");

	connect(_configure, &Configure::setPasswordSignals, [=](std::string password) {
		_password = password;
		});

	connect(ui->identify_pushButton, &QPushButton::clicked, [=]()
		{
			std::string oldPassword = ui->old_password->text().toStdString();
			std::string newPassword = ui->new_password->text().toStdString();
			if (oldPassword == _password)
			{
				_password = newPassword;
				emit fromWordOfCommandToMainScreenToSaveSignals(_password);
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

WordOfCommand::~WordOfCommand()
{
	qDebug() << "~WordOfCommand()";
	delete ui;
}