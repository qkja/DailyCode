#pragma once

#include <QWidget>
#include "ui_welcomescreen.h"
#include <iostream>
#include <qtimer.h>

QT_BEGIN_NAMESPACE
namespace Ui { class WelcomeScreenClass; };
QT_END_NAMESPACE

class WelcomeScreen : public QWidget
{
	Q_OBJECT

public:
	WelcomeScreen(QWidget *parent = nullptr);
	~WelcomeScreen();
protected slots:
	void onButtonDoubleClicked();  
	void resetClickCount();  // 重置计数器
	void fromWelToMianScreen(); // 去主页面
private:
	Ui::WelcomeScreenClass *ui;
	QTimer* _doubleClickTimer;
	int _clickCount;
};
