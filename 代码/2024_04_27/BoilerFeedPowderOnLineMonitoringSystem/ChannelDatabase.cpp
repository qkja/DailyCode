#include "ChannelDatabase.h"

ChannelDatabase::ChannelDatabase(QWidget* parent, ResultData* result_data)
	: QWidget(parent)
	, ui(new Ui::ChannelDatabaseClass())
	, _result_data(result_data)
	, _current_page_count(1)
	, _number_of_total_pages(1)
{
	ui->setupUi(this);
	init();
	std::cout << "ChannelDatabase()" << std::endl;
	QTimer* t = new QTimer(this);

	connect(_result_data, &ResultData::channeDataSignals, [=](const struct ChannelData& data) {
		writeData(data);
		});
	/*connect(t, &QTimer::timeout, [=]() {
		std::cout << "1" << std::endl;
		ChannelData data;
		static int i = 1;
		data._name = "测试" + std::to_string(i);
		data._serial_number = "测试";
		data._slate_number = "测试";
		data._channel_number = "测试";
		data._type = "测试";
		data._range = "测试";
		data._measured_value = "测试";
		data._engineering_value = "测试";
		writeData(data);
		++i;
		});

	t->start(1000);*/
}

ChannelDatabase::~ChannelDatabase()
{
	std::cout << "~ChannelDatabase()" << std::endl;

	delete ui;
}

void ChannelDatabase::init()
{
	this->setWindowTitle("通道数据");
	connect(ui->quit_pushButton, &QPushButton::clicked, [=]()
		{ emit fromChannelDatabaseToMainScreenSignals(); });

	setTableWidget();
	ui->label_cur->setText(std::to_string(_current_page_count).c_str());
	ui->label_total->setText(std::to_string(_number_of_total_pages).c_str());
	connect(ui->pushButton_up, &QPushButton::clicked, [=]() {
		int cur = ui->label_cur->text().toInt();
		cur = cur - 1;
		if (0 == cur)
			cur = ui->label_total->text().toInt();
		showView(cur);

		ui->label_cur->setText(std::to_string(cur).c_str());
		std::cout << "shang" << std::endl;
		_current_page_count = cur;
		});
	connect(ui->pushButton_next, &QPushButton::clicked, [=]() {
		int cur = ui->label_cur->text().toInt();
		cur = cur % ui->label_total->text().toInt() + 1;
		showView(cur);
		ui->label_cur->setText(std::to_string(cur).c_str());
		std::cout << "xia" << std::endl;
		_current_page_count = cur;
		});
}

void ChannelDatabase::closeEvent(QCloseEvent*)
{
	emit channelDatabaseCloseSignals();
}

void ChannelDatabase::setTableWidget()
{
	ui->tableWidget->resizeRowsToContents();//调整行内容大小
	ui->tableWidget->setColumnCount(COL_CHANNEL);//设置列数
	ui->tableWidget->setRowCount(ROW_CHANNEL * NUMBER_OF_TOTAL_PAGES_CHANNEL);//设置行数
	ui->tableWidget->horizontalHeader()->setDefaultSectionSize(200);//标题头的大小
	ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);//横向先自适应宽度
	ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);//然后设置要根据内容使用宽度的列

	QStringList header;
	header << tr("序号") << tr("测点名称") << tr("测点编号") << tr("板号") << tr("通道号") << tr("类型") << tr("测点量程") << tr("实测值") << tr("工程值");
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

void ChannelDatabase::writeData(const struct ChannelData& data)
{
	if (_v.size() == ROW_CHANNEL * NUMBER_OF_TOTAL_PAGES_CHANNEL)
	{
		_v.erase(_v.begin());
		_v.push_back(data);

		for (int i = 0; i < _v.size(); ++i)
		{
			ui->tableWidget->setItem(i, 0, new QTableWidgetItem(std::to_string(i + 1).c_str()));
			ui->tableWidget->setItem(i, 1, new QTableWidgetItem(_v[i]._name.c_str()));
			ui->tableWidget->setItem(i, 2, new QTableWidgetItem(_v[i]._serial_number.c_str()));
			ui->tableWidget->setItem(i, 3, new QTableWidgetItem(_v[i]._slate_number.c_str()));
			ui->tableWidget->setItem(i, 4, new QTableWidgetItem(_v[i]._channel_number.c_str()));
			ui->tableWidget->setItem(i, 5, new QTableWidgetItem(_v[i]._type.c_str()));
			ui->tableWidget->setItem(i, 6, new QTableWidgetItem(_v[i]._range.c_str()));
			ui->tableWidget->setItem(i, 7, new QTableWidgetItem(_v[i]._measured_value.c_str()));
			ui->tableWidget->setItem(i, 8, new QTableWidgetItem(_v[i]._engineering_value.c_str()));
		}
	}
	else
	{
		_v.push_back(data);
		ui->tableWidget->setItem(_v.size() - 1, 0, new QTableWidgetItem(std::to_string(_v.size()).c_str()));
		ui->tableWidget->setItem(_v.size() - 1, 1, new QTableWidgetItem(_v.back()._name.c_str()));
		ui->tableWidget->setItem(_v.size() - 1, 2, new QTableWidgetItem(_v.back()._serial_number.c_str()));
		ui->tableWidget->setItem(_v.size() - 1, 3, new QTableWidgetItem(_v.back()._slate_number.c_str()));
		ui->tableWidget->setItem(_v.size() - 1, 4, new QTableWidgetItem(_v.back()._channel_number.c_str()));
		ui->tableWidget->setItem(_v.size() - 1, 5, new QTableWidgetItem(_v.back()._type.c_str()));
		ui->tableWidget->setItem(_v.size() - 1, 6, new QTableWidgetItem(_v.back()._range.c_str()));
		ui->tableWidget->setItem(_v.size() - 1, 7, new QTableWidgetItem(_v.back()._measured_value.c_str()));
		ui->tableWidget->setItem(_v.size() - 1, 8, new QTableWidgetItem(_v.back()._engineering_value.c_str()));
	}
	ui->tableWidget->update();
	_number_of_total_pages = _v.size() / ROW_CHANNEL;
	if (_v.size() % ROW_CHANNEL != 0)
		_number_of_total_pages = _number_of_total_pages + 1;

	ui->label_cur->setText(std::to_string(_current_page_count).c_str());
	ui->label_total->setText(std::to_string(_number_of_total_pages).c_str());
	showView(_current_page_count);
}

void ChannelDatabase::showView(int page)
{
	int start = ROW_CHANNEL * (page - 1);
	int end = start + ROW_CHANNEL;
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