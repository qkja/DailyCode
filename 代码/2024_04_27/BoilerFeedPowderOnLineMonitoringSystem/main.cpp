#include "BoilerFeedPowderOnLineMonitoringSystem.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	BoilerFeedPowderOnLineMonitoringSystem w; // ʵ�������й��ܵ���
	w.hide();   // ��ҳ����ʱ������
	return a.exec();
}