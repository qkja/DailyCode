#include "backrestcanal.h"
BackrestCanal::BackrestCanal(QWidget* parent, Configure* configure)
	: QWidget(parent)
	, ui(new Ui::BackrestCanalClass())
	, _configure(configure)
{
	qDebug() << "BackrestCanal()";
	ui->setupUi(this);
	init();
	
}

BackrestCanal::~BackrestCanal()
{
	qDebug() << "~BackrestCanal()";
	delete ui;
}

void BackrestCanal::init()
{
	updateData();
}

void BackrestCanal::updateData()
{
	connect(_configure, &Configure::setBackrestCanalSignals, [=](
		std::string a1, std::string a2, std::string a3, std::string a4
		, std::string b1, std::string b2, std::string b3, std::string b4
		, std::string c1, std::string c2, std::string c3, std::string c4
		, std::string d1, std::string d2, std::string d3, std::string d4
		, std::string e1, std::string e2, std::string e3, std::string e4
		, std::string f1, std::string f2, std::string f3, std::string f4) {
			ui->_a1->setText(a1.c_str());
			ui->_a2->setText(a2.c_str());
			ui->_a3->setText(a3.c_str());
			ui->_a4->setText(a4.c_str());
			ui->_b1->setText(b1.c_str());
			ui->_b2->setText(b2.c_str());
			ui->_b3->setText(b3.c_str());
			ui->_b4->setText(b4.c_str());
			ui->_c1->setText(c1.c_str());
			ui->_c2->setText(c2.c_str());
			ui->_c3->setText(c3.c_str());
			ui->_c4->setText(c4.c_str());
			ui->_d1->setText(d1.c_str());
			ui->_d2->setText(d2.c_str());
			ui->_d3->setText(d3.c_str());
			ui->_d4->setText(d4.c_str());
			ui->_e1->setText(e1.c_str());
			ui->_e2->setText(e2.c_str());
			ui->_e3->setText(e3.c_str());
			ui->_e4->setText(e4.c_str());
			ui->_f1->setText(f1.c_str());
			ui->_f2->setText(f2.c_str());
			ui->_f3->setText(f3.c_str());
			ui->_f4->setText(f4.c_str());
			setReadOnly(true);
		});

	connect(ui->save_pushButton, &QPushButton::clicked, [=]() {
		emit fromBackrestCanalToMainScreenToSaveSignals(
			ui->_a1->text().toStdString(), ui->_a2->text().toStdString(), ui->_a3->text().toStdString(), ui->_a4->text().toStdString(),
			ui->_b1->text().toStdString(), ui->_b2->text().toStdString(), ui->_b3->text().toStdString(), ui->_b4->text().toStdString(),
			ui->_c1->text().toStdString(), ui->_c2->text().toStdString(), ui->_c3->text().toStdString(), ui->_c4->text().toStdString(),
			ui->_d1->text().toStdString(), ui->_d2->text().toStdString(), ui->_d3->text().toStdString(), ui->_d4->text().toStdString(),
			ui->_e1->text().toStdString(), ui->_e2->text().toStdString(), ui->_e3->text().toStdString(), ui->_e4->text().toStdString(),
			ui->_f1->text().toStdString(), ui->_f2->text().toStdString(), ui->_f3->text().toStdString(), ui->_f4->text().toStdString()
		);
		});
	connect(ui->modify_pushButton, &QPushButton::clicked, [=]()
		{
			setReadOnly(false);
		});

	connect(ui->quit_pushButton, &QPushButton::clicked, [=]()
		{ emit fromBackrestCanalToMainScreenSignals(); });
}

void BackrestCanal::setReadOnly(bool flag)
{
	ui->_a1->setReadOnly(flag);
	ui->_a2->setReadOnly(flag);
	ui->_a3->setReadOnly(flag);
	ui->_a4->setReadOnly(flag);
	ui->_b1->setReadOnly(flag);
	ui->_b2->setReadOnly(flag);
	ui->_b3->setReadOnly(flag);
	ui->_b4->setReadOnly(flag);
	ui->_c1->setReadOnly(flag);
	ui->_c2->setReadOnly(flag);
	ui->_c3->setReadOnly(flag);
	ui->_c4->setReadOnly(flag);
	ui->_d1->setReadOnly(flag);
	ui->_d2->setReadOnly(flag);
	ui->_d3->setReadOnly(flag);
	ui->_d4->setReadOnly(flag);
	ui->_e1->setReadOnly(flag);
	ui->_e2->setReadOnly(flag);
	ui->_e3->setReadOnly(flag);
	ui->_e4->setReadOnly(flag);
}