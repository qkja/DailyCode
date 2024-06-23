#pragma once

#include <QWidget>
#include <iostream>
#include <qpainter.h>

#define RECTANGULAR_LINE_WIDTH 5  // �����߶ο��
#define WIDTH_OF_A_CIRCLE 5       // Բ���߶ο��
#define DIAMETER 50               // Բ��ֱ��
#define STRAIGHT_LINE_WIDTH 5     // б�ߵĿ��
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
	std::pair<int, int> _outlet_velocity_one_begin;  // Ũ��1�����
	std::pair<int, int> _outlet_velocity_one_end;    // Ũ��1���յ�
	std::pair<int, int>	_wind_speed_one_begin;  //   ���ٵ����
	std::pair<int, int>	_wind_speed_one_end;     //  ���ٵ��յ�
	
	std::pair<int, int> _outlet_velocity_two_begin;  // Ũ��1�����
	std::pair<int, int> _outlet_velocity_two_end;    // Ũ��1���յ�
	std::pair<int, int>	_wind_speed_two_begin;  //   ���ٵ����
	std::pair<int, int>	_wind_speed_two_end;     //  ���ٵ��յ�


	std::pair<int, int> _outlet_velocity_three_begin;  // Ũ��1�����
	std::pair<int, int> _outlet_velocity_three_end;    // Ũ��1���յ�
	std::pair<int, int>	_wind_speed_three_begin;  //   ���ٵ����
	std::pair<int, int>	_wind_speed_three_end;     //  ���ٵ��յ�

	std::pair<int, int> _outlet_velocity_four_begin;  // Ũ��1�����
	std::pair<int, int> _outlet_velocity_four_end;    // Ũ��1���յ�
	std::pair<int, int>	_wind_speed_four_begin;  //   ���ٵ����
	std::pair<int, int>	_wind_speed_four_end;     //  ���ٵ��յ�

};
