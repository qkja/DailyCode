#include "BackrestCanal.h"

BackrestCanal::BackrestCanal(QWidget* parent, Configure* configure)
	: QWidget(parent)
	, ui(new Ui::BackrestCanalClass())
	, _configure(configure)
{
	std::cout << "BackrestCanal()" << std::endl;
	ui->setupUi(this);
	init();
}
BackrestCanal::~BackrestCanal()
{
	std::cout << "~BackrestCanal()" << std::endl;
	delete ui;
}

void BackrestCanal::init()
{
	this->setWindowTitle("背靠管系数修正");
	connect(_configure, &Configure::setBackrestCanalSignals, [=](const std::vector<std::string>& data) {
		ui->_a1->setText(data[0].c_str());
		ui->_a2->setText(data[1].c_str());
		ui->_a3->setText(data[2].c_str());
		ui->_a4->setText(data[3].c_str());
		ui->_b1->setText(data[4].c_str());
		ui->_b2->setText(data[5].c_str());
		ui->_b3->setText(data[6].c_str());
		ui->_b4->setText(data[7].c_str());
		ui->_c1->setText(data[8].c_str());
		ui->_c2->setText(data[9].c_str());
		ui->_c3->setText(data[10].c_str());
		ui->_c4->setText(data[11].c_str());
		ui->_d1->setText(data[12].c_str());
		ui->_d2->setText(data[13].c_str());
		ui->_d3->setText(data[14].c_str());
		ui->_d4->setText(data[15].c_str());
		ui->_e1->setText(data[16].c_str());
		ui->_e2->setText(data[17].c_str());
		ui->_e3->setText(data[18].c_str());
		ui->_e4->setText(data[19].c_str());
		ui->_f1->setText(data[20].c_str());
		ui->_f2->setText(data[21].c_str());
		ui->_f3->setText(data[22].c_str());
		ui->_f4->setText(data[23].c_str());
		setReadOnly(true);
		});

	connect(ui->save_pushButton, &QPushButton::clicked, [=]() {
		std::string a1 = ui->_a1->text().toStdString();
		std::string a2 = ui->_a2->text().toStdString();
		std::string a3 = ui->_a3->text().toStdString();
		std::string a4 = ui->_a4->text().toStdString();
		std::string b1 = ui->_b1->text().toStdString();
		std::string b2 = ui->_b2->text().toStdString();
		std::string b3 = ui->_b3->text().toStdString();
		std::string b4 = ui->_b4->text().toStdString();
		std::string c1 = ui->_c1->text().toStdString();
		std::string c2 = ui->_c2->text().toStdString();
		std::string c3 = ui->_c3->text().toStdString();
		std::string c4 = ui->_c4->text().toStdString();
		std::string d1 = ui->_d1->text().toStdString();
		std::string d2 = ui->_d2->text().toStdString();
		std::string d3 = ui->_d3->text().toStdString();
		std::string d4 = ui->_d4->text().toStdString();
		std::string e1 = ui->_e1->text().toStdString();
		std::string e2 = ui->_e2->text().toStdString();
		std::string e3 = ui->_e3->text().toStdString();
		std::string e4 = ui->_e4->text().toStdString();
		std::string f1 = ui->_f1->text().toStdString();
		std::string f2 = ui->_f2->text().toStdString();
		std::string f3 = ui->_f3->text().toStdString();
		std::string f4 = ui->_f4->text().toStdString();

		std::vector<std::string> v;
		v.push_back(a1);
		v.push_back(a2);
		v.push_back(a3);
		v.push_back(a4);
		v.push_back(b1);
		v.push_back(b2);
		v.push_back(b3);
		v.push_back(b4);
		v.push_back(c1);
		v.push_back(c2);
		v.push_back(c3);
		v.push_back(c4);
		v.push_back(d1);
		v.push_back(d2);
		v.push_back(d3);
		v.push_back(d4);
		v.push_back(e1);
		v.push_back(e2);
		v.push_back(e3);
		v.push_back(e4);
		v.push_back(f1);
		v.push_back(f2);
		v.push_back(f3);
		v.push_back(f4);
		_configure->alterBackrest(v);
		emit fromBackrestCanalToMainScreenSignals();
		});
	connect(ui->modify_pushButton, &QPushButton::clicked, [=]() {
		setReadOnly(false);
		});

	connect(ui->quit_pushButton, &QPushButton::clicked, [=]()
		{ emit fromBackrestCanalToMainScreenSignals(); });
}

void BackrestCanal::closeEvent(QCloseEvent*)
{
	emit backrestCanalCloseSignals();
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