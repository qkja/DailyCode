#include "backrestcanal.h"
#include <qdebug.h>
BackrestCanal::BackrestCanal(QWidget *parent)
	: QWidget(parent), ui(new Ui::BackrestCanalClass())
{
	qDebug() << "BackrestCanal()";
	ui->setupUi(this);
	this->setWindowTitle("你好");
	connect(ui->modify_pushButton, &QPushButton::clicked, [=]()
			{ emit fromBackrestCanalToMainScreenSignals(); });

	connect(ui->quit_pushButton, &QPushButton::clicked, [=]()
			{ emit fromBackrestCanalToMainScreenSignals(); });
}

BackrestCanal::~BackrestCanal()
{
	qDebug() << "~BackrestCanal()";
	delete ui;
}
