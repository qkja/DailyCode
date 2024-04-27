#pragma once

#include "assist.h"
#include "configure.h"
#include "dataprocessing.h"
#include "mythread.h"
#include "resultdata.h"
#include "statusview.h"
#include "systemsetting.h"
#include "Task.hpp"
#include "ui_boilerfeedpowderonlinemonitoringsystem.h"
#include "verifypassword.h"
#include "welcomescreen.h"
#include <iostream>
#include <QtWidgets/QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui
{
	class BoilerFeedPowderOnLineMonitoringSystemClass;
};
QT_END_NAMESPACE

class BoilerFeedPowderOnLineMonitoringSystem : public QMainWindow
{
	Q_OBJECT

public:
	BoilerFeedPowderOnLineMonitoringSystem(QWidget* parent = nullptr);
	~BoilerFeedPowderOnLineMonitoringSystem();
	void init();
private:
	void SystemSettingConnect();   // 系统设置的信号与槽
	void StatusViewConnect();      // 状态查看的信号与槽
	void DataProcessingConnect();  // 数据处理的信号与槽
	void AssistConnect();          // 帮助的信号与槽
	void quitThreadConnect();      // 退出计算线程的信号与槽
	void toMainScreenConnect();    // 返回主主页面的信号与槽
	void receiveDataConnect();     // 接受数据的信号与槽
	void closeEventConnect();      // 重写退出的信号与槽
protected:
	void closeEvent(QCloseEvent*) override;

signals:
	void quitSignals();
	void stopThread();
private:
	Ui::BoilerFeedPowderOnLineMonitoringSystemClass* ui;
	MyThread _my_thread;              // 线程
	ResultData _result_data;          // 解析的数据
	Configure* _configure;            // 配置信息
	WelcomeScreen* _welcome_screen;   // 欢迎界面
	SystemSetting* _system_setting;   // 系统设置
	StatusView* _status_view;         // 状态查看
	DataProcessing* _data_processing; // 数据处理
	Assist* _assist;                  // 帮助
	VerifyPassword* _verify_password; // 密码
};
