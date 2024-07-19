#include "PrimaryWindCutCircleDiagramView.h"
#include <qtimer.h>
PrimaryWindCutCircleDiagramView::PrimaryWindCutCircleDiagramView(QWidget* parent)
	: QWidget(parent)
{
	std::cout << "PrimaryWindCutCircleDiagramView()" << std::endl;
	QTimer* t = new QTimer(this);
	connect(t, &QTimer::timeout, [=]() {
		/*init();
		std::cout << "1" << std::endl;*/

		qreal ret1 = qrand();
		qreal ret2 = qrand();
		qreal ret3 = qrand();
		qreal ret4 = qrand();
		qreal ret5 = qrand();
		qreal ret6 = qrand();
		qreal ret7 = qrand();
		qreal ret8 = qrand();
		writeData(ret1, ret2, ret3, ret4, ret5, ret6, ret7, ret8);
		});
	t->start(1000);
}

PrimaryWindCutCircleDiagramView::~PrimaryWindCutCircleDiagramView()
{
	std::cout << "~PrimaryWindCutCircleDiagramView()" << std::endl;
}

void PrimaryWindCutCircleDiagramView::writeData(double velocityOne, double speedOne
	, double velocityTwo, double speedTwo
	, double velocityThree, double speedThree
	, double velocityFour, double speedFour)
{
	int width = this->width();   
	int height = this->height(); 

	double ratioOne = velocityOne / (velocityOne + speedOne);
	double ratioTwo = velocityTwo / (velocityTwo + speedTwo);
	double ratioThree = velocityThree / (velocityThree + speedThree);
	double ratioFour = velocityFour / (velocityFour + speedFour);

	_outlet_velocity_one_begin = { width,height };
	_outlet_velocity_one_end.first = (int)(2.0 * width / 3 + (1.0 - ratioOne) * width / 3.0);
	_outlet_velocity_one_end.second = (int)(2.0 * height / 3 + (1.0 - ratioOne) * height / 3.0);
	_wind_speed_one_begin = _outlet_velocity_one_end;
	_wind_speed_one_end = { 2 * width / 3, 2 * height / 3 };

	_outlet_velocity_two_begin = { 0, height };
	_outlet_velocity_two_end.first = (int)(ratioTwo * 1.0 * width / 3.0);
	_outlet_velocity_two_end.second = (int)(2.0 * height / 3 + (1 - ratioTwo) * 1.0 * height / 3);
	_wind_speed_two_begin = _outlet_velocity_two_end;
	_wind_speed_two_end = { width / 3, 2 * height / 3 };

	_outlet_velocity_three_begin = {0,0};
	_outlet_velocity_three_end.first = (int)(ratioThree * 1.0 * width / 3);
	_outlet_velocity_three_end.second = (int)(ratioThree * 1.0 * height / 3);
	_wind_speed_three_begin = _outlet_velocity_three_end;
	_wind_speed_three_end = { width / 3,height / 3 };

	_outlet_velocity_four_begin = { width ,0 };
	_outlet_velocity_four_end.first = (int)(2.0 * width / 3 + (1.0 - ratioFour) * width / 3.0);
	_outlet_velocity_four_end.second = (int)(ratioFour * 1.0 * height / 3);
	_wind_speed_four_begin = _outlet_velocity_four_end;
	_wind_speed_four_end = { 2 * width / 3, height / 3 };
	update();
}



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
	painterRectangle.drawRect(RECTANGULAR_LINE_WIDTH, RECTANGULAR_LINE_WIDTH, width - 2 * RECTANGULAR_LINE_WIDTH, height - 2 * RECTANGULAR_LINE_WIDTH);

	// 画圆的
	QPainter painterCircle(this);
	QPen penCircle;
	QBrush brushCircle(QColor(0, 255, 0));
	brushCircle.setStyle(Qt::Dense1Pattern);
	painterCircle.setBrush(brushCircle);
	painterCircle.setPen(penCircle);
	penCircle.setWidth(WIDTH_OF_A_CIRCLE);

	painterCircle.drawEllipse((width - DIAMETER) / 2, (height - DIAMETER) / 2, DIAMETER, DIAMETER);

	//设置斜线

	QPainter painterBiasOne(this);
	QPen penBiasOne;
	penBiasOne.setWidth(STRAIGHT_LINE_WIDTH);
	penBiasOne.setColor(QColor(255, 0, 0));  // 红色
	painterBiasOne.setPen(penBiasOne);
	// 右下1号
	painterBiasOne.drawLine(_outlet_velocity_one_begin.first, _outlet_velocity_one_begin.second, _outlet_velocity_one_end.first, _outlet_velocity_one_end.second);

	painterBiasOne.drawLine(_outlet_velocity_two_begin.first, _outlet_velocity_two_begin.second, _outlet_velocity_two_end.first, _outlet_velocity_two_end.second);

	painterBiasOne.drawLine(_outlet_velocity_three_begin.first, _outlet_velocity_three_begin.second, _outlet_velocity_three_end.first, _outlet_velocity_three_end.second);

	painterBiasOne.drawLine(_outlet_velocity_four_begin.first, _outlet_velocity_four_begin.second, _outlet_velocity_four_end.first, _outlet_velocity_four_end.second);

	QPainter painterBiasTwo(this);
	QPen penBiasTwo;
	penBiasTwo.setWidth(STRAIGHT_LINE_WIDTH);
	penBiasTwo.setColor(QColor(0, 255, 0));  // 蓝色
	painterBiasTwo.setPen(penBiasTwo);
	painterBiasTwo.drawLine(_wind_speed_one_begin.first, _wind_speed_one_begin.second, _wind_speed_one_end.first, _wind_speed_one_end.second);
	painterBiasTwo.drawLine(_wind_speed_two_begin.first, _wind_speed_two_begin.second, _wind_speed_two_end.first, _wind_speed_two_end.second);
	painterBiasTwo.drawLine(_wind_speed_three_begin.first, _wind_speed_three_begin.second, _wind_speed_three_end.first, _wind_speed_three_end.second);
	painterBiasTwo.drawLine(_wind_speed_four_begin.first, _wind_speed_four_begin.second, _wind_speed_four_end.first, _wind_speed_four_end.second);
}