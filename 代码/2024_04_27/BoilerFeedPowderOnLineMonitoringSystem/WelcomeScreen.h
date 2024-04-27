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

class WelcomeScreen : public QWidget
{
	Q_OBJECT

public:
	WelcomeScreen(QWidget* parent = nullptr);
	~WelcomeScreen();
protected slots:
	void onButtonDoubleClicked();
	void resetClickCount();
signals:
	void fromWelToMianScreenSignals();
	void welcomeScreenCloseSignals();
protected:
	void closeEvent(QCloseEvent*);

private:
	Ui::WelcomeScreenClass* ui;
	QTimer* _doubleClickTimer;
	int _clickCount;
};
