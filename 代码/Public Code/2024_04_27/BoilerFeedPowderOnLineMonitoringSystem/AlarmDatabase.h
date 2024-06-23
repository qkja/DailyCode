#pragma once

#include <QWidget>
#include "ui_AlarmDatabase.h"
#include <iostream>
#include "AlertData.h"
#include <QScrollBar>
#include <qtimer.h>
#include <iostream>
#include "ResultData.h"
#include <string>

#define NUMBER_OF_TOTAL_PAGES 100
#define ROW 10
#define COL 5

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
	AlarmDatabase(QWidget* parent = nullptr, ResultData* result_data = nullptr);
	~AlarmDatabase();
	void init();
signals:
	void alarmDatabaseCloseSignals();
	void fromAlarmDatabaseToMainScreenSignals();
private:
	void closeEvent(QCloseEvent*);
	void setTableWidget(); // 设置表格
	void writeData(const struct AlertData&);
	void showView(int);
private:
	Ui::AlarmDatabaseClass* ui;
	ResultData* _result_data;  // 派发数据
	int _current_page_count;
	int _number_of_total_pages;
	std::vector<struct AlertData> _v;
};
