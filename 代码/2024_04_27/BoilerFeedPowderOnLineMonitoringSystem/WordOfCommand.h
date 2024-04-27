#pragma once

#include <QWidget>
#include "ui_WordOfCommand.h"
#include "Configure.h"
#include <iostream>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// 该指令仅支持VS环境
#endif
QT_BEGIN_NAMESPACE
namespace Ui { class WordOfCommandClass; };
QT_END_NAMESPACE

class WordOfCommand : public QWidget
{
	Q_OBJECT

public:
	WordOfCommand(QWidget* parent = nullptr, Configure* configure = nullptr);
	~WordOfCommand();
	void init();
signals:
	void fromWordOfCommandToMainScreenSignals();
	void wordOfCommandCloseSignals();
private:
	void closeEvent(QCloseEvent*);
private:
	Ui::WordOfCommandClass* ui;
	Configure* _configure;
	std::string _password;
};
