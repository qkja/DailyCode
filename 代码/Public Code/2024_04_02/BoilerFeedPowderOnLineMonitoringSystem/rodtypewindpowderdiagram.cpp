#include "rodtypewindpowderdiagram.h"

RodTypeWindPowderDiagram::RodTypeWindPowderDiagram(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::RodTypeWindPowderDiagramClass())
{
	ui->setupUi(this);
}

RodTypeWindPowderDiagram::~RodTypeWindPowderDiagram()
{
	delete ui;
}
