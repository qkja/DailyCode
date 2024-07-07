#pragma once

#include <QWidget>
#include "ui_GiveAnAlarm.h"
#include <iostream>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
QT_BEGIN_NAMESPACE
namespace Ui { class GiveAnAlarmClass; };
QT_END_NAMESPACE

class GiveAnAlarm : public QWidget
{
	Q_OBJECT

public:
	GiveAnAlarm(QWidget *parent = nullptr);
	~GiveAnAlarm();

private:
	Ui::GiveAnAlarmClass *ui;
};
