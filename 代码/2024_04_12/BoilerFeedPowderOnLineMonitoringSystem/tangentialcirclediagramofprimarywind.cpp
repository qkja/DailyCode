#include "tangentialcirclediagramofprimarywind.h"

TangentialCircleDiagramOfPrimaryWind::TangentialCircleDiagramOfPrimaryWind(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::TangentialCircleDiagramOfPrimaryWindClass())
{
	ui->setupUi(this);

	std::cout << "TangentialCircleDiagramOfPrimaryWind()" << std::endl;

}

TangentialCircleDiagramOfPrimaryWind::~TangentialCircleDiagramOfPrimaryWind()
{
	std::cout << "~TangentialCircleDiagramOfPrimaryWind()" << std::endl;

	delete ui;
}
