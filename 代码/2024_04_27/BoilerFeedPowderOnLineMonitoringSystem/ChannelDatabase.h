#pragma once

#include <QWidget>
#include "ui_ChannelDatabase.h"
#include <iostream>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// 该指令仅支持VS环境
#endif
QT_BEGIN_NAMESPACE
namespace Ui { class ChannelDatabaseClass; };
QT_END_NAMESPACE

class ChannelDatabase : public QWidget
{
	Q_OBJECT

public:
	ChannelDatabase(QWidget* parent = nullptr);
	~ChannelDatabase();
	void init();
signals:
	void channelDatabaseCloseSignals();
	void fromChannelDatabaseToMainScreenSignals();
private:
	void closeEvent(QCloseEvent*);
private:
	Ui::ChannelDatabaseClass* ui;
};
