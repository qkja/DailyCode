#include "tangentialcirclediagramofprimarywind.h"

TangentialCircleDiagramOfPrimaryWind::TangentialCircleDiagramOfPrimaryWind(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::TangentialCircleDiagramOfPrimaryWindClass())
{
	ui->setupUi(this);
}

TangentialCircleDiagramOfPrimaryWind::~TangentialCircleDiagramOfPrimaryWind()
{
	delete ui;
}
