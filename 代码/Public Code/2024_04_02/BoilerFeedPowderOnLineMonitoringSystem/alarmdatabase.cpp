#include "alarmdatabase.h"

AlarmDatabase::AlarmDatabase(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::AlarmDatabaseClass())
{
	ui->setupUi(this);
	connect(ui->quit_pushButton, &QPushButton::clicked, [=]() {
		emit fromAlarmDatabaseToMainScreenSignals();
		});
}

AlarmDatabase::~AlarmDatabase()
{
	delete ui;
}
