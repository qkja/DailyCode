#pragma once

#include <QMainWindow>
#include "ui_mainscreen.h"
#include "systemsetting.h"
#include "verifypassword.h"
#include "assist.h"
#include "dataprocessing.h"
#include "statusview.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
QT_BEGIN_NAMESPACE
namespace Ui { class MainScreenClass; };
QT_END_NAMESPACE

class MainScreen : public QMainWindow
{
	Q_OBJECT

public:
	MainScreen(QWidget *parent = nullptr);
	~MainScreen();
signals:
	void quitSignals();

private:
	void SystemSettingConnect();
	void StatusViewConnect();
	void DataProcessingConnect();
	void AssistConnect();
private:
	Ui::MainScreenClass *ui;
	SystemSetting* _system_setting;    // ϵͳ����
	StatusView* _status_view;          // ״̬�鿴
	DataProcessing* _data_processing;  // ���ݴ���
	Assist* _assist;                   // ����
	VerifyPassword* _verify_password;
};
