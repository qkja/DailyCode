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
    void init();
    void startThread();
    void closeEvent(QCloseEvent *);

private:
    void SystemSettingConnect();
    void StatusViewConnect();
    void DataProcessingConnect();
    void AssistConnect();

signals:
    void quitSignals();
    void stopThread();
protected slots:
    void quit();                                                         // �˳�����
    void fromWelToMianScreen();                                          // �ӻ�ӭ�������
    void processData(Task);                                              // ��������
    void processConfigure(std::unordered_map<std::string, std::string>); // ����������Ϣ
private:
    Ui::BoilerFeedPowderOnLineMonitoringSystemClass *ui;
    WelcomeScreen *_welcomeScreen;

    SystemSetting *_system_setting;   // ϵͳ����
    StatusView *_status_view;         // ״̬�鿴
    DataProcessing *_data_processing; // ���ݴ���
    Assist *_assist;                  // ����
    VerifyPassword *_verify_password; // ������֤
    MyThread _myThread;
};
