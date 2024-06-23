#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test03.h"
#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QtCharts>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtConcurrent/QtConcurrent>
#include <QThread>
QT_CHARTS_USE_NAMESPACE
QT_BEGIN_NAMESPACE
namespace Ui { class Test03Class; };
QT_END_NAMESPACE

class Test03 : public QMainWindow
{
    Q_OBJECT

public:
    Test03(QWidget *parent = nullptr);
    ~Test03();
    void onChartBuilt(QVector<double> x, QVector<double> y);
    void buildChartAsync();
private:
    Ui::Test03Class *ui;
    QChartView* m_chartView;
};
