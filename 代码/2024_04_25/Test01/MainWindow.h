#pragma once

#include <QMainWindow>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/qlineseries.h>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/qvalueaxis.h>
#include <QDebug>
#include "qtimer.h"
#include <qpushbutton.h>
#include <QtCharts/qdatetimeaxis.h>
#include <qdatetime.h>

QT_CHARTS_USE_NAMESPACE
class MainWindow  : public QMainWindow

{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();
	void button_slot();
	void button1_slot();
	void button2_slot();
	void timerEvent(QTimerEvent* event);
protected:
	void paintEvent(QPaintEvent* event);
private:
	QTimer* timer;
	QPushButton* button;
	QPushButton* button1;
	QPushButton* button2;
	QValueAxis* axisX;
	QValueAxis* axisY;
	QLineSeries* series;
	QChart* chart;
	QChartView* chartView;
	QDateTimeAxis* daxisX;
	QValueAxis* daxisY;
	QLineSeries* dseries;
	QChart* dchart;
	QChartView* dchartView;
};
