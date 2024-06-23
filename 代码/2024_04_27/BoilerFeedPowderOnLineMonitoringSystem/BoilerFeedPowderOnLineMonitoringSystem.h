#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BoilerFeedPowderOnLineMonitoringSystem.h"
#include "Configure.h"
#include "WelcomeScreen.h"
#include <iostream>
#include <MyThread.h>
#include "GiveAnAlarm.h"
#include "AlertData.h"
#include "MyTime.h"
#include "Spout.h"
#include "BackrestCanal.h"
#include "WordOfCommand.h"
#include "RodTypeWindPowderDiagram.h"
#include "TangentialCircleDiagramOfPrimaryWind.h"
#include "TrendChart.h"
#include "HistoricalTrendChart.h"
#include "AlarmDatabase.h"
#include "ChannelDatabase.h"
#include "VerifyPassword.h"
#include "ResultData.h"
#include "ChannelData.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// 该指令仅支持VS环境
#endif

/*
* 这是系统的主界面,所有的功能都在这里
* 可以通过点击菜单栏的选项进行相应的选择
*/

QT_BEGIN_NAMESPACE
namespace Ui { class BoilerFeedPowderOnLineMonitoringSystemClass; };
QT_END_NAMESPACE

class BoilerFeedPowderOnLineMonitoringSystem : public QMainWindow
{
	Q_OBJECT

public:
	BoilerFeedPowderOnLineMonitoringSystem(QWidget* parent = nullptr);
	~BoilerFeedPowderOnLineMonitoringSystem();

	void init(); // 进行所有功能的初始化
protected:
	void closeEvent(QCloseEvent*) override; //
private:
	void initThread();
	void initSystemSetting();
	void initWelcomeScreen(); // 初始化欢迎界面
	void initGiveAnAlarm();
	void initMyTime();
	void initSpout();
	void initBackrestCanal();
	void initWordOfCommand();
	void initQuit();

	void initStatusView();
	void initRodTypeWindPowderDiagram();
	void initTangentialCircleDiagramOfPrimaryWind();
	void initTrendChart();
	void initHistoricalTrendChart();

	void initDataProcessing();
	void initAlarmDatabase();
	void initChannelDatabase();

	void initAssist();

	void startThread();
private:
	Ui::BoilerFeedPowderOnLineMonitoringSystemClass* ui;
	ResultData _result_data;  // 解析的数据,由子线程发送到这里
	MyThread _my_thread;	  // 线程
	Configure* _configure;	  // 配置信息

	WelcomeScreen* _welcome_screen;		  // 欢迎界面
	GiveAnAlarm* _give_an_alarm;	      // 设定报警限
	MyTime* _my_time;	                  // 设定时间
	Spout* _spout;						  // 修改喷口面积
	BackrestCanal* _backrest_canal;		  // 修改靠背管系数
	WordOfCommand* _word_of_command;	  // 修改口令
	VerifyPassword* _verify_password;	  // 密码验证

	RodTypeWindPowderDiagram* _rod_type_wind_powder_diagram;	                      // 棒型风粉图
	TangentialCircleDiagramOfPrimaryWind* _tangential_circle_diagram_of_primary_wind; // 一次风切圆图
	TrendChart* _trend_chart;                                                         // 趋势图
	HistoricalTrendChart* _historical_trend_chart;                                    // 历史趋势图

	AlarmDatabase* _alarm_database;													  // 报警数据
	ChannelDatabase* _channel_database;												  // 通道数据
};
