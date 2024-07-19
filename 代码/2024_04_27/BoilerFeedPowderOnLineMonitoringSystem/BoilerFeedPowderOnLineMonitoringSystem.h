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
#pragma execution_character_set("utf-8")// ��ָ���֧��VS����
#endif

/*
* ����ϵͳ��������,���еĹ��ܶ�������
* ����ͨ������˵�����ѡ�������Ӧ��ѡ��
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

	void init(); // �������й��ܵĳ�ʼ��
protected:
	void closeEvent(QCloseEvent*) override; //
private:
	void initThread();
	void initSystemSetting();
	void initWelcomeScreen(); // ��ʼ����ӭ����
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
	ResultData _result_data;  // ����������,�����̷߳��͵�����
	MyThread _my_thread;	  // �߳�
	Configure* _configure;	  // ������Ϣ

	WelcomeScreen* _welcome_screen;		  // ��ӭ����
	GiveAnAlarm* _give_an_alarm;	      // �趨������
	MyTime* _my_time;	                  // �趨ʱ��
	Spout* _spout;						  // �޸�������
	BackrestCanal* _backrest_canal;		  // �޸Ŀ�����ϵ��
	WordOfCommand* _word_of_command;	  // �޸Ŀ���
	VerifyPassword* _verify_password;	  // ������֤

	RodTypeWindPowderDiagram* _rod_type_wind_powder_diagram;	                      // ���ͷ��ͼ
	TangentialCircleDiagramOfPrimaryWind* _tangential_circle_diagram_of_primary_wind; // һ�η���Բͼ
	TrendChart* _trend_chart;                                                         // ����ͼ
	HistoricalTrendChart* _historical_trend_chart;                                    // ��ʷ����ͼ

	AlarmDatabase* _alarm_database;													  // ��������
	ChannelDatabase* _channel_database;												  // ͨ������
};
