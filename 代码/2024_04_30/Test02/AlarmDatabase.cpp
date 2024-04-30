#include "AlarmDatabase.h"

AlarmDatabase::AlarmDatabase(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::AlarmDatabaseClass())
    , _current_page_count(1)
    , _number_of_total_pages(1)
{
	ui->setupUi(this);
    init();

    QTimer* t = new QTimer;

    connect(t, &QTimer::timeout, [=]() {

        AlertData data;
        static int i = 1;
        data._sensor_name = "测试" + std::to_string(i);
        data._alarm_type = "测试";
        data._initial_time_point = "测试";
        data._data = "测试";
        data._end_time_point = "测试";
        writeData(data);
        ++i;
        });

    t->start(1000);
}

AlarmDatabase::~AlarmDatabase()
{
	delete ui;
}

void AlarmDatabase::init()
{
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

void AlarmDatabase::setTableWidget()
{
    ui->tableWidget->resizeRowsToContents();//调整行内容大小
    ui->tableWidget->setColumnCount(COL);//设置列数
    ui->tableWidget->setRowCount(ROW * NUMBER_OF_TOTAL_PAGES);//设置行数
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(200);//标题头的大小
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);//横向先自适应宽度
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);//然后设置要根据内容使用宽度的列

    QStringList header;
    header << tr("传感器名字") << tr("出限类型") << tr("起始时间点") << tr("数据") << tr("结束时间点");
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

void AlarmDatabase::writeData(const AlertData& data)
{
    if (_v.size() == ROW * NUMBER_OF_TOTAL_PAGES)
    {
        _v.erase(_v.begin());
        _v.push_back(data);
        std::string _sensor_name; // 传感器名字

        for (int i = 0; i < _v.size(); ++i)
        {
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(_v[i]._sensor_name.c_str()));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(_v[i]._alarm_type.c_str()));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(_v[i]._initial_time_point.c_str()));
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(_v[i]._data.c_str()));
            ui->tableWidget->setItem(i, 4, new QTableWidgetItem(_v[i]._end_time_point.c_str()));
        }
    }
    else
    {
        _v.push_back(data);
        ui->tableWidget->setItem(_v.size() - 1, 0, new QTableWidgetItem(_v.back()._sensor_name.c_str()));
        ui->tableWidget->setItem(_v.size() - 1, 1, new QTableWidgetItem(_v.back()._alarm_type.c_str()));
        ui->tableWidget->setItem(_v.size() - 1, 2, new QTableWidgetItem(_v.back()._initial_time_point.c_str()));
        ui->tableWidget->setItem(_v.size() - 1, 3, new QTableWidgetItem(_v.back()._data.c_str()));
        ui->tableWidget->setItem(_v.size() - 1, 4, new QTableWidgetItem(_v.back()._end_time_point.c_str()));
    }
    ui->tableWidget->update();

    _number_of_total_pages = _v.size() / ROW;
    if (_v.size() % ROW != 0)
        _number_of_total_pages = _number_of_total_pages + 1;

    ui->label_cur->setText(std::to_string(_current_page_count).c_str());
    ui->label_total->setText(std::to_string(_number_of_total_pages).c_str());
    showView(_current_page_count);
}


void AlarmDatabase::showView(int page)
{
    int start = ROW * (page - 1);
    int end = start + ROW;
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
