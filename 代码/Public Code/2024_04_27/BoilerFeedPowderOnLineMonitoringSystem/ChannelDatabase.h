#pragma once

#include <QWidget>
#include "ui_ChannelDatabase.h"
#include <iostream>
#include <iostream>
#include "AlertData.h"
#include <QScrollBar>
#include <qtimer.h>
#include "ResultData.h"
#include <iostream>
#include <string>
#include "ChannelData.h"

#define NUMBER_OF_TOTAL_PAGES_CHANNEL 100
#define ROW_CHANNEL 10
#define COL_CHANNEL 9
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// 该指令仅支持VS环境
#endif
QT_BEGIN_NAMESPACE
namespace Ui { class ChannelDatabaseClass; };
QT_END_NAMESPACE

class ChannelDatabase : public QWidget
{
	Q_OBJECT

public:
	ChannelDatabase(QWidget* parent = nullptr, ResultData* result_data = nullptr);
	~ChannelDatabase();
	void init();
signals:
	void channelDatabaseCloseSignals();
	void fromChannelDatabaseToMainScreenSignals();
private:
	void closeEvent(QCloseEvent*);
	void setTableWidget(); // 设置表格
	void writeData(const struct ChannelData&);
	void showView(int);
private:
	ResultData* _result_data;  // 派发数据
	Ui::ChannelDatabaseClass* ui;
	int _current_page_count;
	int _number_of_total_pages;
	std::vector<struct ChannelData> _v;
};
