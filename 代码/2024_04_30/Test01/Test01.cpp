#include "Test01.h"
#include <QScrollBar>
#include <qtimer.h>
#include <iostream>
#include <string>
Test01::Test01(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::Test01Class())
	, _current_page_count(1)
	, _number_of_total_pages(1)

{
	ui->setupUi(this);

	connect(ui->pushButton_2, &QPushButton::clicked, [=]() {
		int ret = ui->label->text().toInt();
		ret = ret - 1;
		if (0 == ret)
			ret = ui->label_2->text().toInt();
		showView(ret);

		ui->label->setText(std::to_string(ret).c_str());

		std::cout << "shang"   << std::endl;
		_current_page_count = ret;
		});
	connect(ui->pushButton, &QPushButton::clicked, [=]() {
		int ret = ui->label->text().toInt();

		ret = ret % ui->label_2->text().toInt() + 1;
		showView(ret);

		ui->label->setText(std::to_string(ret).c_str());
		std::cout << "xia" << std::endl;
		_current_page_count = ret;
		});
	init();
	showView(_current_page_count);

	QTimer* t = new QTimer;
	/*int i = 0;
	for (int i = 0; i < 20; i++)
	{
		writeData(i);
	}*/
	connect(t, &QTimer::timeout, [=]() {
		static int i = 0;

		writeData(i);
		++i;
		std::cout << "q: " <<i<< std::endl;
		});

	t->start(5000);
}

Test01::~Test01()
{
	delete ui;
}

void Test01::init()
{
	createDataTable(); // 创建数据表
	ui->label->setText(std::to_string(_current_page_count).c_str());
	ui->label_2->setText(std::to_string(_number_of_total_pages).c_str());
}

void Test01::writeData(int data)
{
	if (_v.size() >= ui->tableWidget->rowCount())
	{
		_v.erase(_v.begin());
		_v.push_back(data);
		for (int i = 0; i < _v.size(); ++i)
		{
			ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(_v[i])));
		}
		ui->tableWidget->update();
	}
	else
	{
		_v.push_back(data);
		ui->tableWidget->setItem(_v.size() - 1, 0, new QTableWidgetItem(QString::number(_v.back())));
	}

	_number_of_total_pages = _v.size() / 5;
	if (_v.size() % 5 != 0)
		_number_of_total_pages = _number_of_total_pages + 1;

	ui->label->setText(std::to_string(_current_page_count).c_str());
	ui->label_2->setText(std::to_string(_number_of_total_pages).c_str());
	showView(_current_page_count);
}

void Test01::createDataTable()
{
	// 设置 2列
	// 设置行数, 共100行
	ui->tableWidget->resizeRowsToContents();//调整行内容大小
	ui->tableWidget->setColumnCount(1);//设置列数
	ui->tableWidget->setRowCount(20);//设置行数
	ui->tableWidget->horizontalHeader()->setDefaultSectionSize(200);//标题头的大小
	ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);//横向先自适应宽度
	ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);//然后设置要根据内容使用宽度的列
	//设置标题头的文字
	QStringList header;
	header << tr("编号");
	ui->tableWidget->setHorizontalHeaderLabels(header);
	ui->tableWidget->verticalHeader()->setVisible(false); //设置行号列,true为显示
	ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection); //可多选（Ctrl、Shift、 Ctrl+A都可以）
	ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //设置选择行为时每次选择一行
	ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑

	//设置水平、垂直滚动条样式
	ui->tableWidget->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:10px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");
	ui->tableWidget->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width: 10px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");

	ui->tableWidget->clearContents();//清除表格数据区的所有内容，但是不清除表头
}

void Test01::showView(int page)
{
	int start = 5 * (page - 1);
	int end = start + 5;
	if (end > _v.size())
		end = _v.size();
	for (int i = 0; i < ui->tableWidget->rowCount(); ++i)
	{
		if (i >= start && i < end)
		{
			ui->tableWidget->setRowHidden(i, false);
		}
		else
		{
			ui->tableWidget->setRowHidden(i, true);
		}
	}
}