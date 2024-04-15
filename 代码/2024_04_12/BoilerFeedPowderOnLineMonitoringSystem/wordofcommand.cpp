#include "wordofcommand.h"
#include <qdebug.h>
WordOfCommand::WordOfCommand(QWidget *parent)
	: QWidget(parent), ui(new Ui::WordOfCommandClass())
{
	ui->setupUi(this);
	qDebug() << "WordOfCommand()";

	this->setWindowTitle("��������");
	connect(ui->identify_pushButton, &QPushButton::clicked, [=]()
			{ emit fromWordOfCommandToMainScreenSignals(); });
	connect(ui->cancel_pushButton, &QPushButton::clicked, [=]()
			{ emit fromWordOfCommandToMainScreenSignals(); });
}

WordOfCommand::~WordOfCommand()
{
	qDebug() << "~WordOfCommand()";
	delete ui;
}