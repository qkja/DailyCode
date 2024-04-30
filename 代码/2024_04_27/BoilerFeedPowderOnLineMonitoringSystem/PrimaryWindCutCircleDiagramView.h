#pragma once

#include <QWidget>
#include <iostream>
#include <qpainter.h>

#define RECTANGULAR_LINE_WIDTH 5  // 矩形线段宽度
#define WIDTH_OF_A_CIRCLE 5       // 圆的线段宽度
#define DIAMETER 50               // 圆的直径
#define STRAIGHT_LINE_WIDTH 5     // 斜线的宽度
class PrimaryWindCutCircleDiagramView : public QWidget
{
	Q_OBJECT

public:
	PrimaryWindCutCircleDiagramView(QWidget* parent);
	~PrimaryWindCutCircleDiagramView();
protected:
	void paintEvent(QPaintEvent*) override;
};
