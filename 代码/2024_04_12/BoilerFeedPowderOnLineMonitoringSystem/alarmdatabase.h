#pragma once

#include "ui_alarmdatabase.h"
#include <iostream>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui
{
	class AlarmDatabaseClass;
};
QT_END_NAMESPACE

class AlarmDatabase : public QWidget
{
	Q_OBJECT

public:
	AlarmDatabase(QWidget* parent = nullptr);
	~AlarmDatabase();
signals:
	void fromAlarmDatabaseToMainScreenSignals();

private:
	Ui::AlarmDatabaseClass* ui;
};
