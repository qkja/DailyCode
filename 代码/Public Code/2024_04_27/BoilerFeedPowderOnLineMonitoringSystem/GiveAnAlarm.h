#pragma once

#include <QWidget>
#include "ui_GiveAnAlarm.h"
#include <iostream>
#include "Configure.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// 该指令仅支持VS环境
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class GiveAnAlarmClass; };
QT_END_NAMESPACE

class GiveAnAlarm : public QWidget
{
	Q_OBJECT

public:
	GiveAnAlarm(QWidget* parent = nullptr, Configure* configure = nullptr);
	~GiveAnAlarm();
	void init();
signals:
	void giveAnAlarmCloseSignals();
	void fromGiveAnAlarmToMainScreenSignals();
private:
	void closeEvent(QCloseEvent*);
	int strfromDoubleToInt(const std::string&);  // 字符串转整数
	std::string intToStr(int);                   // 整数转字符串
private:
	Ui::GiveAnAlarmClass* ui;
	Configure* _configure;
};
