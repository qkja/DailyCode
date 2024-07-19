#include "channeldatabase.h"

ChannelDatabase::ChannelDatabase(QWidget* parent)
	: QWidget(parent), ui(new Ui::ChannelDatabaseClass())
{
	ui->setupUi(this);
	connect(ui->quit_pushButton, &QPushButton::clicked, [=]()
		{ emit fromChannelDatabaseToMainScreenSignals(); });
}

ChannelDatabase::~ChannelDatabase()
{
	delete ui;
}