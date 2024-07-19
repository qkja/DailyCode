#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test01.h"
#include <iostream>
#include <QWidget>
#include <QWidget>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/qlineseries.h>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/qvalueaxis.h>
QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class Test01Class; };
QT_END_NAMESPACE

class Test01 : public QMainWindow
{
    Q_OBJECT

public:
    Test01(QWidget *parent = nullptr);
    ~Test01();

private:
    Ui::Test01Class *ui;
};
