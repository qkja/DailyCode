#include "ChannelDatabase.h"

ChannelDatabase::ChannelDatabase(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::ChannelDatabaseClass())
{
	ui->setupUi(this);
	init();
	std::cout << "ChannelDatabase()" << std::endl;
}

ChannelDatabase::~ChannelDatabase()
{
	std::cout << "~ChannelDatabase()" << std::endl;

	delete ui;
}

void ChannelDatabase::init()
{
	this->setWindowTitle("通道数据");
	connect(ui->quit_pushButton, &QPushButton::clicked, [=]()
		{ emit fromChannelDatabaseToMainScreenSignals(); });
}

void ChannelDatabase::closeEvent(QCloseEvent*)
{
	emit channelDatabaseCloseSignals();
}