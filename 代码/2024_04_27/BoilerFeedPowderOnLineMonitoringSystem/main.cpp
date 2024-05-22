#include "BoilerFeedPowderOnLineMonitoringSystem.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	BoilerFeedPowderOnLineMonitoringSystem w; // 实例化所有功能的类
	w.hide();   // 主页面暂时先隐藏
	return a.exec();
}