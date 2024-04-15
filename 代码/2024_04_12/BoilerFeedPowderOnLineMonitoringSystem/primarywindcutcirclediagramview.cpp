#include "primarywindcutcirclediagramview.h"

PrimaryWindCutCircleDiagramView::PrimaryWindCutCircleDiagramView(QWidget *parent)
	: QWidget(parent)
{}

PrimaryWindCutCircleDiagramView::~PrimaryWindCutCircleDiagramView()
{}

void PrimaryWindCutCircleDiagramView::paintEvent(QPaintEvent* event)
{
	(void)event;
	int width = this->width();
	int height = this->height();
	// 画矩形的
	QPainter painterRectangle(this);  
	QPen penRectangle;
	penRectangle.setWidth(RECTANGULAR_LINE_WIDTH);
	painterRectangle.setPen(penRectangle);
	painterRectangle.drawRect(RECTANGULAR_LINE_WIDTH, RECTANGULAR_LINE_WIDTH,width-2* RECTANGULAR_LINE_WIDTH, height -2* RECTANGULAR_LINE_WIDTH);



	// 画圆的
	QPainter painterCircle(this);
	QPen penCircle;
	QBrush brushCircle(QColor(0,255,0));
	brushCircle.setStyle(Qt::Dense1Pattern);
	painterCircle.setBrush(brushCircle);
	painterCircle.setPen(penCircle);
	penCircle.setWidth(WIDTH_OF_A_CIRCLE);

	painterCircle.drawEllipse((width- DIAMETER) / 2, (height- DIAMETER) / 2, DIAMETER, DIAMETER);


	//设置斜线

	QPainter painterBias(this);
	QPen penBias;
	penBias.setWidth(STRAIGHT_LINE_WIDTH);
	penBias.setColor(QColor(0, 255, 0));
	painterBias.setPen(penBias);
	painterBias.drawLine(0,0, (1 * width) / 3, (1 * height) / 3); // 左上
	painterBias.drawLine(width, 0, (2 * width) / 3, (1 * height) / 3); // 右上
	painterBias.drawLine(0, height, (1 * width) / 3, (2 * height) / 3); // 左下
	painterBias.drawLine((2 * width) / 3, (2 * height) / 3, width, height); // 右下
}
