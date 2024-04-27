#pragma once

#include <QWidget>
#include "ui_MyTime.h"
#include <iostream>
#include <qtimer.h>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// ��ָ���֧��VS����
#endif
QT_BEGIN_NAMESPACE
namespace Ui { class MyTimeClass; };
QT_END_NAMESPACE

class MyTime : public QWidget
{
	Q_OBJECT

public:
	MyTime(QWidget* parent = nullptr);
	~MyTime();
	void init();
signals:
	void myTimeCloseSignals();
	void fromMyTimeToMianScreenSignals();
private:
	void closeEvent(QCloseEvent*);
private:
	Ui::MyTimeClass* ui;
	QTimer* _timer;
};
