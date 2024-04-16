#pragma once

#include <QWidget>
#include "ui_welcomescreen.h"
#include <qtimer.h>
#include <iostream>
#include <qpushbutton.h>


QT_BEGIN_NAMESPACE
namespace Ui
{
	class WelcomeScreenClass;
};
QT_END_NAMESPACE

class WelcomeScreen : public QWidget
{
	Q_OBJECT

public:
	WelcomeScreen(QWidget *parent = nullptr);
	~WelcomeScreen();
protected slots:
	void onButtonDoubleClicked();
	void resetClickCount();
signals:
	void fromWelToMianScreenSignals();

private:
	Ui::WelcomeScreenClass *ui;
	QTimer *_doubleClickTimer;
	int _clickCount;
};
