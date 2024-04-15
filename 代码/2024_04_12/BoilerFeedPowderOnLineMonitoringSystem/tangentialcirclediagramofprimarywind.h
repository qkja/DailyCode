#pragma once

#include <QMainWindow>
#include "ui_tangentialcirclediagramofprimarywind.h"
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui
{
	class TangentialCircleDiagramOfPrimaryWindClass;
};
QT_END_NAMESPACE

class TangentialCircleDiagramOfPrimaryWind : public QMainWindow
{
	Q_OBJECT

public:
	TangentialCircleDiagramOfPrimaryWind(QWidget *parent = nullptr);
	~TangentialCircleDiagramOfPrimaryWind();

private:
	Ui::TangentialCircleDiagramOfPrimaryWindClass *ui;
};
