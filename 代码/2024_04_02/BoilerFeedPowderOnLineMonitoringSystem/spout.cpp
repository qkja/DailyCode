#include "spout.h"
#include <qdebug.h>
Spout::Spout(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::SpoutClass())
{
	ui->setupUi(this);
	qDebug() << "Spout()";
	this->setWindowTitle("设定喷口面积");
	connect(ui->save_pushButton, &QPushButton::clicked, [=]() {
		emit fromSpoutToMianScreenSignals();
		});
	connect(ui->modify_pushButton, &QPushButton::clicked, [=]() {
		emit fromSpoutToMianScreenSignals();
		});
	connect(ui->quit_pushButton, &QPushButton::clicked, [=]() {
		emit fromSpoutToMianScreenSignals();
		});
}

Spout::~Spout()
{
	qDebug() << "~Spout()";
	delete ui;
}
