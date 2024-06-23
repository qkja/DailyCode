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
    updateView(flag);   // ��������
    //setPage();        // ������ʾ
}


void Test01::updateView(bool flag)
{
    // ����д����
    if (flag)
    {
        //ֱ��ȥ�������е�����
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
    // ����� βҳ��Ҫ����һ��
    _totalPage = _v.size() % ROW + 1;
    showPageData(_curPage);
}





void Test01::setTableWidget()
{
    ui->tableWidget->resizeRowsToContents();//���������ݴ�С
    ui->tableWidget->setColumnCount(COL);//��������
    ui->tableWidget->setRowCount(ROW * (NUMBER_OF_PAGES+1));//��������
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(200);//����ͷ�Ĵ�С
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);//����������Ӧ���
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);//Ȼ������Ҫ��������ʹ�ÿ�ȵ���

    //���ñ���ͷ������
    QStringList header;
    header << tr("���") << tr("����");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->verticalHeader()->setVisible(false); //�����к���,trueΪ��ʾ
    ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection); //�ɶ�ѡ��Ctrl��Shift�� Ctrl+A�����ԣ�
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //����ѡ����Ϊʱÿ��ѡ��һ��
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //���ò��ɱ༭
   
    //����ˮƽ����ֱ��������ʽ
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

    ui->tableWidget->clearContents();//���������������������ݣ����ǲ������ͷ
}

void Test01::showPageData(int index)
{
    // ��һ����ʼλ��
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
    // ��һ������λ��
}


void Test01::setPage()
{
    ui->CurPageLable->setText(QString("�� %1 ҳ").arg(_curPage));
    ui->TotalPageLable->setText(QString("�� %1 ҳ").arg(_totalPage));
}

void Test01::showView(int page)
{

}

