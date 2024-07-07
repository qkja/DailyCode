#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test02.h"
#include <QtCharts>
#include <qtimer.h>
QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class Test02Class; };
QT_END_NAMESPACE

class Test02 : public QMainWindow
{
    Q_OBJECT

public:
    Test02(QWidget *parent = nullptr);
    ~Test02();
    void CreateChartFunc();
	void _updateData(std::vector<double>, int, int);

public slots:
	void handleTextChanged(const QString&);
private:
	QChart* _chart;
	QValueAxis* _x;
	QValueAxis* _y_wind;              // ����Y��
	QValueAxis* _y_concentration;     // Ũ��Y��
	QValueAxis* _y_temperature_1;     // �¶�1 Y��
	QValueAxis* _y_temperature_2;     // �¶�2 Y��
	QLineSeries* _line_wind;          // ��������
	QLineSeries* _line_concentration; // Ũ������
	QLineSeries* _line_temperature_1; // �¶�1����
	QLineSeries* _line_temperature_2; // �¶�2����
	QChartView* _chartView;           // ��ͼ
    //QChartView* chartview; //  QChartView����չʾͼ����ͼ�ࣩ
    //QChart* chart;         //  QChart����Ҫ����֯ͼ������ݣ��ĵ��ࣩ
    Ui::Test02Class *ui;
	int _left_wind  = 0;      // �������ķ�Χ
	int _right_wind =  0;     // �����Ҳ�ķ�Χ
	std::vector<double> v;
};
