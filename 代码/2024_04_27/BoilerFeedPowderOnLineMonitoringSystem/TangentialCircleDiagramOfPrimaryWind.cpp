#include "TangentialCircleDiagramOfPrimaryWind.h"

TangentialCircleDiagramOfPrimaryWind::TangentialCircleDiagramOfPrimaryWind(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::TangentialCircleDiagramOfPrimaryWindClass())
	, _time(new QTimer(this))
{
	ui->setupUi(this);
	init();
	std::cout << "TangentialCircleDiagramOfPrimaryWind()" << std::endl;
}

TangentialCircleDiagramOfPrimaryWind::~TangentialCircleDiagramOfPrimaryWind()
{
	std::cout << "~TangentialCircleDiagramOfPrimaryWind()" << std::endl;

	delete ui;
}

void TangentialCircleDiagramOfPrimaryWind::init()
{
	this->setWindowTitle("Ò»´Î·çÇÐÔ²Í¼");
	connect(_time, &QTimer::timeout, [=]() {
		QDateTime currentDateTime = QDateTime::currentDateTime();
		QString dateTimeString = currentDateTime.toString("hh:mm:ss    yyyy-MM-dd");
		ui->label_date->setText(dateTimeString);
		});
	_time->start(1000);

	QTimer* t = new QTimer(this);
	connect(t, &QTimer::timeout, [=]() {
		std::cout << "1" << std::endl;

		qreal ret1 = qrand();
		qreal ret2 = qrand();
		qreal ret3 = qrand();
		qreal ret4 = qrand();
		qreal ret5 = qrand();
		qreal ret6 = qrand();
		qreal ret7 = qrand();
		qreal ret8 = qrand();
		ui->widget_a->writeData(ret1, ret2, ret3, ret4, ret5, ret6, ret7, ret8);
		ui->widget_b->writeData(ret1, ret2, ret3, ret4, ret5, ret6, ret7, ret8);
		ui->widget_c->writeData(ret1, ret2, ret3, ret4, ret5, ret6, ret7, ret8);
		ui->widget_d->writeData(ret1, ret2, ret3, ret4, ret5, ret6, ret7, ret8);
		ui->widget_e->writeData(ret1, ret2, ret3, ret4, ret5, ret6, ret7, ret8);
		ui->widget_f->writeData(ret1, ret2, ret3, ret4, ret5, ret6, ret7, ret8);
		});
	t->start(1000);
}

void TangentialCircleDiagramOfPrimaryWind::closeEvent(QCloseEvent*)
{
	emit tangentialCircleDiagramOfPrimaryWindCloseSignals();
}