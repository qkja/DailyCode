#pragma once
#include "Task.hpp"
#include <QWidget>
// ���ͷ��ͼ����
struct BarPatternOfWindPowder
{

	double _wind_speed;     // ����
	double	_concentration; // Ũ��
	double _temperature;    // �¶�
};

struct TendencyChartData
{
	int    _category;       // ���
	double _wind_speed;     // ����
	double _concentration;  // Ũ��
	double _temperature_1;  // �¶�1
	double _temperature_2;  // �¶�2
};

class ResultData  : public QWidget
{
	Q_OBJECT

public:
	ResultData(QWidget *parent = nullptr);
	~ResultData();
signals:
	// ���ͷ��ͼ����
	void barPatternOfWindPowderSignals(std::vector<struct BarPatternOfWindPowder>);
	// ����ͼ
	void tendencyChartDataSignals(std::vector<struct TendencyChartData>);
public slots:
	void distributeData(Task);
};
