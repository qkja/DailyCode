#pragma once

#include <QWidget>
#include "ui_AlarmDatabase.h"
#include <iostream>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// 该指令仅支持VS环境
#endif
QT_BEGIN_NAMESPACE
namespace Ui { class AlarmDatabaseClass; };
QT_END_NAMESPACE

class AlarmDatabase : public QWidget
{
	Q_OBJECT

public:
	AlarmDatabase(QWidget* parent = nullptr);
	~AlarmDatabase();
	void init();
signals:
	void alarmDatabaseCloseSignals();
	void fromAlarmDatabaseToMainScreenSignals();
private:
	void closeEvent(QCloseEvent*);
private:
	Ui::AlarmDatabaseClass* ui;
};
