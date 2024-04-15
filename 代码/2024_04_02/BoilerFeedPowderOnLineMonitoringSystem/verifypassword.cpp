#include "verifypassword.h"
#include "qdebug.h"
VerifyPassword::VerifyPassword(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::VerifyPasswordClass())
{
	qDebug() << "VerifyPassword()";
	ui->setupUi(this);
	this->setWindowTitle("ÑéÖ¤¿ÚÁî");
	connect(ui->identify_pushButton, &QPushButton::clicked, [=]() {
		emit fromVerifyPasswordSignalsIsTrue();
		});
	connect(ui->cancel_pushButton, &QPushButton::clicked, [=]() {
		emit fromVerifyPasswordSignalsIsFalse();
		});

}

VerifyPassword::~VerifyPassword()
{
	qDebug() << "~VerifyPassword()";
	delete ui;
}

void VerifyPassword::closeEvent(QCloseEvent*)
{
	emit ExitWin();
}