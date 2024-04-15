#pragma once

#include <QWidget>
#include "ui_wordofcommand.h"
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui
{
	class WordOfCommandClass;
};
QT_END_NAMESPACE
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
class WordOfCommand : public QWidget
{
	Q_OBJECT

public:
	WordOfCommand(QWidget *parent = nullptr);
	~WordOfCommand();
signals:
	void fromWordOfCommandToMainScreenSignals();

private:
	Ui::WordOfCommandClass *ui;
};
