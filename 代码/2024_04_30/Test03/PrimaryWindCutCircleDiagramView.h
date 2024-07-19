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
	void writeData(double, double, double, double, double, double, double, double);
protected:
	void paintEvent(QPaintEvent*) override;
private:
	std::pair<int, int> _outlet_velocity_one_begin;  // 浓度1的起点
	std::pair<int, int> _outlet_velocity_one_end;    // 浓度1的终点
	std::pair<int, int>	_wind_speed_one_begin;  //   流速的起点
	std::pair<int, int>	_wind_speed_one_end;     //  流速的终点
	
	std::pair<int, int> _outlet_velocity_two_begin;  // 浓度1的起点
	std::pair<int, int> _outlet_velocity_two_end;    // 浓度1的终点
	std::pair<int, int>	_wind_speed_two_begin;  //   流速的起点
	std::pair<int, int>	_wind_speed_two_end;     //  流速的终点


	std::pair<int, int> _outlet_velocity_three_begin;  // 浓度1的起点
	std::pair<int, int> _outlet_velocity_three_end;    // 浓度1的终点
	std::pair<int, int>	_wind_speed_three_begin;  //   流速的起点
	std::pair<int, int>	_wind_speed_three_end;     //  流速的终点

	std::pair<int, int> _outlet_velocity_four_begin;  // 浓度1的起点
	std::pair<int, int> _outlet_velocity_four_end;    // 浓度1的终点
	std::pair<int, int>	_wind_speed_four_begin;  //   流速的起点
	std::pair<int, int>	_wind_speed_four_end;     //  流速的终点

};
