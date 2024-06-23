#pragma once

#include <QWidget>
#include "ui_WelcomeScreen.h"
#include <qtimer.h>
#include <iostream>
#include <qpushbutton.h>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class WelcomeScreenClass; };
QT_END_NAMESPACE
/*
* 这是一个带有ui界面的欢迎窗口,在程序启动后优先显示这个窗口
* 双击"锅炉燃烧"按钮就可以进入主页面
*/
class WelcomeScreen : public QWidget
{
	Q_OBJECT

public:
	WelcomeScreen(QWidget* parent = nullptr);
	~WelcomeScreen();
	void init();
protected slots:
	void onButtonDoubleClicked();       // 点击按钮触发的槽函数
	void resetClickCount();             // 重置计数器
signals:
	void fromWelToMianScreenSignals();  // 双击之后,触发这个信号,转到主界面
	void welcomeScreenCloseSignals();   // 窗口关闭时,触发这个函数
protected:
	void closeEvent(QCloseEvent*);      // 重写窗口关闭的函数

private:
	Ui::WelcomeScreenClass* ui;
	QTimer* _doubleClickTimer;          // 定时器对象
	volatile int _clickCount;           // 点击的计数器,volatile关键字,让去内存中取值
};
