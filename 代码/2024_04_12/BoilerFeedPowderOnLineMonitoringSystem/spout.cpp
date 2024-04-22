#include "spout.h"
#include <qdebug.h>
Spout::Spout(QWidget *parent, Configure* configure)
	: QWidget(parent)
	, ui(new Ui::SpoutClass())
	,_configure(configure)
{
	ui->setupUi(this);
	qDebug() << "Spout()";
	this->setWindowTitle("�趨������");

	connect(_configure, &Configure::setSpoutSignals, [=](std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, std::string s6, std::string s7)
		{
			ui->area_of_spout_in_layer_A->setText(s1.c_str());
			ui->area_of_spout_in_layer_B->setText(s2.c_str());
			ui->area_of_spout_in_layer_C->setText(s3.c_str());
			ui->area_of_spout_in_layer_D->setText(s4.c_str());
			ui->area_of_spout_in_layer_E->setText(s5.c_str());
			ui->area_of_spout_in_layer_F->setText(s6.c_str());
			ui->pipe_nozzle_area->setText(s7.c_str());
			setReadOnly(true);
		});

	connect(ui->save_pushButton, &QPushButton::clicked, [=]()
			{ emit fromSpoutToMianScreenSignals(); });
	connect(ui->modify_pushButton, &QPushButton::clicked, [=]()
			{ emit fromSpoutToMianScreenSignals(); });
	connect(ui->quit_pushButton, &QPushButton::clicked, [=]()
			{ emit fromSpoutToMianScreenSignals(); });
}

Spout::~Spout()
{
	qDebug() << "~Spout()";
	delete ui;
}

void Spout::setReadOnly(bool flag)
{
	ui->area_of_spout_in_layer_A->setReadOnly(flag);
	ui->area_of_spout_in_layer_B->setReadOnly(flag);
	ui->area_of_spout_in_layer_C->setReadOnly(flag);
	ui->area_of_spout_in_layer_D->setReadOnly(flag);
	ui->area_of_spout_in_layer_E->setReadOnly(flag);
	ui->area_of_spout_in_layer_F->setReadOnly(flag);
	ui->pipe_nozzle_area->setReadOnly(flag);
}
