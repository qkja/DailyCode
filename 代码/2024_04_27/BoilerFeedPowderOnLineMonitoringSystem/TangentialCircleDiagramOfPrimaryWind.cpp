#include "TangentialCircleDiagramOfPrimaryWind.h"

TangentialCircleDiagramOfPrimaryWind::TangentialCircleDiagramOfPrimaryWind(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::TangentialCircleDiagramOfPrimaryWindClass())
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
	this->setWindowTitle("“ª¥Œ∑Á«–‘≤Õº");
}

void TangentialCircleDiagramOfPrimaryWind::closeEvent(QCloseEvent*)
{
	emit tangentialCircleDiagramOfPrimaryWindCloseSignals();
}