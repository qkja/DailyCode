#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test01.h"
#include "Data.h"

#define NUMBER_OF_PAGES 3
#define COL 2  //һ�е�����
#define ROW 10 
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// ��ָ���֧��VS����
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
	void init();  // ��ʼ��
	void writeData(const Data&);  // д����
	void updateView(bool);  // ��������
private:
	void setTableWidget(); // ���ñ��
	void showPageData(int);  // ��ʾһҳ������
	void setPage();  // ����ҳ��
	void showView(int page);
private:
	Ui::Test01Class* ui;
	int _curPage;      // ��ǰҳ                                        /* ��ǰҳ */
	int _totalPage;    // Ŀǰ����ҳ��
	std::vector<Data> _v;
};

