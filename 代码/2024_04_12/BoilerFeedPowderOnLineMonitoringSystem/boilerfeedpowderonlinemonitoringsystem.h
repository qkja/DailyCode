#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_boilerfeedpowderonlinemonitoringsystem.h"
#include "welcomescreen.h"
#include "Task.hpp"
#include "mythread.h"
#include "systemsetting.h"
#include "verifypassword.h"
#include "assist.h"
#include "dataprocessing.h"
#include "statusview.h"
#include <iostream>
#include "configure.h"
#include "resultdata.h"
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
    BoilerFeedPowderOnLineMonitoringSystem(QWidget *parent = nullptr);
    ~BoilerFeedPowderOnLineMonitoringSystem();

private:
    void init();
    void myConnect();
    void SystemSettingConnect();
    void StatusViewConnect();
    void DataProcessingConnect();
    void AssistConnect();
    void closeEvent(QCloseEvent*);
signals:
    void quitSignals();
    void stopThread();
protected slots:
    void quit();                                                         // �˳�����
    void fromWelToMianScreen();                                          // �ӻ�ӭ�������
private:
    Ui::BoilerFeedPowderOnLineMonitoringSystemClass *ui;
    MyThread _myThread;               // 线程
    ResultData _result_data;          // 解析的数据
    Configure* _configure;            // 配置信息
    WelcomeScreen *_welcomeScreen;    // 欢饮界面
    SystemSetting *_system_setting;   // 系统设置
    StatusView* _status_view;         // 状态查看
    DataProcessing* _data_processing; // 数据处理
    Assist *_assist;                  // 帮助
    VerifyPassword *_verify_password; // 密码
};
