#include "Test01.h"
#include <QScrollBar>
#include <qtimer.h>
#include <iostream>
#include <string>
Test01::Test01(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Test01Class())
    , _curPage(1)
    , _totalPage(1)
{
    ui->setupUi(this);
    init();

    QTimer* t = new QTimer;
    int i = 0;
    connect(t, &QTimer::timeout, [=]() {
        
        Data a;
        a._name = std::to_string(i);
        writeData(a);
        std::cout <<"q" <<std::endl;
        });

    t->start(1000);
}

Test01::~Test01()
{
    delete ui;
}

void Test01::init()
{
    setTableWidget();
    setPage();
}

void Test01::writeData(const Data& data)
{
    bool flag = false;
    if (_v.size() == ROW * NUMBER_OF_PAGES)
    {
        _v.erase(_v.begin());
        flag = true;
    }
    _v.push_back(data);
    updateView(flag);   // 更新数据
    //setPage();        // 设置显示
}


void Test01::updateView(bool flag)
{
    // 先来写数据
    if (flag)
    {
        //直接去更新所有的数据
        for (int i = 0; i < _v.size(); ++i)
        {
            ui->tableWidget->setItem(i+ ROW, 0, new QTableWidgetItem(QString::number(i + 1)));
            ui->tableWidget->setItem(i + ROW, 1, new QTableWidgetItem(_v[i]._name.c_str()));
        }
    }
    else
    {
        ui->tableWidget->setItem(ROW+_v.size()-1, 0, new QTableWidgetItem(QString::number(_v.size())));
        ui->tableWidget->setItem(ROW + _v.size() - 1, 1, new QTableWidgetItem(_v.back()._name.c_str()));
    }
    // 这里的 尾页需要更新一下
    _totalPage = _v.size() % ROW + 1;
    showPageData(_curPage);
}





void Test01::setTableWidget()
{
    ui->tableWidget->resizeRowsToContents();//调整行内容大小
    ui->tableWidget->setColumnCount(COL);//设置列数
    ui->tableWidget->setRowCount(ROW * (NUMBER_OF_PAGES+1));//设置行数
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(200);//标题头的大小
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);//横向先自适应宽度
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);//然后设置要根据内容使用宽度的列

    //设置标题头的文字
    QStringList header;
    header << tr("编号") << tr("数据");
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

void Test01::showPageData(int index)
{
    // 找一个起始位置
    int start = index * ROW;
    int end = start + ROW;
    if (end > _v.size())
        end = _v.size();
    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
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
    // 找一个结束位置
}


void Test01::setPage()
{
    ui->CurPageLable->setText(QString("第 %1 页").arg(_curPage));
    ui->TotalPageLable->setText(QString("共 %1 页").arg(_totalPage));
}

void Test01::showView(int page)
{

}

