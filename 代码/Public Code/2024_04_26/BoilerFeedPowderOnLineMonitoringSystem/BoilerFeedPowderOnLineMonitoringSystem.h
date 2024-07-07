#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BoilerFeedPowderOnLineMonitoringSystem.h"
#include "WelcomeScreen.h"
#include <iostream>
#include "GiveAnAlarm.h"
#include "Configure.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
QT_BEGIN_NAMESPACE
namespace Ui { class BoilerFeedPowderOnLineMonitoringSystemClass; };
QT_END_NAMESPACE

class BoilerFeedPowderOnLineMonitoringSystem : public QMainWindow
{
    Q_OBJECT

public:
    BoilerFeedPowderOnLineMonitoringSystem(QWidget *parent = nullptr);
    ~BoilerFeedPowderOnLineMonitoringSystem();
public:
    void init();
    void SystemSettingConnect();   // 系统设置的信号与槽

private:
    Ui::BoilerFeedPowderOnLineMonitoringSystemClass *ui;
    WelcomeScreen* _welcome_screen;   // 欢迎界面
    Configure* _configure;            // 配置信息

    GiveAnAlarm* _give_an_alarm;	 //   设定报警限
};
