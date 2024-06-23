#pragma once

#include <QMainWindow>
#include "ui_AlarmDatabase.h"
#include "AlertData.h"
#include <QScrollBar>
#include <qtimer.h>
#include <iostream>
#include <string>

#define NUMBER_OF_TOTAL_PAGES 2
#define ROW 5
#define COL 5
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// 该指令仅支持VS环境
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class AlarmDatabaseClass; };
QT_END_NAMESPACE

class AlarmDatabase : public QMainWindow
{
	Q_OBJECT

public:
	AlarmDatabase(QWidget *parent = nullptr);
	~AlarmDatabase();
	void init();  // 初始化
private:
	void setTableWidget(); // 设置表格
	void writeData(const AlertData&);

	void showView(int);
private:
	Ui::AlarmDatabaseClass *ui;
	int _current_page_count;
	int _number_of_total_pages;
	std::vector<AlertData> _v;
};
