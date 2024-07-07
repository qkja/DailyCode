#include "Spout.h"

Spout::Spout(QWidget* parent, Configure* configure)
	: QWidget(parent)
	, ui(new Ui::SpoutClass())
	, _configure(configure)
{
	ui->setupUi(this);
	init();
	std::cout << "Spout()" << std::endl;
}

Spout::~Spout()
{
	std::cout << "~Spout()" << std::endl;

	delete ui;
}

void Spout::init()
{
	this->setWindowTitle("设定喷口面积");
	connect(_configure, &Configure::setSpoutSignals, [=](const std::vector<std::string>& v) {
		ui->area_of_spout_in_layer_A->setText(v[0].c_str());
		ui->area_of_spout_in_layer_B->setText(v[1].c_str());
		ui->area_of_spout_in_layer_C->setText(v[2].c_str());
		ui->area_of_spout_in_layer_D->setText(v[3].c_str());
		ui->area_of_spout_in_layer_E->setText(v[4].c_str());
		ui->area_of_spout_in_layer_F->setText(v[5].c_str());
		ui->pipe_nozzle_area->setText(v[6].c_str());
		setReadOnly(true);
		});

	connect(ui->save_pushButton, &QPushButton::clicked, [=]() {
		std::string a = ui->area_of_spout_in_layer_A->text().toStdString();
		std::string b = ui->area_of_spout_in_layer_B->text().toStdString();
		std::string c = ui->area_of_spout_in_layer_C->text().toStdString();
		std::string d = ui->area_of_spout_in_layer_D->text().toStdString();
		std::string e = ui->area_of_spout_in_layer_E->text().toStdString();
		std::string f = ui->area_of_spout_in_layer_F->text().toStdString();
		std::string all = ui->pipe_nozzle_area->text().toStdString();
		std::vector<std::string> v;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		v.push_back(d);
		v.push_back(e);
		v.push_back(f);
		v.push_back(all);
		_configure->alterSpout(v);
		emit fromSpoutToMianScreenSignals();
		});
	connect(ui->modify_pushButton, &QPushButton::clicked, [=]() {
		setReadOnly(false); });
	connect(ui->quit_pushButton, &QPushButton::clicked, [=]() {
		emit fromSpoutToMianScreenSignals(); });
}

void Spout::closeEvent(QCloseEvent*)
{
	emit spoutCloseSignals();
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