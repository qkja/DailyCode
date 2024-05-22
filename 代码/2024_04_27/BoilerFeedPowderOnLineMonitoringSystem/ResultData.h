#pragma once

#include "Task.h"
#include <QWidget>
#include "ChannelData.h"
#include "AlertData.h"
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

class ResultData : public QWidget
{
	Q_OBJECT

public:
	ResultData(QWidget* parent = nullptr);
	~ResultData();
signals:
	// ���ͷ��ͼ����
	void barPatternOfWindPowderSignals(const std::vector<struct BarPatternOfWindPowder>&);
	// ����ͼ
	void tendencyChartDataSignals(const std::vector<struct TendencyChartData>&);
	void alarmDataSignals(const struct AlertData&);
	void channeDataSignals(const struct ChannelData&);
public slots:
	// ��������������ó���,�����ɷ�
	void distributeAllData(std::vector<struct Result>);
	void distributeAlarmData(std::vector<struct AlertData>);
	void distributeChannelData(std::vector<struct ChannelData>);
};
