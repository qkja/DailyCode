#pragma once

#include <QWidget>
#include "ui_giveanalarm.h"
#include <iostream>
#include "mythread.h"
#include "configure.h"
#include <qlabel.h>
QT_BEGIN_NAMESPACE
namespace Ui
{
	class GiveAnAlarmClass;
};
QT_END_NAMESPACE

class GiveAnAlarm : public QWidget
{
	Q_OBJECT

public:
	GiveAnAlarm(QWidget* parent = nullptr, Configure* configure = nullptr);
	~GiveAnAlarm();
signals:
	void fromGiveAnAlarmToMainScreenToSaveSignals(std::string, std::string,
		std::string, std::string,
		std::string, std::string);
	void fromGiveAnAlarmToMainScreenSignals();
private:
	void myConnect(); // 信号与槽
	int strfromDoubleToInt(std::string&);  // 字符串转整数
	std::string intToStr(int);             // 整数转字符串
private:
	Configure* _configure;
	Ui::GiveAnAlarmClass* ui;
};
