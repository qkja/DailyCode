#pragma once

#include <QWidget>
#include "ui_wordofcommand.h"
#include <iostream>
#include "configure.h"
QT_BEGIN_NAMESPACE
namespace Ui
{
	class WordOfCommandClass;
};
QT_END_NAMESPACE

class WordOfCommand : public QWidget
{
	Q_OBJECT

public:
	WordOfCommand(QWidget* parent = nullptr, Configure* configure = nullptr);
	~WordOfCommand();
signals:
	void fromWordOfCommandToMainScreenSignals();
	void fromWordOfCommandToMainScreenToSaveSignals(std::string);
private:
	Ui::WordOfCommandClass* ui;
	Configure* _configure;
	std::string _password;
};
