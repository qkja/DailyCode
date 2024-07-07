#pragma once

#include <QWidget>
#include "ui_VerifyPassword.h"
#include <iostream>
#include "Configure.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// 该指令仅支持VS环境
#endif
QT_BEGIN_NAMESPACE
namespace Ui { class VerifyPasswordClass; };
QT_END_NAMESPACE

class VerifyPassword : public QWidget
{
	Q_OBJECT

public:
	VerifyPassword(QWidget* parent = nullptr, Configure* configure = nullptr);
	~VerifyPassword();
	void init();
	void setOption(int);
signals:
	void fromVerifyPasswordToSpoutSignalsIsTrue(); // 对面积是正确的
	void fromVerifyPasswordToBackrestCanalSignalsIsTrue(); // 对系数是正确的
	void fromVerifyPasswordSignalsIsFalse();
	void verifyPasswordCloseSignals();
private:
	void closeEvent(QCloseEvent*);
private:
	Ui::VerifyPasswordClass* ui;
	std::string _password;
	Configure* _configure;
	int _option;
};
