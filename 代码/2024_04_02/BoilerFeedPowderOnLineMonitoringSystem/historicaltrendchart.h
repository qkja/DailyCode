#pragma once

#include <QMainWindow>
#include "ui_historicaltrendchart.h"

QT_BEGIN_NAMESPACE
namespace Ui { class HistoricalTrendChartClass; };
QT_END_NAMESPACE

class HistoricalTrendChart : public QMainWindow
{
	Q_OBJECT

public:
	HistoricalTrendChart(QWidget *parent = nullptr);
	~HistoricalTrendChart();

private:
	Ui::HistoricalTrendChartClass *ui;
};
