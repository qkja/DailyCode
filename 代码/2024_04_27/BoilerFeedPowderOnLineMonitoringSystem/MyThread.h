#pragma once

#include <QThread>
#include <iostream>
#include "Task.h"
#include <iostream>
#include <fstream>
class MyThread : public QThread
{
	Q_OBJECT

public:
	MyThread(QObject* parent = nullptr);
	~MyThread();
	void init();
	void run() override;
	void quitThread();
signals:
	void saveCoefficientSignals(const std::vector<std::string>);   // �õ�ϵ��
	void produceDataSignals(Task);
private:
	void parse(Task*, const std::string&);
	void slicedString(std::vector<std::string>*, const std::string&);// �з��ַ���
private:
	volatile bool _quit_flag;
	std::vector<double> _area;                          // �������
	std::vector<double> _coefficient_of_backrest_tube;  // ���濿����ϵ��
};
