#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test01.h"
#include "Data.h"

#define NUMBER_OF_PAGES 3
#define COL 2  //一行的数据
#define ROW 10 
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// 该指令仅支持VS环境
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class Test01Class; };
QT_END_NAMESPACE

class Test01 : public QMainWindow
{
	Q_OBJECT

public:
	Test01(QWidget* parent = nullptr);
	~Test01();
	void init();  // 初始化
	void writeData(const Data&);  // 写数据
	void updateView(bool);  // 更新数据
private:
	void setTableWidget(); // 设置表格
	void showPageData(int);  // 显示一页的数据
	void setPage();  // 设置页数
	void showView(int page);
private:
	Ui::Test01Class* ui;
	int _curPage;      // 当前页                                        /* 当前页 */
	int _totalPage;    // 目前的总页数
	std::vector<Data> _v;
};

