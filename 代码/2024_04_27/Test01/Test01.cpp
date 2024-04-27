#include "Test01.h"
#include <qtimer.h>
#include <iostream>
#include<ctime>
#include <Windows.h>
Test01::Test01(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::Test01Class())
	, sub(nullptr)
	,_t(new Test(nullptr))
{
	std::cout << "Test01()" << std::endl;

	ui->setupUi(this);
	connect(ui->action1, &QAction::triggered, [=]() {
		if (sub == nullptr)
		{
			//sub->close();
			sub = nullptr;
			sub = new Sub(nullptr, _t);
		}
		

		/*connect(sub, &QWidget::destroyed, [=](QObject* obj) {
			
			Q_UNUSED(obj);
			sub = nullptr;
			});*/
		//time_t nowtime;
		//time(&nowtime);
		//tm p;
		//localtime_s(&p, &nowtime);
		//printf("%04d:%02d:%02d %02d:%02d:%02d\n", p.tm_year + 1900, p.tm_mon + 1, p.tm_mday, p.tm_hour, p.tm_min, p.tm_sec);
		//
		//QTimer::singleShot(2000, sub, [=]() {
		//	_t->func();
		//
		//	});
		//time(&nowtime);
		//localtime_s(&p, &nowtime);
		//printf("%04d:%02d:%02d %02d:%02d:%02d\n", p.tm_year + 1900, p.tm_mon + 1, p.tm_mday, p.tm_hour, p.tm_min, p.tm_sec);

		//sub->show();

		_t->func();

		QTimer::singleShot(1, sub, [=]() {
			
			});


		sub->show();

		this->hide();

		connect(sub, &Sub::subClose, [=]() 
			{
				sub->hide();
				this->show();
			});
		//sub->setAttribute(Qt::WA_DeleteOnClose);
		});
}

Test01::~Test01()
{
	std::cout << "~Test01()" << std::endl;
	delete ui;
}
void Test01::closeEvent(QCloseEvent*)
{
	delete sub;
	/*if(sub)
		sub->close();*/
	this->close();
}
//void Test01::on_pushButton_clicked()
//{
//	this->hide();//��ǰ��������
//	if (sub == nullptr)
//		sub = new Sub();//�½��Ӵ���
//	connect(sub, &Sub::subClose, [=]() {
//		QWidget::show();
//		sub = nullptr;
//		});//�����Ӵ���ر��ź��븸������ʾ�¼�
//	sub->setAttribute(Qt::WA_DeleteOnClose);//�����Ӵ������ԣ��رռ�����
//	sub->show();//��ʾ�Ӵ���
//}